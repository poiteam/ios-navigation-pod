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
s.ios.deployment_target = '8.0'
s.name = "PoilabsNavigation"
s.summary = "Poilabs Indoor Navigation Framework"
s.requires_arc = true

#2
s.version = "1.0.3"

# 3
s.license = { :type => "MIT", :file => "LICENSE" }

# 4 - Replace with your name and e-mail address
s.author = { "Emre Kuru" => "emre@poilabs.com" }

# 5 - Replace this URL with your own GitHub page's URL (from the address bar)
s.homepage = "https://bitbucket.org/poiteam/ios-navigation-pod"

# 6 - Replace this URL with your own Git URL from "Quick Setup"
s.source = { :git => "https://bitbucket.org/poiteam/ios-navigation-pod.git", 
             :tag => "#{s.version}" }


# 7 dependency
s.dependency 'Mapbox-iOS-SDK'
s.dependency 'PoilabsAnalysis'

s.ios.vendored_frameworks = 'PoilabsNavigation.framework'
s.resources = 'PoilabsNavigationResources.bundle'
end
