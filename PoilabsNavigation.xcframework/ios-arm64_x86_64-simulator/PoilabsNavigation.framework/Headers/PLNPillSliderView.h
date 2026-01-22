//
//  PLNCategoriesViewController.h
//  PoilabsNavigation
//
//  Created by Burak on 10.11.2025.
//  Copyright © 2025 poilabs. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "PLNPillSliderItem.h"
#import "PLNPillSliderCell.h"


@protocol PLNPillSliderViewDelegate <NSObject>
- (void)pillSliderViewDidSelectCell:(PLNPillSliderCell *)cell
                     isCategoryOpen:(BOOL)isCategoryOpen;
@end

@interface PLNPillSliderView : UIView
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (strong, nonatomic) IBOutlet UIView *contentView;
- (void)setItems:(NSArray<PLNPillSliderItem *> *)items;
@property (nonatomic, weak) id<PLNPillSliderViewDelegate> delegate;

@end
