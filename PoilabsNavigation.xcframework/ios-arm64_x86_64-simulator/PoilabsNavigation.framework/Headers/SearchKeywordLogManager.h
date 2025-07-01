//
//  SearchKeywordLogTimerManager.h
//  PoilabsNavigation
//
//  Created by fahreddin on 1.12.2022.
//  Copyright © 2022 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLNNavigationMapView.h"

@interface SearchKeywordLogManager : NSObject

- (instancetype)initWith:(PLNNavigationMapView *)mapView;

@property(strong, nonatomic) NSString *searchText;

- (void)startSearchKeywordLogTimer;
- (void)stopSearchKeywordLogTimer;
- (BOOL)isTimerEmpty;

@end

