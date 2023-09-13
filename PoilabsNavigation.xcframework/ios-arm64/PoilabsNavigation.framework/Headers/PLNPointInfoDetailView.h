//
//  PLNPointInfoDetailView.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 10.04.2023.
//  Copyright © 2023 poilabs. All rights reserved.
//

#import "UIKit/UIKit.h"
#import "PLPoiProperties.h"

@interface PLNPointInfoDetailView : UIView

- (instancetype)initWithProperties:(PLPoiProperties *)properties;

@property(strong, nonatomic) UIImageView *pointDetailImageView;
@property(strong, nonatomic) UILabel *infoLabel;
@property(strong, nonatomic) UIStackView *stackView;
@property(strong, nonatomic) UIStackView *buttonsStackView;

@property(strong, nonatomic) PLPoiProperties *poiProperties;

@property bool isLoaded;

@end
