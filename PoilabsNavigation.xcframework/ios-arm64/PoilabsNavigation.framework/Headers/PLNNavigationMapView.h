//
//  PLNavigationMapView.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LGPlusButtonsView.h"
#import <Mapbox/Mapbox.h>
#import "PLNLocationManager.h"
#import "PLNCustomAnnotationView.h"
#import "PLNNavigationMapViewDelegate.h"
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "PLFloor.h"
#import "PLNCustomCalloutView.h"
#import "PLNFacility.h"
#import "PLPositioningManager.h"
#import "PLNPositioningManagerDelegate.h"
#import "PLNPointInfoView.h"
#import "PLNTextFieldTint.h"
#import "PLNShowAllTableViewCell.h"
#import "PoilabsSdkAnalytics/PoilabsSdkAnalytics.h"
#import "PoilabsCore/PLCoreWrapper.h"
#import "PLNOtherFloorsPopUp.h"

@interface PLNNavigationMapView : UIView<UITableViewDelegate, UITableViewDataSource, MGLMapViewDelegate,UIGestureRecognizerDelegate,UIPickerViewDelegate,UIPickerViewDataSource,UICollectionViewDelegate,UICollectionViewDataSource,UICollectionViewDelegateFlowLayout, PLNPositioningManagerDelegate, UITextFieldDelegate, PLNPointInfoViewDelegate, PLCoreDelegate>
{
    NSInteger selectedIndexPathRow;
    CGFloat selectedCellSize;
}

@property(strong, nonatomic) id<PLNNavigationMapViewDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *contentView;

@property (weak, nonatomic) IBOutlet UIView *mapBaseView;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *FloorChooseHeight;

#pragma mark - Search Bar
@property (weak, nonatomic) IBOutlet UIView *searchBarBaseView;

@property (weak, nonatomic) IBOutlet UIView *backButtonBaseView;

@property (weak, nonatomic) IBOutlet UIButton *backButton;

@property (weak, nonatomic) IBOutlet UIView *searchBaseView;

@property (weak, nonatomic) IBOutlet PLNTextFieldTint *searchTextField;

@property (weak, nonatomic) IBOutlet UIView *searchCancelBaseView;

@property (weak, nonatomic) IBOutlet UIButton *searchCancelButton;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *backButtonBaseViewWidthLayoutConstraint;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *searchCancelBaseViewWidthLayoutConstraint;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *searchBaseViewHeightConstraint;


- (IBAction)searchCanceled:(id)sender;

- (IBAction)searchTextFieldEditingDidBegin:(id)sender;

- (IBAction)searchTextFieldEditingChanged:(id)sender;

- (IBAction)searchTextFieldDidEndOnExit:(id)sender;

@property (weak, nonatomic) IBOutlet UIView *tableViewBaseView;

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *popularSearchTitleLabelHeightConstraint;

@property (weak, nonatomic) IBOutlet UILabel *popularSearchesLabel;

#pragma mark - Floors 
@property (weak, nonatomic) IBOutlet UIView *floorSelectionBaseView;

@property (weak, nonatomic) IBOutlet UIButton *floorSelectionButton;

#pragma mark - Left Buttons
@property (weak, nonatomic) IBOutlet UIButton *babyButton;

@property (weak, nonatomic) IBOutlet UIButton *compassButton;

@property (weak, nonatomic) IBOutlet UIButton *userFollowButton;

@property (weak, nonatomic) IBOutlet UIButton *carButton;

- (IBAction)makeBabyActions:(id)sender;

- (IBAction)makeCompassActions:(id)sender;

- (IBAction)makeFollowActions:(id)sender;

- (IBAction)makeCarActions:(id)sender;



#pragma mark - Remove Route View
@property (weak, nonatomic) IBOutlet UIView *removeRouteBaseView;

@property (weak, nonatomic) IBOutlet UILabel *removeRouteTitleLabel;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *removeRouteBaseViewWidthLayoutConstraint;

- (IBAction)removeRouteAction:(id)sender;

@property (weak, nonatomic) IBOutlet UILabel *currentFloorName;



#pragma mark - RED Alert View
@property (weak, nonatomic) IBOutlet UIView *redAlertBaseView;

@property (weak, nonatomic) IBOutlet UILabel *redAlertDescriptionLabel;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *redAlertBaseHeightLayoutConstraint;

- (IBAction)redAlertButtonTapped:(id)sender;


#pragma mark - Floor Change View

@property (weak, nonatomic) IBOutlet UIView *floorChangeDescriptionBaseView;

@property (weak, nonatomic) IBOutlet UILabel *floorChangeDescriptionLabel;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *floorChangeDescriptionViewTopLayoutConstraint;

#pragma mark - Choose Manual Parking Area

@property (weak, nonatomic) IBOutlet UIView *chooseManualParkingAreaBaseView;

@property (weak, nonatomic) IBOutlet UIView *chooseManualParkingAreaAlphaView;

@property (weak, nonatomic) IBOutlet UIView *chooseManualParkingAreaPickerContentBaseView;

@property (weak, nonatomic) IBOutlet UIButton *saveManualParkingAreaButton;
    @property (weak, nonatomic) IBOutlet UILabel *saveManualParkingButtonLabel;
    
- (IBAction)saveManualParking:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *cancelManualParkingButton;
    @property (weak, nonatomic) IBOutlet UILabel *cancelManualParkingButtonLabel;
    
- (IBAction)cancelManualParking:(id)sender;

@property (weak, nonatomic) IBOutlet UILabel *manualParkingDescriptionLabel;

@property (weak, nonatomic) IBOutlet UIPickerView *firstPickerView;

@property (weak, nonatomic) IBOutlet UIPickerView *secondPickerView;

@property (weak, nonatomic) IBOutlet UIPickerView *thirdPickerView;

-(void)getShowonMapPin:(NSString *)poiId;
-(void)showMultiplePins:(NSArray *)storeIds;
-(void)addSharedLocationPinToCoordinate:(CLLocationCoordinate2D)coordinate floorLevel:(int)floorLevel withIcon:(UIImage*)icon withTitle:(NSString*)title;
-(void)removeSharedLocationPin;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *removeRouteBottomHeight;

@property (weak, nonatomic) IBOutlet UICollectionView *CollecitonViewfloorChangeSlider;


// slider collection tanımlama

@property (weak, nonatomic) IBOutlet UICollectionView *collectionViewSlider;


@property (weak, nonatomic) IBOutlet UILabel *cancelLabelAction;

//bir noktadan baska noktaya rota almasi icin
-(void)getRouteFrom:(PLPoi *)startPoi toEnd:(PLPoi *)endPoi type:(PLRouteLogType)type;
-(void) getRouteToFacility:(PLPoi *)startPoi toFacilityType:(NSString *)facilityType;
-(void)navigateForMultiplePointRoute:(PLPoi *)startPoi;

-(void)logSearchKeyword:(NSString *)keyword;

-(void)navigateWithStoreIdTo:(NSString *)targetPoiStoreId;
-(void)getRouteWithMultiplePoints:(NSArray *)storeIds;

@end
