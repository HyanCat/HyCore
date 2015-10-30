//
//  HyImageItem.m
//  ruogu
//
//  Created by HyanCat on 15/10/29.
//  Copyright © 2015年 ruogu. All rights reserved.
//

#import "HyImageItem.h"
#import <AssetsLibrary/AssetsLibrary.h>

@implementation HyImageItem
@synthesize image;
@synthesize thumbnail;
@synthesize imageUrl;

- (BOOL)loadImage
{
	if (HyStringIsNil(self.imageUrl.absoluteString)) {
		return NO;
	}
	
	if ([FCFileManager isReadableItemAtPath:self.imageUrl.absoluteString]) {
		self.image = [UIImage imageWithContentsOfFile:self.imageUrl.absoluteString];
	}
	
	return !!self.image;
}

@end

@implementation HyImageAssetItem
@synthesize asset = _asset;

- (instancetype)initWithAsset:(ALAsset *)asset
{
	self = [super init];
	if (self) {
		_asset = asset;
		self.imageUrl = asset.defaultRepresentation.url;
		self.thumbnail = [UIImage imageWithCGImage:asset.thumbnail];
	}
	return self;
}

@end

@implementation HyImageRemoteItem
@synthesize remoteUrl;
@synthesize asset = _asset;

- (instancetype)initWithAsset:(ALAsset *)asset
{
	self = [super init];
	if (self) {
		_asset = asset;
		self.imageUrl = asset.defaultRepresentation.url;
		self.thumbnail = [UIImage imageWithCGImage:asset.thumbnail];
	}
	return self;
}
@end
