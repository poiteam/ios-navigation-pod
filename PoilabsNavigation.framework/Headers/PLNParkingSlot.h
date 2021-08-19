//
//  PLNParkingSlot.h
//  PoilabsNavigation
//
//  Created by ERCAN AYYILDIZ on 02/06/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLNParkingSlot : NSObject

-(id)initWithData:(NSDictionary*)data;

@property (strong, nonatomic) NSString *parkingKeyName;

@property (strong, nonatomic) NSMutableArray *parkingValues;

@end
