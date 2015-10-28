//
//  UIImage+Hy.h
//
//  Created by HyanCat on 15/9/28.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Hy)

+ (UIImage *)imageWithSize:(CGSize)size
		   backgroundColor:(UIColor *)backgroundColor;

+ (UIImage *)imageWithSize:(CGSize)size
			  cornerRadius:(CGFloat)cornerRadius
		   backgroundColor:(UIColor *)backgroundColor;

+ (UIImage *)imageWithSize:(CGSize)size
			   borderWidth:(CGFloat)borderWidth
			   borderColor:(UIColor *)borderColor
		   backgroundColor:(UIColor *)backgroundColor;

+ (UIImage *)imageWithSize:(CGSize)size
			  cornerRadius:(CGFloat)cornerRadius
			   borderWidth:(CGFloat)borderWidth
			   borderColor:(UIColor *)borderColor
		   backgroundColor:(UIColor *)backgroundColor;

+ (UIImage *)imageWithSize:(CGSize)size
			  cornerRadius:(CGFloat)cornerRadius
			   borderWidth:(CGFloat)borderWidth
			   borderColor:(UIColor *)borderColor
		  backgroundColors:(NSArray *)backgroundColors;

/*
 等比例缩放图片，尺寸调整为 size*size 范围
 有单边超过 size 的，缩小为 size
 宽高都小于 size 的，较长的一边放大至 size
 size 为 point
 */
- (UIImage *)zoomToFitSize:(CGFloat)size;

// 等比缩小后,裁剪到指定大小
- (UIImage *)scaleAndClipToFillSize:(CGSize)destSize;

/*
 * 等比例缩小
 * size 为 point
 */
- (UIImage *)shrinkToSize:(CGFloat)size;
/*
 * 等比例放大
 * size 为 point
 */
- (UIImage *)magnifyToSize:(CGFloat)size;

- (UIImage *)imageWithSize:(CGSize)size;
- (UIImage *)imageWithSize:(CGSize)size cornerRadius:(CGFloat)cornerRadius;
- (UIImage *)imageWithSize:(CGSize)size cornerRadius:(CGFloat)cornerRadius borderWidth:(CGFloat)borderWidth;
- (UIImage *)imageWithSize:(CGSize)size cornerRadius:(CGFloat)cornerRadius borderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor;

/**
 * 灰度图
 */
- (UIImage *) grayImage;
- (UIImage *) blurImage;

@end

UIImage *HyUIImage(NSString *imageName);