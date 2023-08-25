//
//  PLNavigationResponse.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLPoi.h"

@interface PLNavigationResponse : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) PLPoi *mallPoi;

@property(strong, nonatomic) NSMutableArray *allPointsForParking;

@property(strong, nonatomic) NSMutableArray *allPointsForMap;

@end
