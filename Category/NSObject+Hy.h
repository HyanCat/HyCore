//
//  NSObject+Hy.h
//
//  Created by HyanCat on 15/9/25.
//  Copyright © 2015年 HyanCat. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Hy)

+ (BOOL)equalToObject1:(id)object1 andObject2:(id)object2;

- (instancetype)mapValueFormObject:(NSObject *)object withMap:(NSDictionary *)map;

- (instancetype)mapCoreDataPropertiesFromObject:(NSDictionary *)object withMap:(NSDictionary *)map;

+ (instancetype)invokeClass:(Class)className selector:(SEL)selector arguments:(NSArray *)arguments;

- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)object;

@end


@protocol HyObjectSingleton <NSObject>

+ (instancetype)sharedHyInstance;
+ (void)freeSharedHyInstance;

@end

@interface NSObject (HyObjectSingleton) <HyObjectSingleton>

@end