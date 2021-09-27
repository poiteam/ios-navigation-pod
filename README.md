![Poilabs](https://www.poilabs.com/public/img/poi-labs-logo.png)

# PoilabsNavigation Sdk
[![Version](https://img.shields.io/cocoapods/v/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)
[![License](https://img.shields.io/cocoapods/l/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)
[![Platform](https://img.shields.io/cocoapods/p/PoilabsNavigation.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)

## Instalation

### CocoaPods

To integrate PoilabsNavigation into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
pod 'PoilabsNavigation'
```

### Manually

Proje Dosyalarında düzenlenmesi gereken değerler aşağıda gösterilmiştir:

* **.framework** dosyasını General Sayfasında Embedded Binaries Başlığı altına ekleyiniz.

* **.bundle** dosyasını da Build Phases  Sayfasında Copy bundle Resources Başlığı altına ekleyiniz.


PoilabsNavigation, Mapbox SDK kullanmaktadır. Uygulamanıza **Mapbox.framework** eklemeniz gerekmektedir.  
[MapBox iOS Sdk](https://www.mapbox.com/ios-sdk/)

## Kullanım

Haritayi gostermek icin aşağıdaki metodu kullanarak ekranı uygulamanıza ekleyebilirsiniz. 

Aşağıdaki block metodda asenkron işlem yapılmaktadır. Completion handlerı gelene kadar HUD göstermenizde fayda olacaktır.


### Swift

```swift
@IBOutlet weak var navigationView: UIView!
var currentCarrier: PLNNavigationMapView?
PLNNavigationSettings.sharedInstance().mallId = "place.title"
PLNNavigationSettings.sharedInstance().applicationId = "place.appId"         
PLNNavigationSettings.sharedInstance().applicationSecret = "place.appSecret"

PLNavigationManager.sharedInstance()?.getReadyForStoreMap(completionHandler: { (error) in
	if error == nil {
    	let carrierView = PLNNavigationMapView(frame: CGRect(x: 0, y: 0, width: self.navigationView.bounds.size.width, height: self.navigationView.bounds.size.height))
    	carrierView.awakeFromNib()
    	carrierView.delegate = self
    	carrierView.curretLocationBottomLabel.text = "place.title"
    	carrierView.searchBarBaseView.backgroundColor = UIColor.black
    	carrierView.searchCancelButton.setTitleColor(.white, for: .normal)
    	self.currentCarrier = carrierView
    	self.navigationView.addSubview(carrierView)
    } else {
    	//show error
    }
})
```
Mağaza listesi üst bar'ının ve listeyi kapatma button'un rengini uygulamanıza göre değiştirebilirsiniz. 

```swift
    carrierView.searchBarBaseView.backgroundColor = UIColor.black
    carrierView.searchCancelButton.setTitleColor(.white, for: .normal)
```

### PLNNavigationMapViewDelegate

childsAreReady konum listesi hazır olduğunda tetiklenir. Göstermek istediğiniz lokasyonları gösterebilir veya istediğiniz bir konuma rota alabilirsiniz. 

```swift
    func childsAreReady() {
        //konum gösterme ve rota alma işlemleri için PoilabsNavigation Sdk hazır
    }
```

### Kullanıcı konum ikonunun ayarlanması

PoilabsNavigation sdk tarafından belirlenmiş bir ikon kullanıcı konumunu gösterecektir. Eğer kendiniz başka bir ikon kullanmak istiyorsanız. -getReadyForStoreMap methodu öncesinde istediğiniz ikonu customUserIcon'a set etmeniz gerekmektedir. Herhangi bir atama yapmaz iseniz varsayılan ikon ile kullanıcı konumu gösterilecektir.

```swift
	PLNNavigationSettings.sharedInstance().customUserIcon = UIImage(...
```

### Pusula aktif olarak başlatma

Varsayılan ayar pusulanın kapalı olarak haritanın açılmasıdır. Kullanıcı ister ise pusulayı harita açıldıktan sonra açabilir. Eğer başlangıçta pusula açık bir şekilde haritayı ayağa kaldırmak istiyorsanız -getReadyForStoreMap methodu öncesinde isCompassActive ayarını true yapmanız gerekmektedir.

```swift
	PLNNavigationSettings.sharedInstance().isCompassActive = true
```

### Harita üzerinde pin gösterme

Konum listesinin hazır olduğu haberi geldikten sonra aşağıdaki method ile istediğiniz store id'ye sahip bir konumu harita üzerinde gösterebilirsiniz. String tipinde, decimal storeId ile çalışmaktadır. 

```swift
	self.currentCarrier?.getShowonMapPin("store_id")
```

### Harita üzerinde birden fazla pin gösterme

Konum listesinin hazır olduğu haberi geldikten sonra aşağıdaki method ile istediğiniz store id'lere sahip konumları harita üzerinde gösterebilirsiniz. String listesi tipinde, decimal storeId'ler ile çalışmaktadır. 

```swift
	self.currentCarrier?.showMultiplePins(["store_id1", "store_id2", "store_id3"])
```

### İstenilen bir konuma rota alma

Konum listesinin hazır olduğu haberi geldikten sonra aşağıdaki method ile istediğiniz store id'ye sahip bir konuma rota alabilirsiniz. String tipinde, decimal storeId ile çalışmaktadır. Kullanıcı konumu var ise mevcut konumdan verilen storeId'ye sahip konumlardan en yakınına rota alınıp haritada gösterilecektir. Eğer konum yok ise konum listesi PoilabsNavigation sdk kontrolüne bırakılmışsa başlangıç noktası sdk tarafından seçtirilecektir. Eğer konum listesi gizli olarak ayarlanmışsa rota oluşturulamayacaktır. 

```swift
	self.currentCarrier?.navigateWithStoreId(to: "store_id")
```

### SDK’nın çalışması için Info.plist dosyasına eklenmesi gerekenler:

+MGLMapboxMetricsEnabledSettingShownInApp : YES

+Privacy - Location Usage Description: ‘Sizin açıklamanız’

+Privacy - Location When In Use Usage Description: ‘Sizin açıklamanız’

+Privacy - Location Always Usage Description: ‘Sizin açıklamanız’

+Privacy - Location Always and When In Use Usage Description: ‘Sizin açıklamanız’

+Privacy - Bluetooth Peripheral Usage Description: ‘Sizin açıklamanız’

+Privacy - Bluetooth Always Usage Description: ‘Sizin açıklamanız’
