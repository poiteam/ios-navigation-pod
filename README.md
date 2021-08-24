![Poilabs](https://www.poilabs.com/public/img/poi-labs-logo.png)

# PoilabsNavigation Sdk
[![Version](https://img.shields.io/cocoapods/v/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)
[![License](https://img.shields.io/cocoapods/l/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)
[![Platform](https://img.shields.io/cocoapods/p/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)

## Instalation

### CocoaPods

To integrate PoilabsNavigation into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
pod 'PoilabsNavigation', '~> 2.5.18'
```

### Manually

Proje Dosyalarında düzenlenmesi gereken değerler aşağıda gösterilmiştir:

* **.framework** dosyasını General Sayfasında Embedded Binaries Başlığı altına ekleyiniz.

* **.bundle** dosyasını da Build Phases  Sayfasında Copy bundle Resources Başlığı altına ekleyiniz.


PoilabsNavigation, Mapbox SDK kullanmaktadır. Uygulamanıza **Mapbox.framework** eklemeniz gerekmektedir.  
[MapBox iOS Sdk](https://www.mapbox.com/ios-sdk/)

## Usage

### Objective C
Harita ModalViewController yapisindadir. Haritayi gostermek icin aşağıdaki metodu kullanarak ekranı uygulamanıza ekleyebilirsiniz. 

Aşağıdaki block metodda asenkron işlem yapılmaktadır. Completion handlerı gelene kadar HUD göstermenizde fayda olacaktır.

```objective-c
#import <PLNavigation/PLNavigation.h>
[[PLNNavigationSettings sharedInstance] setMallId:place.title];
[[PLNNavigationSettings sharedInstance] setApplicationId:place.appId];
[[PLNNavigationSettings sharedInstance] setApplicationSecret:place.appSecret];

[[PLNNavigationSettings sharedInstance] setNavigationUniqueIdentifier:@"identifier"];
//application language en/tr
[[PLNNavigationSettings sharedInstance] setApplicationLanguage:@"en"];
//show loading animation
[[PLNavigationManager sharedInstance] getReadyForStoreMapWithCompletionHandler:^(PLNError *error) {
//hide loading animation
NSLog(@"getReadyForStore");
if (error)
{
NSLog(@"Error Descr %@",error.errorDescription);
}
else
{
PLNNavigationMapView *carrierView = [[PLNNavigationMapView alloc] initWithFrame:
CGRectMake(0, 10, self.mapView.bounds.size.width, 
self.mapView.bounds.size.height)];
[carrierView awakeFromNib];
carrierView.delegate = self;
carrierView.searchBarBaseView.backgroundColor = [UIColor blackColor];
[carrierView.searchCancelButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
self.currentCarrier = carrierView;
[self.mapView addSubview:carrierView];
}
}];

```

### Swift

```swift
@IBOutlet weak var navigationView: UIView!
var currentCarrier: PLNNavigationMapView?
PLNNavigationSettings.sharedInstance().mallId = "place.title"
PLNNavigationSettings.sharedInstance().applicationId = "place.appId"         
PLNNavigationSettings.sharedInstance().applicationSecret = "place.appSecret"

PLNavigationManager.sharedInstance()?.getReadyForStoreMap(completionHandler: { (error) in
    let carrierView = PLNNavigationMapView(frame: CGRect(x: 0, y: 0, width: self.navigationView.bounds.size.width, height: self.navigationView.bounds.size.height))
    carrierView.awakeFromNib()
    carrierView.delegate = self as? PLNNavigationMapViewDelegate
    carrierView.floorChooseHeight.constant = 20
    carrierView.curretLocationBottomLabel.text = "place.title"
    carrierView.searchBarBaseView.backgroundColor = UIColor.black
    self.currentCarrier = carrierView
    self.navigationView.addSubview(carrierView)
})
```




### SDK’nın çalışması için Info.plist dosyasına eklenmesi gerekenler:

+MGLMapboxMetricsEnabledSettingShownInApp : YES

+Privacy - Location Usage Description: ‘Sizin açıklamanız’

+Privacy - Location When In Use Usage Description: ‘Sizin açıklamanız’

+Privacy - Location Always Usage Description: ‘Sizin açıklamanız’

+Privacy - Location Always and When In Use Usage Description: ‘Sizin açıklamanız’

+Privacy - Bluetooth Peripheral Usage Description: ‘Sizin açıklamanız’

## License

PoilabsNavigation is available under the MIT license. See the LICENSE file for more info.
