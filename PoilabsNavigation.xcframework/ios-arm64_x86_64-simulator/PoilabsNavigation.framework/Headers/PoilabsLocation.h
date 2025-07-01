//
//  PoilabsLocation.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 2.04.2025.
//  Copyright © 2025 poilabs. All rights reserved.
//

#ifndef PoilabsLocation_h
#define PoilabsLocation_h

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface PoilabsLocation : NSObject

@property (strong, nonatomic) CLLocation *location;
@property (assign, nonatomic) int floorLevel;
@property (strong, nonatomic) NSString *placeId;

- (instancetype)initWithLocation:(CLLocation *)location floorLevel:(int)floorLevel placeId:(NSString *)placeId;

@end
#endif /* PoilabsLocation_h */
