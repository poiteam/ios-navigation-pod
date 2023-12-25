//
//  PLNPlace.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 10.03.2023.
//  Copyright © 2023 poilabs. All rights reserved.
//
#import "PLMap.h"
#import "PLNFacility.h"
#import "PLNPositioning.h"

#ifndef PLNPlace_h
#define PLNPlace_h


@interface PLNPlace : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) PLMap *map;

@property(strong, nonatomic) NSMutableArray<PLNFacility *> *facilities;

//It can be floorname or floorlabel. Depend on its value, on floor change slider, show floor level or floor name for elevator cases
@property(strong, nonatomic) NSString *routeSummaryParameter;

@property(assign, nonatomic) double weinbergConstant;

@property(strong, nonatomic) NSDictionary<NSString*, NSArray*> *zonePassList;

-(BOOL)isZoneReachableFromZone:(NSString *)startZone toZone:(NSString *)endZone;

@property(strong, nonatomic) PLNPositioning *positioning;

@property(strong, nonatomic) NSArray<NSString *> *routePointTypes;

@end

#endif /* PLNPlace_h */
