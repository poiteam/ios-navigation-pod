//
//  PLNPointInfoView.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 18.11.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "PLPoi.h"
#import "PLNUtils.h"

@interface PLNPointInfoView : UIView

- (void)addAssSubviewTo: (UIView *)view;
- (void)present;
- (void)dismiss;
- (instancetype)init:(PLPoi *)point completionHandler:(void(^)(void)) handler;
@property(strong, nonatomic) PLPoi *point;
@property(strong, nonatomic) UIImageView *imageView;
@property(strong, nonatomic) UIImageView *navigateIcon;
@property(strong, nonatomic) UILabel *placeTitleLabel;
@property(strong, nonatomic) UILabel *placeTypeLabel;
@property(strong, nonatomic) UIButton *navigationButton;
@property(strong, nonatomic) UIStackView *labelsStackView;
@property(strong, nonatomic) UIView *topView;
@property (strong, nonatomic) void (^actionHandler)(void);
-(void)navigateButtonPressed;

@end

