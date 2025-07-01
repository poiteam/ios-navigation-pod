//
//  PLNPositioningManagerDelegate.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 8.11.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//

#import "PLPositioningManager.h"
#import <CoreLocation/CoreLocation.h>
@protocol PLNPositioningManagerDelegate <NSObject>

typedef enum positioningManagerError
    {
        BLUETOOTH,
        LOCATION
    } PoilabsPositioningManagerError;

@optional
-(void)positioningManagerDidFail: (PoilabsPositioningManagerError)error;
-(void)positioningManagerDidStart;
-(void)positioningManagerDidOutOfRoute;
-(void)positioningManagerDidUpdateUserLocation: (CLLocation *) location andHeading:(CLHeading *)heading inFloorLevel:(int)floorLevel;

@end
