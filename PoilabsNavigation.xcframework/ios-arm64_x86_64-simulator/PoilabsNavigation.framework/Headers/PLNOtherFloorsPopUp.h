//
//  PLNOtherFloorsPopUp.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 1.08.2023.
//  Copyright © 2023 poilabs. All rights reserved.
//

#ifndef PLNOtherFloorsPopUp_h
#define PLNOtherFloorsPopUp_h
#import <UIKit/UIKit.h>

@interface PLNOtherFloorsPopUp : UIView

- (instancetype)initWithClickHandler:(void(^)(void)) clicked;

@property(strong, nonatomic) UIImageView *floorsIcon;
@property(strong, nonatomic) UIImageView *notificationCircle;
@property(strong, nonatomic) UILabel *otherFloorsLabel;
@property (strong, nonatomic) UIImageView *moreLevelIcon;

@property (strong, nonatomic) void (^clicked)(void);

@end

#endif /* PLNOtherFloorsPopUp_h */
