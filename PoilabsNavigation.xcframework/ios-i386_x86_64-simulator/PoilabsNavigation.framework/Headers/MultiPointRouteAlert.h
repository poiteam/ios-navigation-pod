//
//  MultiPointRouteAlert.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 22.02.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLNUtils.h"

@interface MultiPointRouteAlert : UIView
- (id)initWithFrame:(CGRect)theFrame desriptionText:(NSString *)description completionHandler:(void(^)(bool)) handler;
@property (strong, nonatomic) UILabel *descriptionLabel;
@property (strong, nonatomic) UIButton *startButton;
@property (strong, nonatomic) UIButton *cancelButton;
@property (strong, nonatomic) void (^actionHandler)(bool status);
@end
