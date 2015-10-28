//
//  NSString+Hy.m
//
//  Created by HyanCat on 15/10/17.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import "NSString+Hy.h"

@implementation NSString (Hy)

- (NSString *)repeat
{
	NSMutableString * copy = [self mutableCopy];
	[copy appendString:self];
	
	return [copy copy];
}

- (NSUInteger)hexStringToNum
{
	unsigned int num = 0;
	[[NSScanner scannerWithString:self] scanHexInt:&num];
	
	return (NSUInteger)num;
}

+ (NSString *)bundleFileContent:(NSString *)fileName
{
	return [self bundleFileContent:fileName failure:nil];
}

+ (NSString *)bundleFileContent:(NSString *)fileName failure:(HyEXTResultCallback)failure
{
	NSError *error = nil;
	NSString *content = [NSString stringWithContentsOfFile:[[NSBundle mainBundle] pathForResource:fileName ofType:@""] encoding:NSUTF8StringEncoding error:&error];
	if (error && failure) {
		failure(error);
	}
	return content;
}

@end

BOOL HyStringIsNil(NSString *string)
{
	return nil == string || [string isEqual:[NSNull null]] || ![string isKindOfClass:[NSString class]];
}

BOOL HyStringIsNotNil(NSString *string)
{
	return ! HyStringIsNil(string);
}

NSString *HySafeString(NSString *string)
{
	return HyStringIsNil(string) ? @"" : string;
}
