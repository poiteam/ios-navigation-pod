//
//  PLNNavigationMapViewDelegate.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 15/05/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol PLNNavigationMapViewDelegate  <NSObject>


@optional

-(void)treePoiSelected:(NSString *)poiId;

-(void)childsAreReady;

-(void)routeIsRequestedFrom:(NSString *)storeId;

@end
