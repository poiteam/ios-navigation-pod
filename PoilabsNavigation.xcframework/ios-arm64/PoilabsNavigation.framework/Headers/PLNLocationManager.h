//
//  PLNLocationManager.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "PoilabsCommon/PoilabsCommon-Swift.h"


@interface PLNLocationManager : NSObject

+ (instancetype)sharedInstance;
+ (void)destroySharedInstance;

@property(strong, nonatomic) PLPoi *userLocationPoi;

@property(assign, nonatomic) CLLocationCoordinate2D userLocationCoordinate;

@end
