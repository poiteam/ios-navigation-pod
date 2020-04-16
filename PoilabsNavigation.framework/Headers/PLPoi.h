//
//  PLPoi.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/19/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "PLLocation.h"
#import "PLFilter.h"
#import "PLMap.h"
#import "PLPoiNavigation.h"


@interface PLPoi : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *poiId;

@property(strong, nonatomic) NSString *title;

@property(strong, nonatomic) NSString *rotationTitle; // use for Bar rotation informations

@property(strong, nonatomic) NSString *poiDescription;

//@property(strong, nonatomic) NSString *type;

//@property(strong, nonatomic) NSMutableArray *parents; // poi ids

@property(strong, nonatomic) PLLocation *location;

@property(strong, nonatomic) PLFilter *filters;

@property(strong, nonatomic) PLMap *map;

@property(strong, nonatomic) PLPoiNavigation *navigation;




@end
