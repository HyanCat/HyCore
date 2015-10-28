//
//  HyUIActionEventResult.h
//
//  Created by HyanCat on 15/9/27.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HyUIActionEventResult : NSObject

@property (nonatomic, assign, readonly) BOOL shouldContinueDispatching;

+ (instancetype)resultWithContinueDispatching:(BOOL)shouldContinueDispatching;

@end
