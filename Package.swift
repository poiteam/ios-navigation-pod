// swift-tools-version:5.3
import PackageDescription

// Mapbox 11.18.0 (dinamik). MapboxCommon, MapboxCoreMaps ve Turf Mapbox'ın resmî
// dağıtım adreslerinden gelir; MapboxMaps'in dinamik xcframework'ü Mapbox'ın
// "direct download" paketinden ayrılıp bu reponun GitHub Release'ine konmuştur
// (binary'ler Mapbox'ın dağıttıklarıyla birebir aynıdır).
let package = Package(
    name: "PoilabsNavigation",
    platforms: [
        .iOS(.v14)
    ],
    products: [
        .library(
            name: "PoilabsNavigation",
            targets: [
                "PoilabsNavigation",
                "PoilabsMapView",
                "PoilabsCommon",
                "MapboxMaps",
                "MapboxCoreMaps",
                "MapboxCommon",
                "Turf",
                "PoilabsNavigationResources"
            ]
        )
    ],
    dependencies: [
        .package(name: "PoilabsPositioning", url: "https://github.com/poiteam/ios-positioning-pod.git", .exact("1.2.0")),
        .package(name: "PoilabsSdkAnalytics", url: "https://github.com/poiteam/ios-sdk-analytics-pod.git", .exact("1.0.15")),
        .package(name: "PoilabsCore", url: "https://github.com/poiteam/PoilabsCorePod.git", .exact("1.0.17"))
    ],
    targets: [
        .binaryTarget(name: "PoilabsNavigation", path: "PoilabsNavigation.xcframework"),
        .binaryTarget(name: "PoilabsMapView", path: "PoilabsMapView.xcframework"),
        .binaryTarget(name: "PoilabsCommon", path: "PoilabsCommon.xcframework"),
        .binaryTarget(
            name: "MapboxMaps",
            url: "https://github.com/poiteam/ios-navigation-pod/releases/download/mapbox-11.18.0/MapboxMaps.xcframework.zip",
            checksum: "fcb2f1b9dc0843eaf2afd919fbcce379752c926da0e60d5e589b6a762a4ae710"
        ),
        .binaryTarget(
            name: "MapboxCoreMaps",
            url: "https://api.mapbox.com/downloads/v2/mobile-maps-core/releases/ios/packages/11.18.0/MapboxCoreMaps.xcframework-dynamic.zip",
            checksum: "2c597124fe0d57f5cec4fb828c73bd1dce86d2babd6e1116e5ec3cfc4cd39b5a"
        ),
        .binaryTarget(
            name: "MapboxCommon",
            url: "https://api.mapbox.com/downloads/v2/mapbox-common/releases/ios/packages/24.18.0/MapboxCommon.zip",
            checksum: "4c94e2d3b31ddc8e497dff6a878e165477b643bf9f324bb873dd2a052a84788c"
        ),
        .binaryTarget(
            name: "Turf",
            url: "https://github.com/mapbox/turf-swift/releases/download/v4.0.0/Turf.xcframework.zip",
            checksum: "ce43384a6f875ab4becdd6bdb7ca60447e5e9133f2acf325dc57be381b52a34c"
        ),
        .target(
            name: "PoilabsNavigationResources",
            dependencies: [
                "PoilabsPositioning",
                "PoilabsSdkAnalytics",
                "PoilabsCore"
            ],
            path: "Sources/PoilabsNavigationResources",
            resources: [.copy("PoilabsNavigationResources.bundle")]
        )
    ]
)
