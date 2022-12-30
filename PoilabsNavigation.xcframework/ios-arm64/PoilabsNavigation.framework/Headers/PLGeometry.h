//
//  PLGeometry.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface PLGeometry : NSObject

-(id)initWithData:(NSDictionary*)data;

//@property(strong, nonatomic) NSString *type;

@property(assign, nonatomic) CLLocationCoordinate2D coordinates;

@end
