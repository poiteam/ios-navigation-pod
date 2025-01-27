//
//  PLNHexColorConverter.h
//  PoilabsNavigation
//
//  Created by Emre Kuru on 14.01.2025.
//  Copyright © 2025 poilabs. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PLNHexColorConverter : NSObject

/// Converts a hex string to a UIColor.
/// @param hexString The hex string (e.g., @"#FFFFFF" or @"FFFFFF").
/// @return A UIColor object representing the color, or nil if the hex string is invalid.
+ (UIColor *)colorFromHexString:(NSString *)hexString;

@end
