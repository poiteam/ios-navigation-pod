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
#import "PLNFacility.h"
#import "PLNCategory.h"
#import "PLSegment.h"


@interface PLPoi : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *poiId;

@property(strong, nonatomic) NSString *title;

@property(strong, nonatomic) NSString *rotationTitle; // use for Bar rotation informations

@property(strong, nonatomic) PLLocation *location;

@property(strong, nonatomic) PLFilter *filters;

@property(strong, nonatomic) PLMap *map;


@property(strong, nonatomic) NSMutableArray<PLNFacility *> *facilities;

@property(strong, nonatomic) NSString *restrictionWarning;

@property(strong, nonatomic) PLNCategory *category;

@property(strong, nonatomic) NSArray<NSString *> *tags;

//It can be floorname or floorlabel. Depend on its value, on floor change slider, show floor level or floor name for elevator cases
@property(strong, nonatomic) NSString *routeSummaryParameter;

-(NSString *)getTitleForCategoryOrSubcategory;

- (BOOL)containsKeyword:(NSString *)str;

-(CLLocationCoordinate2D)getCoordinates;
-(int)getSegmentsCount;
-(bool)hasSegment;

@property(assign, readonly) bool isVisibleOnMap;
@property(assign, readonly) bool isVisibleOnList;
@property(strong, nonatomic) NSArray<PLSegment *> *segments;

@end
