//
//  PLNFloorsMenu.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 7.10.2024.
//  Copyright © 2024 poilabs. All rights reserved.
//

#ifndef PLNFloorsMenu_h
#define PLNFloorsMenu_h
#import <UIKit/UIKit.h>
#import "PLNFloorsMenuItem.h"
#import "PLNFloorsMenuCell.h"

@interface PLNFloorsMenu : UIView <UITableViewDelegate, UITableViewDataSource>

- (instancetype)initWithMenuItems:(NSArray<PLNFloorsMenuItem *> *)menuItems actionHandler:(void(^)(PLNFloorsMenuItem *selectedFloor))actionHandler;

@property (nonatomic, assign, readonly) BOOL isMenuOpen;

- (CGFloat)getMaxWidth;
-(void)close;
-(void)selectFloorWithBuildingName:(NSString*) buildingName floorName:(NSString *)floorName;
-(void)toggleMenu;
-(void)addNotificationCirclesTo:(NSDictionary<NSString *, NSArray<NSString *>*> *)dict;
-(void)removeNotificationCircles;

@end

#endif /* PLNFloorsMenu_h */
