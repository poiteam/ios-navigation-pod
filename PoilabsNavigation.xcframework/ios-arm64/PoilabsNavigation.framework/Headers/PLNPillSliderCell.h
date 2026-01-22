//
//  PLNCategoryCell.h
//  PoilabsNavigation
//
//  Created by Burak on 10.11.2025.
//  Copyright © 2025 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>
@class PLNPillSliderItem;
@class PLNPillSliderCell;

@interface PLNPillSliderCell: UICollectionViewCell
@property (nonatomic, strong) PLNPillSliderItem *item;
- (void)configureWithItem:(PLNPillSliderItem *)item selected:(BOOL)selected;
@end
