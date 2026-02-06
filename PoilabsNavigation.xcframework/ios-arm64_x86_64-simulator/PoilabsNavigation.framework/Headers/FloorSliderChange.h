//
//  FloorChangeSliderChange.h
//  PoilabsNavigationResources
//
//  Created by Poi Osman BayraKLI on 6.04.2018.
//  Copyright © 2018 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PLNRoutePageIconType) {
    PLNRoutePageDirect = 0,
    PLNRoutePageRight,
    PLNRoutePageLeft,
    PLNRoutePageBack,
    PLNRoutePageNext,
    PLNRoutePageFinal,
    PLNRoutePageFinished,  // New finished state
    
    PLNRoutePageUpElevator,
    PLNRoutePageUpEscalator,
    PLNRoutePageUpStairs,
    
    PLNRoutePageDownElevator,
    PLNRoutePageDownEscalator,
    PLNRoutePageDownStairs,

};

@protocol FloorSliderChangeDelegate <NSObject>
- (void)tapDetectedRightImage;
- (void)tapDetectedLeftImage;
@end

@interface FloorSliderChange : UICollectionViewCell

@property (nonatomic, assign) PLNRoutePageIconType iconType;

@property (nonatomic, weak) id<FloorSliderChangeDelegate> delegate;
@property (nonatomic, strong) UIImageView *iconImageView;
@property (nonatomic, strong) UILabel *descLabel;
@property (nonatomic, strong) UIImageView *nextIconView;

// Hit areas (Apple HIG)
@property (nonatomic, strong) UIButton *leftButton;
@property (nonatomic, strong) UIButton *rightButton;

// Icon images
@property (nonatomic, strong) UIImageView *leftArrowImageView;

- (void)configureWithText:(NSString *)text
                 iconType:(PLNRoutePageIconType)iconType
                isFirst:(BOOL)isFirst
                 isLast:(BOOL)isLast;

@end

