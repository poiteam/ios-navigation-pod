// This file is generated and will be overwritten automatically.

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(CustomLayerMapProjection)
@protocol MBMCustomLayerMapProjection
/**
 * Convert a model matrix to be usable with the currently active projection.
 * The input matrix is expected to transform coordinates from a local coordinate space
 * into web mercator coordinate space where x & y axes are defined in pixels and z in meters.
 * The output matrix will transform local coordinates and align them correctly
 * on the world coordinate space.
 *
 * @param matrix Model matrix for rendering primitives on web mercator projection
 * @param ignoreDistortion Determine whether the output matrix should keep metric size of the model fixed or not.
 *
 * @return Model matrix for rendering primitives on the active projection. Size of the input matrix needs to be 16 or no value is returned.
 */
- (nullable NSArray<NSNumber *> *)convertMercatorModelMatrixForMatrix:(nonnull NSArray<NSNumber *> *)matrix
                                                     ignoreDistortion:(BOOL)ignoreDistortion;
/**
 * Returns a model matrix for transforming coordinates from the local coordinate space of the active projection
 * into the world coordinate space. For example with globe projection the returned matrix will transform ECEF points
 * into world coordinates for rendering.
 *
 * Example: projectionMatrix * projection.getModelMatrix() * latLngToEcef(60.1699, 24.9384)
 *
 * @return Model matrix of the active projection.
 */
- (nonnull NSArray<NSNumber *> *)getModelMatrix;
/**
 * Returns normalized value [0, 1] describing phase of the transition between the currently active projection and
 * mercator projection. This value is 1 when the projection is active and transitions towards the value 0 (mercator projection)
 * as the map is zoomed.
 *
 * @return Phase value describing transition between active projection and mercator projection.
 */
- (float)getTransitionPhase;
/**
 * Returns a specialized model matrix for supporting rendering of custom geometry during transition between
 * the active projection and mercator projection. Transition matrix prepares points on web mercator coordinate space
 * to be used as destination points of the interpolation operation towards mercator projection.
 *
 * Example:
 *   ecefPoint = latLngToEcef(60.1699, 24.9384)
 *   mercPoint = latLngToMercator(60.1699, 24.9384)
 *
 *   clipPoint = projectionMatrix * lerp(getTransitionMatrix() * mercPoint, getModelMatrix() * ecefPoint, getTransitionPhase())
 */
- (nonnull NSArray<NSNumber *> *)getTransitionMatrix;
@end
