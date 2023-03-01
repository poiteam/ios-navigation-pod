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
#import "PLNPointTagsCollectionView.h"
#import "PLNPointTagsCollectionViewCell.h"

@interface PLNPointInfoView : UIView<UICollectionViewDataSource,UICollectionViewDelegateFlowLayout>

- (void)addAssSubviewTo: (UIView *)view;
- (void)present;
- (void)dismiss:(BOOL)callHandler ;
- (instancetype)init:(PLPoi *)point completionHandler:(void(^)(void)) handler didDismiss:(void(^)(void)) dismiss;
@property(strong, nonatomic) PLPoi *point;
@property(strong, nonatomic) UIImageView *imageView;
@property(strong, nonatomic) UIImageView *navigateIcon;
@property(strong, nonatomic) UILabel *placeTitleLabel;
@property(strong, nonatomic) UILabel *placeTypeLabel;
@property(strong, nonatomic) UIButton *navigationButton;
@property(strong, nonatomic) UIStackView *labelsStackView;
@property(strong, nonatomic) UIView *topView;
@property(strong, nonatomic) UIView *smallModeContainerView;

@property(strong, nonatomic) PLNPointTagsCollectionView *tagsCollectionView;
@property (strong, nonatomic) void (^actionHandler)(void);
@property (strong, nonatomic) void (^didDismiss)(void);
-(void)navigateButtonPressed;

@end


