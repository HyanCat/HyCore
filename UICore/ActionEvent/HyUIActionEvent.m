//
//  HyUIActionEvent.m
//
//  Created by HyanCat on 15/9/27.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "HyUIActionEvent.h"

@interface HyUIActionEvent ()

@property (nonatomic, copy, readwrite) NSString *eventName;
@property (nonatomic, strong, readwrite) id eventObject;
@property (nonatomic, copy, readwrite) NSDictionary *userInfo;

@end

@implementation HyUIActionEvent

+ (instancetype)eventWithName:(NSString *)name
{
	return [[self alloc] initWithName:name object:nil userInfo:nil];
}

+ (instancetype)eventWithName:(NSString *)name object:(id)object
{
	return [[self alloc] initWithName:name object:object userInfo:nil];
}

+ (instancetype)eventWithName:(NSString *)name object:(id)object userInfo:(NSDictionary *)userInfo
{
	return [[self alloc] initWithName:name object:object userInfo:userInfo];
}

- (instancetype)initWithName:(NSString *)name object:(id)object userInfo:(NSDictionary *)userInfo
{
	self = [super init];
	if (self) {
		_eventName = name;
		_eventObject = object;
		_userInfo = userInfo;
	}
	return self;
}

@end
