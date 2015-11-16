//
//  HyUIButton.m
//
//  Created by HyanCat on 15/9/28.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "HyUIButton.h"
#import "RGCache.h"

@implementation HyUIButton

- (void)setEventName:(NSString *)eventName
{
	if ([NSObject equalToObject1:_eventName andObject2:eventName]) {
		return;
	}
	_eventName = eventName;
	if (_eventName == nil) {
		[self removeTarget:self action:@selector(buttonTouched:) forControlEvents:UIControlEventTouchUpInside];
	}
	else {
		[self addTarget:self action:@selector(buttonTouched:) forControlEvents:UIControlEventTouchUpInside];
	}
}

- (void)setHighlightBackgroundColor:(UIColor *)highlightBackgroundColor
{
	if ([NSObject equalToObject1:_highlightBackgroundColor andObject2:highlightBackgroundColor]) {
		return;
	}
	_highlightBackgroundColor = highlightBackgroundColor;
}

- (void)setCornerRadius:(CGFloat)cornerRadius
{
	if (_cornerRadius == cornerRadius) {
		return;
	}
	_cornerRadius = cornerRadius;
}

- (void)setNeedsUpdateButtonResource
{
	[self _updateButtonResource];
}

- (void)buttonTouched:(id)sender
{
	[self dispatchHyUIActionEvent:[HyUIActionEvent eventWithName:self.eventName object:self userInfo:self.eventUserInfo]];
}

- (void)_updateButtonResource
{
	UIImage *backgroundImage = [[RGCache sharedImageCache] cachedImageWithColor:self.backgroundColor size:CGSizeMake(1, 1)];
	[self setBackgroundImage:backgroundImage forState:UIControlStateNormal];
	
	UIImage *highlightBackgroundImage = [[RGCache sharedImageCache] cachedImageWithColor:self.highlightBackgroundColor size:CGSizeMake(1, 1)];
	[self setBackgroundImage:highlightBackgroundImage forState:UIControlStateHighlighted];
}

@end
