//
//  HyUIButton.h
//
//  Created by HyanCat on 15/9/28.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HyUIButton : UIButton

@property (nonatomic, copy) NSString *eventName;
@property (nonatomic, copy) NSDictionary *eventUserInfo;

@property (nonatomic, strong) UIColor *highlightBackgroundColor;

@property (nonatomic, assign) CGFloat cornerRadius;

- (void)setNeedsUpdateButtonResource;

@end
