//
//  PLNRouteInfoBottomSheet.h
//  PoilabsNavigation
//
//  Created by Burak on 8.12.2025.
//  Copyright © 2025 poilabs. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "PLNUtils.h"
#import "PLNPointTagsCollectionViewCell.h"
#import "PLNPointInfoDetailView.h"
#import "PLNLeftAlignedCollectionViewFlowLayout.h"
#import "PLNavigationManager.h"
#import "PLNRouteInfoDetailView.h"

#import "PoilabsCommon/PoilabsCommon-Swift.h"

@protocol PLNRouteInfoBottomSheetDelegate;

@protocol PLNRouteInfoBottomSheetDelegate <NSObject>
-(void)startRouteAction;
-(void)expandAction;
@end

@interface PLNRouteInfoBottomSheet : UIView<UICollectionViewDataSource,UICollectionViewDelegateFlowLayout,
UIScrollViewDelegate>

- (void)addSubviewTo: (UIView *)view;
- (void)present;
- (instancetype)initWithPoi:(PLPoi *)poi
                  topHeight:(CGFloat)topHeight
               isRestricted:(BOOL) isRectricted
                   totalMin:(int) totalMin
                totalLength:(int) totalLength
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
@property(strong, nonatomic) UILabel *placeTitleLabel;
@property(strong, nonatomic) UILabel *placeTypeLabel;
@property(strong, nonatomic) UIButton *startButton;
@property(strong, nonatomic) UIButton *routeInfoButton;
@property(strong, nonatomic) UIStackView *labelsStackView;
@property(strong, nonatomic) UIView *topLineView;
@property(strong, nonatomic) UIView *smallModeContainerView;
@property(strong, nonatomic) UIView *mainView;
@property (nonatomic,strong) UILabel *routeInfoLabel;

@property(strong, nonatomic) PLNRouteInfoDetailView *routeInfoDetailView;

@property (nonatomic, strong) UIImageView *startIcon;
@property (nonatomic, strong) UIImageView *dirIcon;

@property(strong, nonatomic) id<PLNRouteInfoBottomSheetDelegate> delegate;

@property (nonatomic, strong) UIImageView *warningIcon;
@property (nonatomic, strong) UILabel *warningLabel;
@property (strong, nonatomic) UIView *warningContainer;
@property (strong, nonatomic) UIView *buttonsContainerView;
@property (nonatomic, assign) BOOL isRestricted;
@property (nonatomic, assign) BOOL disableButtons;

@property(nonatomic, assign) int totalMin;
@property(nonatomic, assign) int totalLength;
@property (nonatomic) CGRect originalFrame;
@property (nonatomic) CGFloat maxHeight;

@property (nonatomic, strong) NSLayoutConstraint *sheetTopConstraint;
@property (nonatomic, strong) NSLayoutConstraint *sheetHeightConstraint;

@property (strong, nonatomic) void (^didDismiss)(void);
-(void)navigateButtonPressed;
-(void)updateInfoValues;
-(void)showButtons;
-(void)setRestrictionInfo:(BOOL) isRestricted;
-(void)configureRouteSteps:(NSArray<NSDictionary *> *)stepsInfo;
@end



