#
#  Be sure to run `pod spec lint PoilabsNavigation.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name             = "PoilabsNavigation"
  s.version          = "7.0.1"
  s.summary          = "Poilabs Indoor Navigation Framework"
  s.description      = "PoilabsNavigation is a framework for indoor navigation."
  s.homepage         = "https://github.com/poiteam/ios-navigation-pod"
  s.license          = { :type => "Proprietary", :file => "LICENSE" }
  s.author           = { "Emre Kuru" => "emre@poilabs.com" }

  s.platform         = :ios, '12.0'
  s.swift_versions   = ['5.0', '5.1', '5.2', '5.3', '5.4', '5.5', '5.6', '5.7', '5.8', '5.9']

  s.source           = { :git => "https://github.com/poiteam/ios-navigation-pod.git", :tag => "#{s.version}" }

  s.vendored_frameworks = [
    'PoilabsNavigation.xcframework',
    'PoilabsMapView.xcframework',
    'PoilabsCommon.xcframework',
    'MapboxCommon.xcframework',
    'MapboxCoreMaps.xcframework',
    'MapboxMaps.xcframework',
    'Turf.xcframework'
  ]

  s.resources = 'PoilabsNavigationResources.bundle'

  # Optional: Silence modulemap warnings
  s.module_map = nil

  s.dependency 'PoilabsPositioning', '1.2.0'
  s.dependency 'PoilabsSdkAnalytics', '~> 1.0.15'
  s.dependency 'PoilabsCore', '1.0.15'
end

