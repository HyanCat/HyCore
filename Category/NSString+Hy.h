//
//  NSString+Hy.h
//
//  Created by HyanCat on 15/10/17.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Hy)

- (NSString *)repeat;

- (NSUInteger)hexStringToNum;

+ (NSString *)bundleFileContent:(NSString *)fileName;
+ (NSString *)bundleFileContent:(NSString *)fileName failure:(HyEXTResultCallback)failure;

@end

BOOL HyStringIsNil(NSString *string);
BOOL HyStringIsNotNil(NSString *string);
NSString *HySafeString(NSString *string);