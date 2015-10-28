//
//  NSDate+Hy.m
//
//  Created by HyanCat on 15/10/6.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "NSDate+Hy.h"

@implementation NSDate (Hy)

+ (NSDate *)dateFromSqlTimestamp:(NSString *)timestamp
{
	if (HyStringIsNil(timestamp)) {
		return nil;
	}
	return [NSDate dateWithString:timestamp formatString:@"YYYY-MM-dd HH:mm:ss"];
}

@end
