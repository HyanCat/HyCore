//
//  HyEXTBlock.h
//
//  Created by HyanCat on 15/9/25.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 分页结果
 */
@protocol HyEXTPageableResult <NSObject>

@property (nonatomic, assign, readonly) NSUInteger total;	// 总数
@property (nonatomic, assign, readonly) NSUInteger page;	// 当前页数
@property (nonatomic, assign, readonly) NSUInteger count;	// 请求结果数（实际数目以 list.count 为准）
@property (nonatomic, copy, readonly) NSArray *list;		// 数据列表

@end

/**
 * 请求对象数据结果
 */
@protocol HyEXTObjectDataResult <NSObject>

@property (nonatomic, copy, readonly) NSData *data;		// 请求的对象数据
@property (nonatomic, copy, readonly) NSURL *remoteUrl;	// 请求的对象远程 url
@property (nonatomic, copy, readonly) NSURL *localUrl;	// 请求的对象本地 url

@end

/**
 * 请求对象数据结果
 */
@protocol HyEXTImageResult <NSObject>

@property (nonatomic, copy, readonly) UIImage *image;	// 请求的图片
@property (nonatomic, copy, readonly) NSURL *remoteUrl;	// 请求的图片远程 url

@end

// 无参数无返回值 Block
typedef void(^HyEXTVoidBlock)();

// 通用数据回调
typedef void(^HyEXTDataResultCallback)(id data, NSError *error);

// 通用结果回调
typedef void(^HyEXTResultCallback)(NSError *error);

// 分页数据回调
typedef void(^HyEXTPagebaleResultCallback)(id <HyEXTPageableResult> data, NSError *error);

// 列表数组数据回调
typedef void(^HyEXTListResultCallback)(NSArray *listData, NSError *error);

// NSData 数据回调
typedef void(^HyEXTObjectDataResultCallback)(id <HyEXTObjectDataResult> data, NSError *error);

// UIImage 数据回调
typedef void(^HyEXTImageResultCallback)(id <HyEXTImageResult> data, NSError *error);


@interface HyEXTPageableResult : NSObject <HyEXTPageableResult>

@property (nonatomic, assign, readwrite) NSUInteger total;	// 总数
@property (nonatomic, assign, readwrite) NSUInteger page;	// 当前页数
@property (nonatomic, assign, readwrite) NSUInteger count;	// 请求结果数（实际数目以 list.count 为准）
@property (nonatomic, copy, readwrite) NSArray *list;		// 数据列表

@end

@interface HyEXTObjectDataResult : NSObject <HyEXTObjectDataResult>

@property (nonatomic, copy, readwrite) NSData *data;		// 请求的对象数据
@property (nonatomic, copy, readwrite) NSURL *remoteUrl;	// 请求的对象远程 url
@property (nonatomic, copy, readwrite) NSURL *localUrl;		// 请求的对象本地 url

@end

@interface HyEXTImageResult : NSObject <HyEXTImageResult>

@property (nonatomic, copy, readwrite) UIImage *image;		// 请求的图片
@property (nonatomic, copy, readwrite) NSURL *remoteUrl;	// 请求的图片远程 url

@end
