//
//  PLNCategory.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 15.12.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//

#ifndef PLNCategory_h
#define PLNCategory_h
#import "PLNSubcategory.h"

@interface PLNCategory : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *iconUrl;

@property(strong, nonatomic) NSString *title;

@property(strong, nonatomic) PLNSubcategory *subcategory;

@end

#endif /* PLNCategory_h */
