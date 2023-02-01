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

-(void)didUserLocationChange:(CLLocationCoordinate2D)coordinate;

@end
