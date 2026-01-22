//
//  PLNPointInfoDetailView.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 10.04.2023.
//  Copyright © 2023 poilabs. All rights reserved.
//

#import "UIKit/UIKit.h"

@interface PLNPointInfoDetailView : UIView

- (instancetype)initWithInformationText:(NSString *)text title:(NSString *) title
                           workingHours:(NSString *) workingHours phoneNumber:(NSString *)number webSite:(NSURL *)webSite andImage:(NSString *)image;

@property(strong, nonatomic) UIImageView *pointDetailImageView;
@property(strong, nonatomic) UILabel *infoLabel;
@property(strong, nonatomic) UIStackView *stackView;
@property(strong, nonatomic) UIStackView *buttonsStackView;

@property(strong, nonatomic) NSString *informationText;
@property(strong, nonatomic) NSString *title;
@property(strong, nonatomic) NSString *workingHours;
@property(strong, nonatomic) NSString *phoneNumber;
@property(strong, nonatomic) NSURL *webSite;
@property(strong, nonatomic) NSString *image;

@property bool isLoaded;

@end
