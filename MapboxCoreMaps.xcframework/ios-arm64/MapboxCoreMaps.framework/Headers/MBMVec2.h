// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

/** 2 component vector. */
NS_SWIFT_NAME(Vec2)
__attribute__((visibility ("default")))
@interface MBMVec2 : NSObject

// This class provides custom init which should be called
- (nonnull instancetype)init NS_UNAVAILABLE;

// This class provides custom init which should be called
+ (nonnull instancetype)new NS_UNAVAILABLE;

- (nonnull instancetype)initWithX:(double)x
                                y:(double)y;

/** The x component of the vector. */
@property (nonatomic, readonly) double x;

/** The y component of the vector. */
@property (nonatomic, readonly) double y;


- (BOOL)isEqualToVec2:(nonnull MBMVec2 *)other;

@end
