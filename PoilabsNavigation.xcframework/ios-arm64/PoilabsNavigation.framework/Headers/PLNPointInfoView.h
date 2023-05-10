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
#import "PLNPointInfoDetailView.h"
#import "PLNLeftAlignedCollectionViewFlowLayout.h"

@interface PLNPointInfoView : UIView<UICollectionViewDataSource,UICollectionViewDelegateFlowLayout,UIScrollViewDelegate>

- (void)addAssSubviewTo: (UIView *)view;
- (void)present;
- (void)dismiss:(BOOL)callHandler ;
- (instancetype)init:(PLPoi *)point completionHandler:(void(^)(void)) handler didDismiss:(void(^)(void)) dismiss;
@property(strong, nonatomic) PLPoi *point;
@property(strong, nonatomic) UIImageView *categoryIconImageView;
@property(strong, nonatomic) UIImageView *navigateIcon;
@property(strong, nonatomic) UILabel *placeTitleLabel;
@property(strong, nonatomic) UILabel *placeTypeLabel;
@property(strong, nonatomic) UIButton *navigationButton;
@property(strong, nonatomic) UIStackView *labelsStackView;
@property(strong, nonatomic) UIView *topLineView;
@property(strong, nonatomic) UIImageView *workingHoursImageView;
@property(strong, nonatomic) UILabel *workingHoursLabel;
@property(strong, nonatomic) UIView *smallModeContainerView;
@property(strong, nonatomic) UIScrollView *scrollView;

@property(strong, nonatomic) PLNPointTagsCollectionView *tagsCollectionView;
@property(strong, nonatomic) PLNPointInfoDetailView *detailsView;

@property (strong, nonatomic) void (^actionHandler)(void);
@property (strong, nonatomic) void (^didDismiss)(void);
-(void)navigateButtonPressed;

@end


