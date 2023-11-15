//
//  PLNNavigationMapViewDelegate.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 15/05/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLLocationStatus.h"

@protocol PLNNavigationMapViewDelegate  <NSObject>


@optional

-(void)childsAreReady;

-(void)routeIsRequestedFrom:(NSString *)storeId;

-(void)didLocationStatusChange:(PLLocationStatus) status;

-(void)didUserLocationChange:(CLLocationCoordinate2D)coordinate __deprecated_msg("Use didUserLocationChange:floorLevel: instead.");

-(void)didUserLocationChange:(CLLocationCoordinate2D)coordinate floorLevel:(NSInteger)floorLevel;

-(void)didUserLocationChange:(CLLocationCoordinate2D)coordinate floorLevel:(NSInteger)floorLevel floorName:(nonnull NSString*)floorName;

-(void)poilabsNavigationReadyForRouting;

- (void)didLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate floorLevel:(NSInteger)floorLevel;

-(void)didUserVisitPointWithStoreIds:(NSArray<NSString *> *_Nonnull)storeIds;

@end
