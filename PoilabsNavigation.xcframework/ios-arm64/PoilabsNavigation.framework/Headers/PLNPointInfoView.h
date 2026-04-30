//
//  PLNPointInfoView.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 18.11.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "PLNUtils.h"
#import "PLNPointTagsCollectionView.h"
#import "PLNPointTagsCollectionViewCell.h"
#import "PLNPointInfoDetailView.h"
#import "PLNLeftAlignedCollectionViewFlowLayout.h"
#import "PLNavigationManager.h"

#import "PoilabsCommon/PoilabsCommon-Swift.h"

@protocol PLNPointInfoViewDelegate <NSObject>
@optional
-(void)pointInfoViewDidSelectTagWithTitle:(NSString *)tagTitle;
@end

@interface PLNPointInfoView : UIView<UICollectionViewDataSource,UICollectionViewDelegateFlowLayout,UIScrollViewDelegate>

- (void)addSubviewTo: (UIView *)view;
- (void)present;
- (void)dismiss:(BOOL)callHandler ;
- (instancetype)initWithPoi:(PLPoi *)poi
                  topHeight:(CGFloat)topHeight
           disableNavButton:(BOOL) disableNavButton
                   totalMin:(int) totalMin
                totalLength:(int) totalLength
          completionHandler:(void (^)(void))completionHandler
                 didDismiss:(void (^)(void))didDismiss;

@property (nonatomic, assign) CGFloat selfCornerRadius;
@property (nonatomic, assign) CGFloat topViewTopSpacing;
@property (nonatomic, assign) CGFloat topViewHeight;
@property (nonatomic, assign) CGFloat imageViewLeftSpacing;
@property (nonatomic, assign) CGFloat imageViewSize;
@property (nonatomic, assign) CGFloat labelsStackViewLeftSpacing;
@property (nonatomic, assign) CGFloat navigationButtonHeight;
@property (nonatomic, assign) CGFloat centerYOffSet;
@property (nonatomic, assign) CGFloat smallModeHeight;

@property (nonatomic, assign) CGPoint originalCenter;

@property(strong, nonatomic) PLPoi *selectedPoi;
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
@property (nonatomic,strong) UILabel *routeInfoLabel;

@property(strong, nonatomic) PLNPointTagsCollectionView *tagsCollectionView;
@property(strong, nonatomic) PLNPointInfoDetailView *detailsView;

@property(strong, nonatomic) id<PLNPointInfoViewDelegate> delegate;

@property(nonatomic, assign) int totalMin;
@property(nonatomic, assign) int totalLength;
@property(nonatomic, assign) bool disableNavButton;

@property (strong, nonatomic) void (^actionHandler)(void);
@property (strong, nonatomic) void (^didDismiss)(void);
-(void)navigateButtonPressed;

@end


