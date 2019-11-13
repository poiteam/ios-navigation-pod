# Poi Navigation Sdk

## Usage
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

### Proje Dosyalarında düzenlenmesi gereken değerler aşağıda gösterilmiştir:

**.framework** dosyasını General Sayfasında Embedded Binaries Başlığı altına ekleyiniz.

**.bundle** dosyasını da Build Phases  Sayfasında Copy bundle Resources Başlığı altına ekleyiniz.


SDK Mapbox SDK kullanmaktadır. Uygulamanıza **Mapbox.framework** eklemeniz gerekmektedir.  
[MapBox iOS Sdk](https://www.mapbox.com/ios-sdk/)



### SDK’nın çalışması için Info.plist dosyasına eklenmesi gerekenler:

+MGLMapboxMetricsEnabledSettingShownInApp : YES

+Privacy - Location Usage Description: ‘Sizin açıklamanız’

+Privacy - Location When In Use Usage Description: ‘Sizin açıklamanız’

+Privacy - Location Always Usage Description: ‘Sizin açıklamanız’

+Privacy - Location Always and When In Use Usage Description: ‘Sizin açıklamanız’

+Privacy - Bluetooth Peripheral Usage Description: ‘Sizin açıklamanız’
