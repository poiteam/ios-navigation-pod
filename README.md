# PoilabsNavigation

![Version](https://img.shields.io/cocoapods/v/PoilabsNavigation.svg?style=flat)
![Platform](https://img.shields.io/cocoapods/p/PoilabsNavigation.svg?style=flat)

**Minimum iOS:** 14.0 | **Swift:** 5.0+

## INSTALLATION

### CocoaPods

To integrate PoilabsNavigation into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
pod 'PoilabsNavigation'
```

Then run:

```bash
$ pod install
$ open YourApp.xcworkspace
```

## PRE-REQUIREMENTS

Add the following keys to your project `Info.plist` file:

- **Privacy - Location Usage Description**
- **Privacy - Location When In Use Usage Description**
- **Privacy - Bluetooth Peripheral Usage Description**
- **Privacy - Bluetooth Always Usage Description**

## CONFIGURATION

Set these properties **before** calling `getReadyForStoreMap`:

```swift
let settings = PLNNavigationSettings.sharedInstance()
settings.applicationId = "APPLICATION_ID"         // Required — provided by Poilabs
settings.applicationSecret = "APPLICATION_SECRET_KEY" // Required — provided by Poilabs
settings.navigationUniqueIdentifier = "UNIQUE_ID" // Required — unique per app user
settings.applicationLanguage = "en"                // "tr" or "en", default: "tr"
```

**Optional settings:**

| Property | Type | Description |
|----------|------|-------------|
| `placeId` | String | Override venue ID. Set if you serve multiple venues. |
| `customUserIcon` | UIImage | Custom icon for user location on map. |
| `isCompassActive` | Bool | Start map with compass enabled. Default: `false`. |
| `isSearchBarHidden` | Bool | Hide the search bar. Default: `false`. |

## USAGE

### Showing the Map

```swift
@IBOutlet weak var navigationView: UIView!
var currentCarrier: PLNNavigationMapView?

PLNavigationManager.sharedInstance()?.getReadyForStoreMap(completionHandler: { error in
    if let error = error {
        print("SDK init failed: \(error)")
        return
    }

    let carrierView = PLNNavigationMapView(
        frame: CGRect(x: 0, y: 0,
                      width: self.navigationView.bounds.size.width,
                      height: self.navigationView.bounds.size.height)
    )
    carrierView.awakeFromNib()
    carrierView.delegate = self
    self.currentCarrier = carrierView
    self.navigationView.addSubview(carrierView)
})
```

### Using Without Map (Location Only)

If you only need user location updates without showing a map:

```swift
PLNavigationManager.sharedInstance()?.initWithAppId(
    "APPLICATION_ID",
    andSecret: "APPLICATION_SECRET_KEY",
    uniqueId: "UNIQUE_ID"
)
PLNavigationManager.sharedInstance()?.delegate = self
```

### Showing a Pin on Map

After `childsAreReady` is called, show a location by its store ID:

```swift
self.currentCarrier?.getShowonMapPin("store_id")
```

### Showing Multiple Pins

```swift
self.currentCarrier?.showMultiplePins(["store_id1", "store_id2", "store_id3"])
```

### Navigating to a Store

After `poilabsNavigationReadyForRouting` is called:

```swift
self.currentCarrier?.navigateWithStoreIdTo("store_id")
```

If the user's location is available, the route starts from their current position. Otherwise the user is prompted to select a start location.

### Multi-Point Route

```swift
self.currentCarrier?.getRouteWithMultiplePoints(["store_id1", "store_id2", "store_id3"])
```

### Starting with Search Text

Open the map with a pre-filled search query:

```swift
let carrierView = PLNNavigationMapView(
    frame: CGRect(x: 0, y: 0,
                  width: self.navigationView.bounds.size.width,
                  height: self.navigationView.bounds.size.height),
    searchText: "coffee"
)
```

## PLNNavigationMapViewDelegate

Implement these callbacks to respond to SDK events:

### childsAreReady

Called when venue data is loaded. Safe to show pins or navigate after this.

```swift
func childsAreReady() {
    // Now you can call getShowonMapPin, showMultiplePins
}
```

### poilabsNavigationReadyForRouting

Called when routing is available. Safe to call navigation methods after this.

```swift
func poilabsNavigationReadyForRouting() {
    // Now you can call navigateWithStoreIdTo, getRouteWithMultiplePoints
}
```

### didUserLocationChange

Called when the user's indoor position updates.

```swift
func didUserLocationChange(_ coordinate: CLLocationCoordinate2D,
                           floorLevel: Int,
                           floorName: String) {
    print("User at \(coordinate.latitude), \(coordinate.longitude) — Floor: \(floorName)")
}
```

### didLocationStatusChange

Called when positioning status changes.

```swift
func didLocationStatusChange(_ status: PLLocationStatus) {
    switch status {
    case PLLocationStatusWaiting:
        print("Searching for location...")
    case PLLocationStatusFound:
        print("Location found")
    case PLLocationStatusNotFound:
        print("Location not available")
    default:
        break
    }
}
```

### didUserVisitPointWithStoreIds

Called when the user is near a POI.

```swift
func didUserVisitPoint(with storeIds: [String]) {
    print("User near stores: \(storeIds)")
}
```

## COMMON ERRORS

| Error | Probable Cause | Fix |
|-------|---------------|-----|
| Init fails with error | Wrong `APPLICATION_ID` or `APPLICATION_SECRET_KEY` | Verify credentials with Poilabs |
| No user location (no blue dot) | Location or Bluetooth permissions not granted | Check Info.plist keys and request runtime permissions |
| Map loads but no blue dot | User not in beacon-covered area | Ensure beacons are deployed and BLE is on |
| `childsAreReady` not called | Network error loading venue data | Check internet connection and credentials |
