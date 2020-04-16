//
//  SearchFirstTableViewCell.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SearchFirstTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIButton *elevatorButton;

@property (weak, nonatomic) IBOutlet UIButton *womanButton;

@property (weak, nonatomic) IBOutlet UIButton *manButton;


@property (weak, nonatomic) IBOutlet UILabel *elevatorLabel;

@property (weak, nonatomic) IBOutlet UILabel *womanLabel;

@property (weak, nonatomic) IBOutlet UILabel *manLabel;


@end
