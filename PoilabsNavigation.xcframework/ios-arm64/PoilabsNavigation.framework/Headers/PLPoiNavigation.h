//
//  PLPoiNavigation.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLPoiNavigation : NSObject

-(id)initWithData:(NSDictionary*)data forPoiId:(NSString *)poiId;

@property(strong, nonatomic) NSMutableArray *segments;

@property(assign, nonatomic) BOOL isVisibleOnList;

@property(assign, nonatomic) BOOL isVisibleOnMap;

@property(assign, nonatomic) BOOL routePrivilage;


@end
