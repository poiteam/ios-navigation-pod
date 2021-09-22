//
//  PLNavigationConfig.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PLNNavigationConfig : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *messageUrl;

@property(strong, nonatomic) NSString *uuidString;

@property(strong, nonatomic) NSString *childsUrl;

@property(strong, nonatomic) NSMutableArray *majorId;

@property(assign, nonatomic) int timeInterval;

@property(strong, nonatomic) NSString *mallPoiId;

@property(assign, nonatomic) int beaconCount;

@property(assign,nonatomic) int minimumRssiLimit;

@property(assign, nonatomic) int decideUnavailableLocationServiceLimit;

//@property(strong, nonatomic) NSString *floorPassBy;

@end
