//
//  PLNFacility.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 10.08.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//

#ifndef PLNFacility_h
#define PLNFacility_h

#import "UIKit/UIKit.h"

@interface PLNFacility : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *pointType;

@property(strong, nonatomic) NSString *title;

@property(assign, nonatomic) int order;

@property(strong, nonatomic) NSString *iconUrl;

@property(strong, nonatomic) UIImage *icon;

-(UIImage *)getIcon;

@end

#endif /* PLNFacility_h */
