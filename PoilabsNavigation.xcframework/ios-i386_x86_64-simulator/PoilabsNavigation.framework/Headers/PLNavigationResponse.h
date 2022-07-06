//
//  PLNavigationResponse.h
//  PLNavigation
//
//  Created by Ercan Ayyıldız on 12/20/16.
//  Copyright © 2016 Ercan Ayyıldız. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLPoi.h"
#import "PESGraph.h"
#import "PESGraphNode.h"
#import "PESGraphEdge.h"
#import "PESGraphRoute.h"
#import "PESGraphRouteStep.h"



@interface PLNavigationResponse : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(strong, nonatomic) PLPoi *mallPoi;

@property(strong, nonatomic) NSMutableArray *allPointsForParking;

@property(strong, nonatomic) NSMutableArray *allPointsForMap;

@property(strong, nonatomic) NSMutableArray *allGraphNodes;

@property(strong, nonatomic) NSMutableArray *allGraphEdgesForEveryOne;

@property(strong, nonatomic) NSMutableArray *allGraphEdgesForDisablePerson;


//@property(strong, nonatomic) NSMutableArray *elevatorGrapNodes;
//
//@property(strong, nonatomic) NSMutableArray *toiletGraphNodes;

@property(strong, nonatomic) NSString *elevatorPoiId;
@property(strong, nonatomic) NSString *toiletPoiId;
@property(strong, nonatomic) NSString *toiletMenPoiId;
@property(strong, nonatomic) NSString *toiletWomenPoiId;
@property(strong, nonatomic) NSString *infoPoiId;
@property(strong, nonatomic) NSString *prayPoiId;




@property(strong, nonatomic) PESGraph *mainGraph;

@property(strong, nonatomic) PESGraph *onlyPassByFilterIncludedMainGraph;

@property(strong, nonatomic) PESGraph *disableGraph;

-(PESGraphNode *)grapNodeFinderWithNodeId:(NSString *)nodeId;
-(PESGraph *)createSameLevelPoisGraph:(int)level;
-(BOOL)hasWc;
-(BOOL)hasMenWc;
-(BOOL)hasWomanWc;
@end
