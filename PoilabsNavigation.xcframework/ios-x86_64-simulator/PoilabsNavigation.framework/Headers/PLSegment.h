//
//  PLSegment.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLSegment : NSObject


-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *startPoiId;

@property(strong, nonatomic) NSString *finishPoiId;

@property(assign, nonatomic) float weight;

@property(assign, nonatomic) float routeWeight;

@property(assign, nonatomic) BOOL isAvailableForDisabledPerson;

@property(assign, nonatomic) BOOL isPromotedForFloorChange;
@end
