//
//  PLPoiProperties.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 10.04.2023.
//  Copyright © 2023 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLPoiProperties : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *restrictionWarning;

@property(strong, nonatomic) NSString *zoneId;

@property(strong, nonatomic) NSString *image;

@property(strong, nonatomic) NSString *workingHours;

@property(strong, nonatomic) NSURL *phone;

@property(strong, nonatomic) NSURL *webSite;

@property(strong, nonatomic) NSString *informationText;

@end
