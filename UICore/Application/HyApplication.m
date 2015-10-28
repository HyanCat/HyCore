//
//  HyApplication.m
//
//  Created by HyanCat on 15/9/24.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "HyApplication.h"
#import "HyBaseViewController.h"
#import "UIGestureRecognizer+Hy.h"

NSString * const kStatusBarWindow = @"UIStatusBarWindow";
NSString * const kStatusBarForegroundView = @"UIStatusBarForegroundView";

@implementation HyApplication

- (void)sendEvent:(UIEvent *)event
{
	if (UIEventTypeTouches == event.type) {

		UITouch * statusBarTouch = nil;
		
		for (UITouch * touch in [event allTouches]) {
			if ([touch.window isKindOfClass:NSClassFromString(kStatusBarWindow)] && [touch.view isKindOfClass:NSClassFromString(kStatusBarForegroundView)]) {
				statusBarTouch = touch;
				break;
			}
		}
		
		if (statusBarTouch && UITouchPhaseEnded == statusBarTouch.phase) {
			HyBaseViewController *rootViewController = (HyBaseViewController *)[[[self delegate] window] rootViewController];
			if ([rootViewController respondsToSelector:@selector(handleStatusBarTouched:)]) {
				[rootViewController handleStatusBarTouched:statusBarTouch];
			}
		}
	}
	
	[super sendEvent:event];
}

@end
