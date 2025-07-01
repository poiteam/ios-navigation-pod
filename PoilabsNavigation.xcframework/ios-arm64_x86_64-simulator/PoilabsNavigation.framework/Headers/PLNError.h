//
//  PLNError.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, PLNavigationErrorCode)
{
    PLNavigationErrorCodeDefault,
    PLNavigationErrorCodeApplicationIdUnavailable,
    PLNavigationErrorCodeApplicationSecretUnavailable,
    PLNavigationErrorCodeNavigationUniqueIdentifierUnavailable,
    PLNavigationErrorCodeServerUnavailable
};

typedef NS_ENUM(NSInteger, PLNavigationWarningCode)
{
    PLNavigationWarningCodeDefault,
    PLNavigationWarningCodeLocationServiceUnavailable,
    PLNavigationWarningCodeBluetoothServiceUnavailable,
    PLNavigationWarningCodeLocationCouldntFound
};

@interface PLNError : NSObject

-(id)initWithDescription:(NSString *)comingErrorDescription withCode:(NSInteger )comingErrorCode;

@property(strong, nonatomic) NSString *errorDescription;

@property(assign, nonatomic) NSInteger errorCode;


@end
