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
#import <sys/utsname.h>
#import "PLNNavigationMapViewDelegate.h"

@interface PLNavigationManager : NSObject

+ (instancetype)sharedInstance;

@property(strong, nonatomic) id<PLNNavigationMapViewDelegate> delegate;

-(void)getReadyForStoreMapWithCompletionHandler:(void (^)(PLNError *error))completionHandler;

-(void)initWithAppId:(NSString *)appId andSecret:(NSString *)secret uniqueId:(NSString *)uniqueId;

@property (strong, nonatomic) PLNavigationResponse *navigationResponse;

@property (strong, nonatomic) PLPoi *childsPlace;

@property(strong, nonatomic) PLNNavigationConfig *config;

@property(strong, nonatomic) NSMutableDictionary<NSNumber*, NSDictionary<NSString*, NSNumber*>*> *shiftParameters;

-(void)postSignals:(NSArray<NSDictionary*> *) signals;

-(NSString *)getFacilityTitleFor:(NSString *)type;

@end
