// swift-tools-version:5.3
import PackageDescription

// CocoaPods'taki kurulumla aynı: 7 xcframework de bu repodan gelir (Mapbox 11.18.0, dinamik).
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
        .binaryTarget(name: "MapboxMaps", path: "MapboxMaps.xcframework"),
        .binaryTarget(name: "MapboxCoreMaps", path: "MapboxCoreMaps.xcframework"),
        .binaryTarget(name: "MapboxCommon", path: "MapboxCommon.xcframework"),
        .binaryTarget(name: "Turf", path: "Turf.xcframework"),
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
