//
//  HyUIActionEvent.h
//
//  Created by HyanCat on 15/9/27.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HyUIActionEvent : NSObject

+ (instancetype)eventWithName:(NSString *)name;
+ (instancetype)eventWithName:(NSString *)name object:(id)object;
+ (instancetype)eventWithName:(NSString *)name object:(id)object userInfo:(NSDictionary *)userInfo;

@property (nonatomic, copy, readonly) NSString *eventName;
@property (nonatomic, strong, readonly) id eventObject;
@property (nonatomic, copy, readonly) NSDictionary *userInfo;

@end
