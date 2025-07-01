//
//  PLNRouteHelperView.h
//  PoilabsNavigation
//
//  Created by ERCAN AYYILDIZ on 22/09/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLNRouteHelperTableViewCell.h"
#import "PoilabsSdkAnalytics/PoilabsSdkAnalytics.h"

#import "PoilabsCommon/PoilabsCommon-Swift.h"

@class PLNNavigationMapView;

@interface PLNRouteHelperView : UIView<UITableViewDelegate, UITableViewDataSource>

@property (strong, nonatomic) IBOutlet UIView *contentView;

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

@property (weak, nonatomic) IBOutlet UIButton *calculateRouteButton;

@property (weak, nonatomic) IBOutlet UIButton *cancelRouteButton;

@property (weak, nonatomic) IBOutlet UIView *poiListBaseView;

@property (weak, nonatomic) IBOutlet UIView *routeResultBaseView;

@property (weak, nonatomic) IBOutlet UITableView *poiListTableView;


@property (weak, nonatomic) IBOutlet UIView *startFinishPoiSearchBaseView;

@property (weak, nonatomic) IBOutlet UITextField *startPointTextField;

@property (weak, nonatomic) IBOutlet UITextField *finishPointTextField;


@property(strong, nonatomic) NSMutableArray *tableViewMutableArray;

@property(strong, nonatomic) NSMutableArray *allPoisMutableArray;

@property(weak, nonatomic) UITextField *activeTextField;

@property(weak, nonatomic) PLNNavigationMapView *callerVC;

@property(strong, nonatomic) PLPoi *startPoi;

@property(strong, nonatomic) PLPoi *finishPoi;

@property(assign, nonatomic) BOOL isMultiPointRoute;

@property(assign, nonatomic) BOOL isNearestFacilityRoute;

@property(strong, nonatomic) NSString *facilityType;

@property(assign, nonatomic) PLRouteLogType routeType;

- (IBAction)editingDidBegin:(id)sender;


- (IBAction)editingChanged:(id)sender;


- (IBAction)didEndOnExit:(id)sender;




#pragma mark - Button Actions

- (IBAction)calculateRoute:(id)sender;

- (IBAction)cancelRouteAction:(id)sender;




@end
