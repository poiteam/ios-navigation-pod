//
//  PLNRouteSelectionView.h
//  PoilabsNavigation
//
//  Created by Burak on 3.12.2025.
//  Copyright © 2025 poilabs. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "PLNRouteInfoBottomSheet.h"


@class PLNRouteSelectionView;


@protocol PLNRouteSelectionViewDelegate <NSObject>
- (void)locationSelectionClicked:(PLPoi *) selectedPoi;
- (void)directButtonClicked;
- (void)accessibleButtonClicked;
@end


@interface PLNRouteSelectionView : UIView

@property (strong, nonatomic) IBOutlet UIView *contentView;

// Card container
@property (weak, nonatomic) IBOutlet UIView *cardView;

@property (nonatomic) NSInteger selectedSegmentIndex;
@property (nonatomic, weak) id<PLNRouteSelectionViewDelegate> delegate;

// Top section
@property (weak, nonatomic) IBOutlet UIImageView *startIconImageView;
@property (weak, nonatomic) IBOutlet UIImageView *endIconImageView;
@property (weak, nonatomic) IBOutlet UILabel *sourceTitleLabel;    // "Your Location"
@property (weak, nonatomic) IBOutlet UIButton *optionsButton;       // three-dots

@property (weak, nonatomic) IBOutlet UIView *separatorView;

// Destination title
@property (weak, nonatomic) IBOutlet UILabel *destinationTitleLabel; // e.g. Pandora

// Bottom segmented action area
@property (weak, nonatomic) IBOutlet UIView *actionsBackgroundView;  // rounded container
@property (weak, nonatomic) IBOutlet UIButton *directButton;         // teal filled
@property (weak, nonatomic) IBOutlet UIButton *accessibleButton;     // secondary
@property (weak, nonatomic) IBOutlet UIStackView *buttonStackView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *buttonStackHeightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *cardViewHeightConstraint;
@property (weak, nonatomic) IBOutlet UIView *routeNotFoundView;

@property (assign) CGFloat  originalCardViewHeight;

@property(strong, nonatomic) PLPoi *selectedPoi;
- (void)activateLocationNotFound;
- (void) setButtonsVisibility:(BOOL) hidden;
- (void)configureInit:(PLPoi *) poi;
@end
