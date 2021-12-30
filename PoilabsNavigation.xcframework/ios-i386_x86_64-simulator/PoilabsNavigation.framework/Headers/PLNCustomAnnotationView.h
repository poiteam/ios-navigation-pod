//
//  PLNCustomAnnotationView.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 06/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Mapbox/Mapbox.h>

@interface PLNCustomAnnotationView : MGLAnnotationView


- (nullable instancetype)initWithReuseIdentifier:(nullable NSString *)reuseIdentifier size:(CGFloat)size;

@property(strong, nonatomic, nullable) UIImageView *imageView;
-(void)changeLocationToNewCoordinate:(CLLocationCoordinate2D)newCoordinate;
-(void)rotateAnnotationToDegree:(float)degree;
-(void)changeLocationWithAnimation:(CLLocationCoordinate2D)newCoordinate;

@end
