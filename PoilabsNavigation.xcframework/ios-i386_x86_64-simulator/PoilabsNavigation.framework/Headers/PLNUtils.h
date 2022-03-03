//
//  PLNUtils.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLAFHTTPSessionManager.h"


@interface PLNUtils : NSObject
+ (instancetype)sharedInstance;

+(void)logDebugInformations:(NSString *)string priority:(int)priorityLevel inManagerType:(NSString *)comingType;

+(PLAFHTTPSessionManager*)getNavigationSessionManager;

+(NSString *)getLocaleStringForQuery:(NSString *)comingStr;
+(NSString *)getLocaleStringForQueryFullTarget:(NSString *)comingStr route:(float )route target:(NSString *)target destinationFloor:(int )difFloor;
+(NSString *)getLocaleStringForMultiPointRoute:(NSString *)comingStr distance:(int)distance;
@property(strong, nonatomic) NSString *navigationUniqueIdentifier;
+(void)showAlertViewWithTitle:(NSString *)title withMessage:(NSString *)message onResponder:(UIResponder *)responder;


@end
