//
//  NSArray+Hy.m
//
//  Created by HyanCat on 15/9/28.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "NSArray+Hy.h"

@implementation NSArray (Hy)

- (id)objectAtPosition:(NSUInteger)position
{
	NSUInteger count = self.count;
	if (position < count) {
		return [self objectAtIndex:position];
	}
	return nil;
}

- (id)objectAtCirclePosition:(NSInteger)position
{
	NSUInteger count = self.count;
	if (count <= 1) {
		return [self firstObject];
	}

	while (position < 0) {
		position += count;
	}
	position = position % count;

	return [self objectAtPosition:position];
}

@end


BOOL HyArrayIsEmpty(NSArray *array)
{
	return array == nil || [array isEqual:[NSNull null]] || array.count == 0;
}

BOOL HyArrayIsNotEmpty(NSArray *array)
{
	return !HyArrayIsEmpty(array);
}
