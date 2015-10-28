//
//  UIView+Hy.h
//
//  Created by HyanCat on 15/9/24.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (HyBase)

#pragma mark Getter

- (CGFloat)x;
- (CGFloat)y;
- (CGFloat)width;
- (CGFloat)height;
- (CGPoint)origin;
- (CGSize)size;
- (CGFloat)minX;
- (CGFloat)minY;
- (CGFloat)maxX;
- (CGFloat)maxY;
- (CGPoint)innerCenter;

#pragma mark Setter

- (void)setX:(CGFloat)x;
- (void)setY:(CGFloat)y;
- (void)setWidth:(CGFloat)width;
- (void)setHeight:(CGFloat)height;
- (void)setOrigin:(CGPoint)origin;
- (void)setSize:(CGSize)size;
- (void)setOriginZero;
- (void)setSizeZero;
- (void)frameAddPoint:(CGPoint)point;
- (void)frameAddSize:(CGSize)size;

#pragma mark Operator

- (void)addSubviewToFill:(UIView *)subview;
- (void)insertSubviewToFill:(UIView *)subview atIndex:(NSInteger)index;
- (void)insertSubviewToFill:(UIView *)subview aboveSubview:(UIView *)abovedSubview;
- (void)insertSubviewToFill:(UIView *)subview belowSubview:(UIView *)belowedSubview;

- (void)removeAllSubviewsWhichKindOfClass:(Class)viewClass;
- (void)removeFromSuperviewIfSelfIsKindOfClass:(Class)viewClass;
- (void)removeFromSuperviewIfExist;

// Find superview which is kind of class.
- (UIView *)superviewWhichKindOfClass:(Class)viewClass;
// Get subviews which are kind of class.
- (NSArray *)subviewsWhichKindOfClass:(Class)viewClass;
// Get subviews which are member of class.
- (NSArray *)subviewsWhichMemberOfClass:(Class)viewClass;

@end

@interface UIView (HyLayout)

- (CGSize)systemLayoutSizeWithPreferredMaxLayoutWidth:(CGFloat)preferedWidth;

@end

@interface UIView (HySnapshot)

// Make a snapshot image which is opaque.
- (UIImage *)snapshot;
// Make a snapshot image with determining whether it is opaque.
- (UIImage *)snapshot:(BOOL)opaque;

// Make a snapshot image view which is opaque.
- (UIView *)snapshotView;
// Make a snapshot image view with determining whether it is opaque.
- (UIView *)snapshotView:(BOOL)opaque;

@end
