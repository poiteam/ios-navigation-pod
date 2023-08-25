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
#import "MultiPointRouteAlert.h"
#import "PLNFacility.h"
#import "PLPositioningManager.h"
#import "PLNPositioningManagerDelegate.h"
#import "PLNPointInfoView.h"
#import "PLNTextFieldTint.h"
#import "PLNShowAllTableViewCell.h"
#import "PoilabsSdkAnalytics/PoilabsSdkAnalytics.h"
#import "PoilabsCore/PLCoreWrapper.h"
#import "PLNOtherFloorsPopUp.h"

@interface PLNNavigationMapView : UIView<UITableViewDelegate, UITableViewDataSource, MGLMapViewDelegate,UIGestureRecognizerDelegate,UIPickerViewDelegate,UIPickerViewDataSource,UICollectionViewDelegate,UICollectionViewDataSource,UICollectionViewDelegateFlowLayout, PLNPositioningManagerDelegate, UITextFieldDelegate, PLNPointInfoViewDelegate>
{
    NSInteger selectedIndexPathRow;
    CGFloat selectedCellSize;
}

@property(strong, nonatomic) id<PLNNavigationMapViewDelegate> delegate;

@property (strong, nonatomic) IBOutlet UIView *contentView;

@property (weak, nonatomic) IBOutlet UIView *mapBaseView;

//@property(strong, nonatomic) MGLMapView *mapView;

@property(strong, nonatomic) MGLMapCamera *mapCamera;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *FloorChooseHeight;

#pragma mark - Algorithm

@property (nonatomic) MGLCoordinateBounds colorado;

@property(strong, nonatomic) NSMutableArray *polylineAnnotationsMutableArray;

@property(strong, nonatomic) NSMutableArray *tableViewStoresMutableArray;

@property (nonatomic) MGLShapeSource *polylineSource;

@property(assign, nonatomic) float currentMapHeadingValue;

@property(assign, nonatomic) float currentDeviceHeadingValue;

@property(strong, nonatomic) PLNCustomAnnotationView *userLocationAnnotationView;

@property(strong, nonatomic) MGLPointAnnotation *userPointAnnotation;

@property(strong, nonatomic) NSMutableArray *upCustomPointAnnotationsMutableArray;
@property(strong, nonatomic) NSMutableArray *downCustomPointAnnotationsMutableArray;
@property(strong, nonatomic) NSMutableArray *upPointAnnotationsMutableArray;
@property(strong, nonatomic) NSMutableArray *downPointAnnotationsMutableArray;
@property(strong, nonatomic) PLNCustomAnnotationView *placeCustomAnnotationView;
@property(strong, nonatomic) MGLPointAnnotation *placePointAnnotation;
@property(strong, nonatomic) NSMutableArray *placePointAnnotationArray;

@property(strong, nonatomic) PLNCustomAnnotationView *startCustomAnnotationView;
@property(strong, nonatomic) MGLPointAnnotation *startPointAnnotation;

@property(strong, nonatomic) PLNCustomAnnotationView *finishCustomAnnotationView;
@property(strong, nonatomic) MGLPointAnnotation *finishPointAnnotation;



#pragma mark - Trees
//@property(strong, nonatomic) NSMutableArray *selectedCustomAnnotationViewArray;
@property(strong, nonatomic) NSMutableArray *selectedPointAnnotationArray;

//@property(strong, nonatomic) NSMutableArray *unselectedCustomAnnotationViewArray;
@property(strong, nonatomic) NSMutableArray *unselectedPointAnnotationArray;

@property(strong, nonatomic) NSMutableArray *descriptionArray;

@property(strong, nonatomic) NSMutableArray *imageArray;



@property(strong, nonatomic) NSMutableArray *upPointAnnotationsMutableArrayLenght;
@property(strong, nonatomic) NSMutableArray *downPointAnnotationsMutableArrayLenght;
@property(strong, nonatomic) NSMutableArray *allFloorsPolylineMutableArray;
@property(strong, nonatomic) NSMutableArray *dashedLineLocations;
@property(strong,nonatomic) PLPoi *targetLocationPoi;

-(void)setTargetLocationPoi:(PLPoi *)targetLocationPoi;

@property(strong, nonatomic) PLNPointInfoView *pointInfoView;

@property(strong,nonatomic) PLPoi *startLocationPoi;

@property(strong,nonatomic) PLFloor *showingFloor;
@property(strong,nonatomic) PLFloor *userLocationFloor;
@property(strong,nonatomic) PLNRoute *currentRoute;
@property(strong, nonatomic) NSMutableArray<PLNRoute *> *routes;
@property(strong, nonatomic) NSArray<NSString *> *pointsToGoStoreIds;

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

@property(strong, nonatomic) LGPlusButtonsView *floorsPlusButtonsView;

@property (weak, nonatomic) IBOutlet UIButton *floorSelectionButton;

@property (strong, nonatomic) UIImageView *floorSelectionButtonNotificationCircle;


@property(assign, nonatomic) BOOL bluetoothStatus;

@property(assign, nonatomic) BOOL locationServicesStatus;


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


#pragma mark - Car Actions

@property(strong, nonatomic) UIAlertController *autoParkCarSectionAlertController;
@property(strong, nonatomic) UIAlertController *manualCarSelectOptionAlertController;


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

-(void)addSelectedTrees:(NSArray *)comingSelectedTrees andUnselectedTrees:(NSArray *)comingUnselectedTrees;

-(void)getShowonMapPin:(NSString *)poiId;
-(void)showMultiplePins:(NSArray *)storeIds;

-(void) selectStartPoiForRoute:(NSString *)senderPoiId;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *removeRouteBottomHeight;

@property (weak, nonatomic) IBOutlet UICollectionView *CollecitonViewfloorChangeSlider;


// slider collection tanımlama

@property (weak, nonatomic) IBOutlet UICollectionView *collectionViewSlider;


@property (weak, nonatomic) IBOutlet UILabel *cancelLabelAction;
// Otopark isimleri kisma
@property(strong, nonatomic) NSMutableArray *autoparkingDisable;


@property (strong, nonatomic) MultiPointRouteAlert *multiPointRouteAlert;

@property(strong, nonatomic) NSMutableArray<PLNFacility *> *facilities;

//bir noktadan baska noktaya rota almasi icin
-(void)getRouteFrom:(PLPoi *)startPoi toEnd:(PLPoi *)endPoi;
-(void) getRouteToFacility:(PLPoi *)startPoi toFacilityType:(NSString *)facilityType;
-(void)navigateForMultiplePointRoute:(PLPoi *)startPoi;
-(void)navigateWithStoreIdTo:(NSString *)targetPoiStoreId;
-(void)getRouteWithMultiplePoints:(NSArray *)storeIds;
-(PLFloor *)getFloorWithLevel:(int)level;
-(void)changeCurrentFloor;
-(PLPoi *)getNearestPoiWithSegmentTo: (CLLocationCoordinate2D)coordinate;
-(PLPoi *)getNearestPoiTo: (CLLocationCoordinate2D)coordinate;

-(void)logSearchKeyword:(NSString *)keyword;

@property(strong, nonatomic) NSTimer *readyForRouteTimer;

@property(strong, nonatomic) PLNOtherFloorsPopUp *otherFloorsPopUp;

@property(strong, nonatomic) NSMutableArray<MGLPointFeature*> *showingPointFeatures;

@end
