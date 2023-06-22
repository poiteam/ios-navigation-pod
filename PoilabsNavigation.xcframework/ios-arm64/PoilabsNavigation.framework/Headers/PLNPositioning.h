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

- (float) rerouteDuration;

- (float) rerouteDistance;

- (float) requestInterval;

- (float) beaconScanInterval;

@end
#endif /* PLNPositioning_h */
