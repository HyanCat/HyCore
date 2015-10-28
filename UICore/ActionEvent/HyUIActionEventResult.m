//
//  HyUIActionEventResult.m
//
//  Created by HyanCat on 15/9/27.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "HyUIActionEventResult.h"

@interface HyUIActionEventResult ()

@property (nonatomic, assign, readwrite) BOOL shouldContinueDispatching;

@end

@implementation HyUIActionEventResult

+ (instancetype)resultWithContinueDispatching:(BOOL)shouldContinueDispatching
{
	HyUIActionEventResult *result = [[self alloc] init];
	result.shouldContinueDispatching = shouldContinueDispatching;

	return result;
}

@end
