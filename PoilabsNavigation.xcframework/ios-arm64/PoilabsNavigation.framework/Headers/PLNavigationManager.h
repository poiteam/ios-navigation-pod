//
//  PLNavigationManager.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/16/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PLNError.h"
#import "PLNavigationResponse.h"
#import "PLNNavigationConfig.h"
#import "PLPositioningManager.h"

@interface PLNavigationManager : NSObject

+ (instancetype)sharedInstance;

-(void)getReadyForStoreMapWithCompletionHandler:(void (^)(PLNError *error))completionHandler;

@property (strong, nonatomic) PLNavigationResponse *navigationResponse;

@property (strong, nonatomic) PLPoi *childsPlace;

@property(strong, nonatomic) PLNNavigationConfig *config;

@end
