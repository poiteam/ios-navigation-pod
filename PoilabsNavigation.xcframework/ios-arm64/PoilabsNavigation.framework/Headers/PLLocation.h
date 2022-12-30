//
//  PLLocation.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLGeometry.h"
#import <CoreLocation/CoreLocation.h>

@interface PLLocation : NSObject

-(id)initWithData:(NSDictionary*)data;

//@property(strong, nonatomic) NSString *type;

@property(strong, nonatomic) PLGeometry *geometry;

@property(assign, nonatomic) int floorLevel;

@property(assign, nonatomic) CLLocationCoordinate2D shopCenterPoint;



@end
