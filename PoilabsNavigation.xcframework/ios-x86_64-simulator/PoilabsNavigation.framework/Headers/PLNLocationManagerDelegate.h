//
//  PLNLocationManagerDelegate.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLPoi.h"
#import "PESGraphNode.h"
#import <CoreLocation/CoreLocation.h>

@protocol PLNLocationManagerDelegate  <NSObject>


@optional

-(void)compassAngleChanged:(float)angle;

-(void)navigationLocationManagerStatusChanged;

-(void)locationManagerDidUpdateLocationCoordinate:(PLPoi *)poi;


@end
