//
//  PLNRoutePageBottomSheet.h
//  PoilabsNavigation
//
//  Created by Burak on 19.12.2025.
//  Copyright © 2025 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PLNRoutePageBottomSheetDelegate <NSObject>
- (void)routeClearClicked;
- (void)routeFocusClicked;
@end

@interface PLNRoutePageBottomSheet : UIView

- (instancetype)initWithTitle:(NSString *)targetTitle
                     totalMin:(int) totalMin
                  totalLength:(int) totalLength;

- (void)addSubviewTo: (UIView *)view;
- (void)configureWithTitle:(NSString *)title
                      time:(NSString *)timeDistance;

- (void)updateMinLength:(int) totalMin totalLength:(int) totalLength;

@property (nonatomic, weak) id<PLNRoutePageBottomSheetDelegate> delegate;

@property(nonatomic, assign) int totalMin;
@property(nonatomic, assign) int totalLength;

@property (nonatomic, assign) CGFloat smallModeHeight;
@property (nonatomic, strong) NSString *targetTitle;

@property (nonatomic, strong) UILabel *routeToLabel;

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *detailLabel;

@property (nonatomic, strong) UIButton *routeFocusButton;
@property (nonatomic, strong) UIButton *clearRouteButton;

@property (nonatomic, strong) UIView *routeFocusButtonContainer;

@property (nonatomic, strong) UIStackView *textStack;
@property (nonatomic, strong) UIStackView *actionStack;

@property (nonatomic, strong) NSLayoutConstraint *sheetHeightConstraint;
@property (nonatomic, weak) UIView *containerView;

@end
