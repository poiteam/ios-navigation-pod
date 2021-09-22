//
//  PLMap.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLMap : NSObject

-(id)initWithData:(NSDictionary*)data;

//@property(strong, nonatomic) NSString *vendor;

@property(strong, nonatomic) NSString *mapId;

@property(strong, nonatomic) NSString *styleUrl;

@property(strong, nonatomic) NSString *accessToken;

@property(assign, nonatomic) int defaultFloor;

@property(strong, nonatomic) NSMutableArray *floors;

@property(strong, nonatomic) NSMutableArray *shoppingFloors;



@end
