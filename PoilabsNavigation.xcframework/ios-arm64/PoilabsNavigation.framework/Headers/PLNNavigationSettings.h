//
//  PLNNavigationSettings.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PLNNavigationSettings : NSObject

+ (instancetype)sharedInstance;
+ (void)destroySharedInstance;

@property(strong, nonatomic) NSString *applicationId;

@property(strong, nonatomic) NSString *placeId;

@property(strong, nonatomic) NSString *applicationSecret;

@property(strong, nonatomic) NSString *navigationUniqueIdentifier;

// set tr or en, default is tr
@property(strong, nonatomic) NSString *applicationLanguage; 


//optional
@property(assign, nonatomic) float backButtonWidth;

@property(assign, nonatomic) float searchCancelWidth;

@property(strong, nonatomic) UIImage *customUserIcon;

@property(assign, nonatomic) BOOL isCompassActive;

@property(assign, nonatomic) BOOL isSearchBarHidden;

- (void)setApplicationLanguage:(NSString *)applicationLanguage;

-(NSString *)getpoilabsNavigationVersionNumber;
@end
