//
//  PLNSubcategory.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 7.02.2023.
//  Copyright © 2023 poilabs. All rights reserved.
//

#ifndef PLNSubcategory_h
#define PLNSubcategory_h

@interface PLNSubcategory : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) NSString *title;

@end

#endif /* PLNSubcategory_h */
