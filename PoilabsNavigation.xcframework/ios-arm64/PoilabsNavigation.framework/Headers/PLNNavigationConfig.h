//
//  PLNavigationConfig.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLNPositioning.h"

@interface PLNNavigationConfig : NSObject

-(id)initWithData:(NSDictionary*)data;



@property(strong, nonatomic) NSString *uuidString;



@property(strong, nonatomic) NSMutableArray *majorList;

@property(strong, nonatomic) NSString *placeId;

@property(assign,nonatomic) int minimumRssiLimit;

@property(strong, nonatomic) NSDictionary *walkways;

@property(strong, nonatomic) PLNPositioning *positioning;

@property(strong, nonatomic) NSNumber *topPoiCount;

//MARK: Urls

@property(strong, nonatomic) NSString *positioningSignalsUrl;

@property(strong, nonatomic) NSString *placeUrl;

@property(strong, nonatomic) NSString *childsUrl;

@property(strong, nonatomic) NSString *walkwaysUrl;

@property(strong, nonatomic) NSString *beaconListUrl;

@property(strong, nonatomic) NSString *eventsUrl;

@property(strong, nonatomic) NSString *logsUrl;

-(NSString *)eventsUrl;

-(NSString *_Nullable)getRemovedLayerPrefix;


@end
