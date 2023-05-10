//
//  PLFloor.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


@interface PLFloor : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *title;

@property(assign, nonatomic) int level;

@property(assign, nonatomic) double zoomLevel;

@property(assign, nonatomic) double maxZoomLevel;

@property(assign, nonatomic) double minZoomLevel;

@property(assign, nonatomic) double navigationZoomLevel;

@property(assign, nonatomic) CLLocationCoordinate2D centerPoint;

@property(assign, nonatomic) CLLocationCoordinate2D swForBounds;

@property(assign, nonatomic) CLLocationCoordinate2D neForBounds;

@property(assign, nonatomic) float mapRotateAngle;

@property(assign, nonatomic) double conversionFactor;

@property(strong, nonatomic) NSString *floorType;

@property(strong, nonatomic) NSDictionary *parkingLabels;

@property(strong, nonatomic) NSArray *sortedKeys;

@property(strong, nonatomic) NSString *parking;

@property(strong, nonatomic) NSMutableArray *parkingSlotsMutableArray;

@property(assign, nonatomic) BOOL showOnNavigationMenu;

@property(assign, nonatomic) double shiftDistance;

@property(assign, nonatomic) double shiftAngle;
@end
