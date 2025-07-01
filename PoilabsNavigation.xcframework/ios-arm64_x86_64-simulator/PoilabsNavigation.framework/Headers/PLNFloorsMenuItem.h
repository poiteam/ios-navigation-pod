//
//  PLNFloorsMenuItem.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 7.10.2024.
//  Copyright © 2024 poilabs. All rights reserved.
//

#ifndef PLNFloorsMenuItem_h
#define PLNFloorsMenuItem_h
@interface PLNFloorsMenuItem : NSObject

@property (nonatomic, strong) NSString * _Nonnull title;
@property (nonatomic, strong, nullable) NSArray<PLNFloorsMenuItem *> *subItems;
@property (nonatomic, assign) BOOL isExpanded;
@property (nonatomic, weak, nullable) PLNFloorsMenuItem *parent;
@property (nonatomic, assign) BOOL hasNotification;

- (instancetype _Nonnull )initWithTitle:(NSString *_Nonnull)title subItems:(nullable NSArray<PLNFloorsMenuItem *> *)subItems parent:(nullable PLNFloorsMenuItem *)parent;
- (BOOL)isSubItem;

- (BOOL)isEqual:(id _Nonnull )object;

@end

#endif /* PLNFloorsMenuItem_h */
