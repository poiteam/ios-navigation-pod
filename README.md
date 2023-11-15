# PoilabsNavigation
[![Version](https://img.shields.io/cocoapods/v/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)
[![Platform](https://img.shields.io/cocoapods/p/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)

## INSTALLATION

### CocoaPods

To integrate PoilabsNavigation into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
pod 'PoilabsNavigation'
```

## PRE-REQUIREMENTS
To Integrate this framework you should add some features to your project info.plist file.

+MGLMapboxMetricsEnabledSettingShownInApp : YES

+Privacy - Location Usage Description

+Privacy - Location When In Use Usage Description

+Privacy - Bluetooth Peripheral Usage Description

+Privacy - Bluetooth Always Usage Description

## USAGE

You can add Mapview with method below.

This method works asynchronously. You can add loading hud while waiting completionHandler.

### Swift

```swift
@IBOutlet weak var navigationView: UIView!
var currentCarrier: PLNNavigationMapView?
PLNNavigationSettings.sharedInstance().applicationId = APPLICATION_ID         
PLNNavigationSettings.sharedInstance().applicationSecret = APPLICATION_SECRET_KEY
PLNNavigationSettings.sharedInstance().navigationUniqueIdentifier = UNIQUE_IDENTIFIER
PLNavigationManager.sharedInstance()?.getReadyForStoreMap(completionHandler: { (error) in
	if error == nil {
    	let carrierView = PLNNavigationMapView(frame: CGRect(x: 0, y: 0, width: self.navigationView.bounds.size.width, height: self.navigationView.bounds.size.height))
    	carrierView.awakeFromNib()
    	carrierView.delegate = self
    	self.currentCarrier = carrierView
    	self.navigationView.addSubview(carrierView)
    } else {
    	//show error
    }
})
```

or you can init sdk without mapview and you can get user location update


```swift
    PLNavigationManager.sharedInstance().initWithAppId(APPLICATION_ID, andSecret: APPLICATION_SECRET_KEY, uniqueId: UNIQUE_IDENTIFIER)
    PLNavigationManager.sharedInstance().delegate = self //PLNNavigationMapViewDelegate
```

You can change colors of top bar and cancel button text according to your application theme.

```swift
    carrierView.searchBarBaseView.backgroundColor = UIColor.black
    carrierView.searchCancelButton.setTitleColor(.white, for: .normal)
```

### PLNNavigationMapViewDelegate


**poilabsNavigationReadyForRouting** 

```swift
    func poilabsNavigationReadyForRouting() {
        //Now you can route with store_id
    }
```

**didUserLocationChange** callback is triggered when location change.

```swift
    func poilabsNavigation(didUpdate userLocation: CLLocationCoordinate2D, floorLevel: Int, floorName: String) {
        
    }
```

**didUserVisitPointWithStoreIds** callback is triggered when if there is any point having store_id near user.

```swift
    func didUserVisitPoint(with storeIds: [String]) {

    }
```

**childsAreReady** callback is triggered when location list is ready. You can show any location or navigate to any location after it is triggered.

```swift
    func childsAreReady() {
        
    }
```

**didLocationStatusChanged** callback is triggered when found, waiting or lost user location.

```swift
    func didLocationStatusChange(_ status: PLLocationStatus) {
        switch status {
        case PLLocationStatusWaiting:
            break
        case PLLocationStatusNotFound:
            break
        case PLLocationStatusFound:
            break
        default:
            break
        }
    }
```

### Using custom user location icon

PoilabsNavigation will show a user icon for default. But if you want to use another icon for user location, before calling -getReadyForStoreMap method, you should set **customUserIcon** with your image.

```swift
	PLNNavigationSettings.sharedInstance().customUserIcon = UIImage(...
```

### Start with active compass mode

In default settings, map will start with deactive compass. User can activate with button on the left side. If you want to start map with active compass mode, before calling -getReadyForStoreMap method, you should set **isCompassActive** to true.


```swift
	PLNNavigationSettings.sharedInstance().isCompassActive = true
```

### Showing location pin on map

After **-childsAreReady** method is triggered, you can show a location on map with its store id. Pass decimal storeId as **String** to **-getShowonMapPin** method.

```swift
	self.currentCarrier?.getShowonMapPin("store_id")
```

### Showing multiple pins on map

After **-childsAreReady** method is triggered, you can show locations on map with their store ids. Pass decimal storeIds as **Array of Strings** to **-showMultiplePins** method.

```swift
	self.currentCarrier?.showMultiplePins(["store_id1", "store_id2", "store_id3"])
```

### Getting route on map

After **-childsAreReady** method is triggered, you can get route on map with destination location's store id. Pass decimal storeId as **String** to **-navigateWithStoreId** method. If user location exists, route will be shown from current location to destination. But if there is no user location and location list is controlled by PoiLabs, user select start location on list. But if location list is under your control and there is no user location, route cannot be taken.


```swift
	self.currentCarrier?.navigateWithStoreId(to: "store_id")
```

### Getting route with multiple points

After **-childsAreReady** method is triggered, you can get route on map with a list of store ids. Pass decimal storeIds as **Array of Strings** to **-getRouteWithMultiplePoints** method.

```swift
	self.currentCarrier?.getRouteWithMultiplePoints(["store_id1", "store_id2", "store_id3"])
```
