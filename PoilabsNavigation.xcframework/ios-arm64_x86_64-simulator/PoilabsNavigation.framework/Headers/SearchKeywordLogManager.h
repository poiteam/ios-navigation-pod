//
//  SearchKeywordLogTimerManager.h
//  PoilabsNavigation
//
//  Created by fahreddin on 1.12.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLNNavigationMapView.h"


@protocol SearchKeywordLogManagerDelegate;

@protocol SearchKeywordLogManagerDelegate <NSObject>
@optional
- (void)logSearchKeyword:(NSString *)searchText;
@end

@interface SearchKeywordLogManager : NSObject

@property (nonatomic, weak) id<SearchKeywordLogManagerDelegate> delegate;
@property(strong, nonatomic) NSString *searchText;

- (void)startSearchKeywordLogTimer;
- (void)stopSearchKeywordLogTimer;
- (BOOL)isTimerEmpty;

@end

