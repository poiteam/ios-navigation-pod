# PoilabsNavigation

![Version](https://img.shields.io/github/v/tag/poiteam/ios-navigation-pod?label=version)
![Platform](https://img.shields.io/badge/platform-iOS%2014%2B-lightgrey)

**Minimum iOS:** 14.0 | **Swift:** 5.0+

## INSTALLATION

PoilabsNavigation is distributed with Swift Package Manager. CocoaPods is no longer supported; new versions are not published there.

### Swift Package Manager

1. In Xcode, select **File > Add Package Dependencies...**
2. Enter the repository URL: `https://github.com/poiteam/ios-navigation-pod.git`
3. Choose **Exact Version** `7.3.1` and add the **PoilabsNavigation** product to your app target.

The package contains everything the SDK needs: PoilabsNavigation, PoilabsMapView, PoilabsCommon and Mapbox Maps 11.18.0. PoilabsPositioning, PoilabsSdkAnalytics and PoilabsCore are resolved automatically. You do not need to add Mapbox or any other dependency yourself.

> The first package resolution can take a few minutes because the package contains the Mapbox frameworks.

**Using with PoilabsVdNavigation:** PoilabsNavigation 7.3.1 and PoilabsVdNavigation 7.2.2 use the same dependency versions. Add both packages to the same app with SPM; nothing else is needed.

**Note:** The SDK ships its own Mapbox Maps 11.18.0. If your app also adds Mapbox Maps itself, the two copies conflict.

### Migrating from CocoaPods

1. Remove `pod 'PoilabsNavigation'` from your `Podfile`, together with any `PoilabsCore`, `PoilabsPositioning` or `PoilabsSdkAnalytics` lines.
2. Run `pod install` (or `pod deintegrate` if no other pods remain).
3. Add the package with Swift Package Manager as described above.

Do not keep the SDK in your `Podfile` while it is added with SPM; the same frameworks would be embedded twice.

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
settings?.applicationId = "APPLICATION_ID"         // Required — provided by Poilabs
settings?.applicationSecret = "APPLICATION_SECRET_KEY" // Required — provided by Poilabs
settings?.navigationUniqueIdentifier = "UNIQUE_ID" // Required — unique per app user
settings?.applicationLanguage = "en"                // en, tr, hr, ar, de, ru, pl — default: "tr"
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
self.currentCarrier?.navigateWithStoreId(to: "store_id")
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
