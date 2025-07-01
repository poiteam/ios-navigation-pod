#
#  Be sure to run `pod spec lint PoilabsNavigation.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

# 1
s.platform = :ios
s.ios.deployment_target = '12.0'
s.name = "PoilabsNavigation"
s.summary = "Poilabs Indoor Navigation Framework"

#2
s.version = "6.0.1"

# 3
s.license = { :type => "Proprietary", :file => "LICENSE" }

# 4 - Replace with your name and e-mail address
s.author = { "Emre Kuru" => "emre@poilabs.com" }

# 5 - Replace this URL with your own GitHub page's URL (from the address bar)
s.homepage = "https://github.com/poiteam/ios-navigation-pod"

# 6 - Replace this URL with your own Git URL from "Quick Setup"
s.source = { :git => "https://github.com/poiteam/ios-navigation-pod.git",
             :tag => "#{s.version}" }

s.ios.vendored_frameworks = 'PoilabsNavigation.xcframework', 'PoilabsMapView.xcframework', 'PoilabsCommon.xcframework', 'MapboxCommon.xcframework', 'MapboxCoreMaps.xcframework', 'MapboxMaps.xcframework', 'Turf.xcframework'

s.resources = 'PoilabsNavigationResources.bundle'

s.dependency 'PoilabsPositioning', '1.2.0'
s.dependency 'PoilabsSdkAnalytics', '~> 1.0.15'
s.dependency 'PoilabsCore', '1.0.15'
end
