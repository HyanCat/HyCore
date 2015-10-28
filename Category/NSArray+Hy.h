//
//  NSArray+Hy.h
//
//  Created by HyanCat on 15/9/28.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Hy)

- (id)objectAtPosition:(NSUInteger)position;

- (id)objectAtCirclePosition:(NSInteger)position;

@end

BOOL HyArrayIsEmpty(NSArray *array);