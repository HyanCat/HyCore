//
//  UIResponder+HyUIActionEvent.h
//
//  Created by HyanCat on 15/9/27.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HyUIActionEvent;
@interface UIResponder (HyUIActionEvent)

/**
 * 分发界面事件
 *
 * 想要处理该事件的对象，需要实现形如：
 *  - (HyUIActionEventHandleResult *)handle%@WithActionEvent:(HyUIActionEvent *)actionEvent;
 *
 * %@ 为事件名，首字母将自动转为大写
 * 返回对象为 nil, 或者返回对象的 continueDispatch 属性为 NO 时，表示该事件处理结束，不再传递该事件
 */
- (void)dispatchHyUIActionEvent:(HyUIActionEvent *)actionEvent;
- (void)dispatchHyUIActionEvent:(HyUIActionEvent *)actionEvent inMainThead:(BOOL)inMainThead;

@end
