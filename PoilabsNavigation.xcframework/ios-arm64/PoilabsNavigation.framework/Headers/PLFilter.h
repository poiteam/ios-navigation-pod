//
//  PLFilter.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLFilter : NSObject

-(id)initWithData:(NSDictionary*)data;

//@property(strong, nonatomic) NSString *brand;
//
//@property(strong, nonatomic) NSString *gender;

@property(strong, nonatomic) NSString *placeType;

//@property(strong, nonatomic) NSString *placeCategory;

@property(strong, nonatomic) NSMutableArray *pointType;

//@property(strong, nonatomic) NSString *category;

//@property(strong, nonatomic) NSString *store_id;

@property(strong, nonatomic) NSArray *store_ids;

@end
