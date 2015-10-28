//
//  UIResponder+HyUIActionEvent.m
//
//  Created by HyanCat on 15/9/27.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "UIResponder+HyUIActionEvent.h"
#import "HyFoundationCore.h"
#import "HyUIActionEvent.h"
#import "HyUIActionEventResult.h"
#import <objc/message.h>

static dispatch_queue_t dispatchUIEventQueue;

const char *dispatchUIEventQueueName = "HyUIActionEventDispatchQueue";

@implementation UIResponder (HyUIActionEvent)

- (void)dispatchHyUIActionEvent:(HyUIActionEvent *)actionEvent
{
	[self dispatchHyUIActionEvent:actionEvent inMainThead:YES];
}

- (void)dispatchHyUIActionEvent:(HyUIActionEvent *)actionEvent inMainThead:(BOOL)inMainThead
{
	if (inMainThead) {
		if ([NSThread isMainThread]) {
			[self _dispatchHyUIActionEvent:actionEvent];
		}
		else {
			dispatch_async(dispatch_get_main_queue(), ^{
				[self _dispatchHyUIActionEvent:actionEvent];
			});
		}
	}
	else {
		weakify(self);
		dispatch_async([self _dispatchQueue], ^{
			strongify(self);
			[self _dispatchHyUIActionEvent:actionEvent];
		});
	}
}

- (void)_dispatchHyUIActionEvent:(HyUIActionEvent *)actionEvent
{
	NSString * name = [[[actionEvent.eventName substringToIndex:1] uppercaseString] stringByAppendingString:[actionEvent.eventName substringFromIndex:1]];
	NSString * actionSelectorName = [NSString stringWithFormat:@"handle%@WithActionEvent:", name];
	SEL selector = NSSelectorFromString(actionSelectorName);
	if ([self respondsToSelector:selector]) {
		HyUIActionEventResult * result = nil;
		HyUIActionEventResult * (*action)(id, SEL, HyUIActionEvent *) = (HyUIActionEventResult *(*)(id, SEL, HyUIActionEvent *)) objc_msgSend;
		action(self, selector, actionEvent);
		if (result == nil || ![result isKindOfClass:[HyUIActionEventResult class]] || result.shouldContinueDispatching == NO) {
			// 结束 event
			return ;
		}
	}
	
	UIResponder * next = [self nextResponder];
	if (next == nil && [self isKindOfClass:[UIViewController class]]) {
		next = [(UIViewController *)self parentViewController];
	}
	if (next) {
		[next dispatchHyUIActionEvent:actionEvent inMainThead:[NSThread isMainThread]];
	}
	else {
		NSLog(@"分发 HyUIActionEvent 事件失败，没有找到实现 %@ 的对象", actionSelectorName);
	}
}

- (dispatch_queue_t)_dispatchQueue
{
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		dispatchUIEventQueue = dispatch_queue_create(dispatchUIEventQueueName, DISPATCH_QUEUE_SERIAL);
	});
	return dispatchUIEventQueue;
}

@end
