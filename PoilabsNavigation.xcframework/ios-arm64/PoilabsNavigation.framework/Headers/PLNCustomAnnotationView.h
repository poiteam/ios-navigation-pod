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
-(nullable instancetype)initSharedLocationAnnotationView:(nullable UIImage *)icon title:(nullable NSString *) title;

-(void)changeLocationWithAnimation:(CLLocationCoordinate2D)newCoordinate;

@property(strong, nonatomic, nullable) UIImageView *imageView;
@property(strong, nonatomic, nullable) UILabel *descriptionLabel;

@end
