//
//  PLNPositioning.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 7.02.2023.
//  Copyright © 2023 poilabs. All rights reserved.
//

#ifndef PLNPositioning_h
#define PLNPositioning_h

@interface PLNPositioning : NSObject

-(id)initWithData:(NSDictionary*)data;

@property(assign, nonatomic) float beaconScanInterval;

@property(assign, nonatomic) float requestInterval;

@property(assign, nonatomic) float rerouteDuration;

@property(assign, nonatomic) float rerouteDistance;

@end
#endif /* PLNPositioning_h */
