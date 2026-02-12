//
//  PLNavigationMapView.h
//  PoiNavigationMainApp
//
//  Created by ERCAN AYYILDIZ on 05/04/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLNLocationManager.h"
#import "PLNNavigationMapViewDelegate.h"
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "PLPositioningManager.h"
#import "PLNPositioningManagerDelegate.h"
#import "PLNPointInfoView.h"
#import "PLNTextFieldTint.h"
#import "PLNShowAllTableViewCell.h"
#import "PoilabsSdkAnalytics/PoilabsSdkAnalytics.h"
#import "PoilabsCore/PLCoreWrapper.h"
#import "PLNOtherFloorsPopUp.h"
#import "PLNFloorsMenu.h"
#import "PLNPillSliderView.h"
#import "PoilabsMapView/PoilabsMapView-Swift.h"
#import "PLNRouteSelectionView.h"
#import "PLNRoutePageBottomSheet.h"
#import "FloorSliderChange.h"

@interface PLNNavigationMapView : UIView< UIGestureRecognizerDelegate,UIPickerViewDelegate,UIPickerViewDataSource,UICollectionViewDelegate,UICollectionViewDataSource,UICollectionViewDelegateFlowLayout, PLNPositioningManagerDelegate, UITextFieldDelegate, PLNPointInfoViewDelegate, PLCoreDelegate, PLMapViewDelegate, PLNPillSliderViewDelegate, PLNRouteSelectionViewDelegate, PLNRouteInfoBottomSheetDelegate, PLNRoutePageBottomSheetDelegate, FloorSliderChangeDelegate>
{
    NSString *selectedRouteKey;
    NSInteger selectedIndexPathRow;
    CGFloat selectedCellSize;
}
- (instancetype)initWithFrame:(CGRect)frame
                       searchText:(NSString *)searchText;

+ (PLCoreWrapper *)sharedCore;

@property (strong, nonatomic) PLMapView *poilabsMapView;

@property(strong, nonatomic) id<PLNNavigationMapViewDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *contentView;

@property (weak, nonatomic) IBOutlet UIView *mapBaseView;

@property (weak, nonatomic) IBOutlet PLNPillSliderView *categoryPillView;
@property (weak, nonatomic) IBOutlet PLNRouteSelectionView *routeSelectionView;
@property (weak, nonatomic) IBOutlet UIView *leftStackView;

#pragma mark - Search Bar
@property (weak, nonatomic) IBOutlet UIView *searchBarBaseView;

@property (weak, nonatomic) IBOutlet PLNTextFieldTint *searchTextField;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *searchBaseViewHeightConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *searchTextFieldTopConstraint;
@property (nonatomic, assign) BOOL shouldShowSearchOnLoad;
@property (nonatomic, copy) NSString *searchTextForInit;
@property (nonatomic, assign) BOOL isInfoLoading;
@property (nonatomic, assign) BOOL routeFocusActive;
@property (nonatomic, assign) int routeFocusCollectionFloorIndex;

- (IBAction)searchTextFieldEditingDidBegin:(id)sender;


#pragma mark - Left Buttons
@property (weak, nonatomic) IBOutlet UIButton *babyButton;

@property (weak, nonatomic) IBOutlet UIButton *userFollowButton;

@property (weak, nonatomic) IBOutlet UIButton *carButton;

- (IBAction)makeBabyActions:(id)sender;

- (IBAction)makeFollowActions:(id)sender;

- (IBAction)makeCarActions:(id)sender;

#pragma mark - Remove Route View
@property (weak, nonatomic) IBOutlet UIView *removeRouteBaseView;

@property (weak, nonatomic) IBOutlet UILabel *removeRouteTitleLabel;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *removeRouteBaseViewWidthLayoutConstraint;

- (IBAction)removeRouteAction:(id)sender;

#pragma mark - RED Alert View
@property (weak, nonatomic) IBOutlet UIView *redAlertBaseView;

@property (weak, nonatomic) IBOutlet UILabel *redAlertDescriptionLabel;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *redAlertBaseHeightLayoutConstraint;

- (IBAction)redAlertButtonTapped:(id)sender;

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


@property(strong, nonatomic) PLNRouteInfoBottomSheet *routeInfoBottomSheet;

-(void) selectStartPoiForRoute:(PLPoi *)startPoi targetPoi:(PLPoi *)targetPoi;
-(void)getShowonMapPin:(NSString *)poiId;
-(void)showMultiplePins:(NSArray *)storeIds;
-(void)addSharedLocationPinToCoordinate:(CLLocationCoordinate2D)coordinate floorLevel:(int)floorLevel withIcon:(UIImage*)icon withTitle:(NSString*)title;
-(void)removeSharedLocationPin;

@property (weak, nonatomic) IBOutlet UICollectionView *collectionViewfloorChangeSlider;


// slider collection tanımlama

@property (weak, nonatomic) IBOutlet UICollectionView *collectionViewSlider;

//bir noktadan baska noktaya rota almasi icin
-(void)getRouteFrom:(PLPoi *)startPoi toEnd:(PLPoi *)endPoi type:(PLRouteLogType)type;
-(void) getRouteToFacility:(PLPoi *)startPoi toFacilityType:(NSString *)facilityType;
-(void)navigateForMultiplePointRoute:(PLPoi *)startPoi;

-(void)logSearchKeyword:(NSString *)keyword;

-(void)navigateWithStoreIdTo:(NSString *)targetPoiStoreId;
-(void)getRouteWithMultiplePoints:(NSArray *)storeIds;

// Location Selection Mode
@property (nonatomic, assign) BOOL isLocationSelectionMode;
-(void)enterLocationSelectionMode;
-(void)exitLocationSelectionMode;

@end

