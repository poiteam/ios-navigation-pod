//
//  PLNFloorsMenuCell.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 7.10.2024.
//  Copyright © 2024 poilabs. All rights reserved.
//

#ifndef PLNFloorsMenuCell_h
#define PLNFloorsMenuCell_h

#import <UIKit/UIKit.h>
#import "PLNFloorsMenuItem.h"

@interface PLNFloorsMenuCell : UITableViewCell

// Custom background view for the cell
@property (nonatomic, strong) UIView *customBackgroundView;

// Label to display the title
@property (nonatomic, strong) UILabel *titleLabel;

@property (strong, nonatomic) UIImageView *notificationCircle;

- (void)configureWithItem:(PLNFloorsMenuItem *)item;

- (void)addNotificationCircle;
- (void)removeNotificationCircle;

@end

#endif /* PLNFloorsMenuCell_h */
