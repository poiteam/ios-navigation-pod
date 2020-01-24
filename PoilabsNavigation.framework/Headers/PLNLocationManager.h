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
#import "PLNLocationManagerDelegate.h"


@interface PLNLocationManager : NSObject<CLLocationManagerDelegate,CBCentralManagerDelegate>

+ (instancetype)sharedInstance;

@property(strong,nonatomic) CLLocationManager *coreLocationManager;

@property(strong, nonatomic) CLBeaconRegion *coreBeaconRegion;

@property(strong, nonatomic) CBCentralManager *coreCentralManager;

@property(strong, nonatomic) id<PLNLocationManagerDelegate> delegate;

@property(strong, nonatomic) NSDate *lastBeaconRequestDate;

@property(strong,nonatomic) NSMutableArray *foundedBeaconsInPeriod;

@property(assign, nonatomic) NSInteger decideUnavailableLocation;

@property(assign, nonatomic) BOOL bluetoothStatus;

@property(assign, nonatomic) BOOL locationManagerFailed;

@property(assign, nonatomic) BOOL locationServicesStatus;

@property(strong, nonatomic) PLPoi *userLocationPoi;

@property(strong, nonatomic) NSMutableArray *poiIdsArray;

@property(strong, nonatomic) PESGraphNode *userLocationNode;

@property(assign, nonatomic) CLLocationCoordinate2D userLocationCoordinate;

-(void)startMonitoring;

-(void)closeNavigationMonitoring;




@end
