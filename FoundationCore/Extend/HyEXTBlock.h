//
//  HyEXTBlock.h
//
//  Created by HyanCat on 15/9/25.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HyEXTBlock : NSObject

@end

/**
 * 分页结果
 */
@protocol HyEXTPageableResult <NSObject>

@property (nonatomic, assign, readonly) NSUInteger total;	// 总数
@property (nonatomic, assign, readonly) NSUInteger page;		// 当前页数
@property (nonatomic, assign, readonly) NSUInteger count;	// 请求结果数（实际数目以 list.count 为准）
@property (nonatomic, copy, readonly) NSArray *list;			// 数据列表

@end

@interface HyEXTPageableResult : NSObject <HyEXTPageableResult>

@property (nonatomic, assign, readwrite) NSUInteger total;	// 总数
@property (nonatomic, assign, readwrite) NSUInteger page;	// 当前页数
@property (nonatomic, assign, readwrite) NSUInteger count;	// 请求结果数（实际数目以 list.count 为准）
@property (nonatomic, copy, readwrite) NSArray *list;		// 数据列表

@end

// 无参数无返回值 Block
typedef void(^HyEXTVoidBlock)();

// 通用数据回调
typedef void(^HyEXTDataResultCallback)(id data, NSError *error);

// 通用结果回调
typedef void(^HyEXTResultCallback)(NSError *error);

// 分页数据回调
typedef void(^HyEXTPagebaleResultCallback)(id <HyEXTPageableResult> data, NSError *error);

typedef void(^HyEXTListResultCallback)(NSArray *listData, NSError *error);

