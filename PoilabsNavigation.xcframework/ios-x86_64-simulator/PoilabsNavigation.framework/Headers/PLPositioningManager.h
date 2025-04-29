//
//  PLPositioningManager.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 8.11.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "PoilabsPositioning/PoilabsPositioning.h"
#import "PLNavigationManager.h"
#import "PLNNavigationSettings.h"
#import "PoilabsSdkAnalytics/PoilabsSdkAnalytics.h"
#import "PLNPositioningManagerDelegate.h"
#import "Mapbox/Mapbox.h"
#import "PLFloor.h"
#import "PLNPositioningManagerDelegate.h"
#import "PoilabsLocation.h"

@interface PLPositioningManager: NSObject<MGLLocationManager, PoilabsPositioningDelegate>

+ (instancetype _Nonnull )sharedInstance;

@property (nonatomic, weak) id<MGLLocationManagerDelegate> _Nullable delegate;
@property (nonatomic, weak) id<PLNPositioningManagerDelegate> _Nullable errorDelegate;

@property (nonatomic, readonly) CLAuthorizationStatus authorizationStatus;

@property(strong, nonatomic, nullable) CLHeading *heading;

@property(strong,nonatomic) PLPositioning * _Nullable positioningManager;

@property(strong, nonatomic) NSTimer * _Nullable outOfRouteTimer;

@property(strong, nonatomic) NSMutableArray<NSDictionary *> * _Nonnull signalsInWindow;

-(void) startPositioningWith:(NSArray<PLPBeaconNode*>*_Nonnull)beacons;

-(void)getFirstLocation;

@property(assign, nonatomic) bool isRouteActive;

@property(strong, nonatomic) NSMutableDictionary<NSNumber*, NSMutableArray<CLLocation*> *> * _Nullable routeCoordinates;

-(double)getDistanceBetweenRouteAndLocation:(CLLocationCoordinate2D)location inFloorLevel:(int)floorLevel forPlaceId:(NSString *)placeId includeFirstStep:(bool)containsFirstStep;

-(void)setPlaceProperties;

- (PoilabsLocation *)getPoilabsLocation;

@property(strong, nonatomic, nonnull) NSString *sessionId;

+ (void)destroySharedInstance;
@end
