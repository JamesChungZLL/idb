/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBControlCore.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Builds an xcresulttool invocation as a subprocess.
 */
@interface FBXCTestResultToolOperation : NSObject

/**
 Get the JSON representation of the XCTest result bundle

 @param path the path of the result bundle
 @param bundleObjectId ID of an object in the result bundle
 @param queue the queue to use for serialization.
 @param logger the logger to log to.
 @return a future that wraps the extracted JSON object.
 */
+ (FBFuture<NSDictionary<NSString *, NSDictionary<NSString *, id> *> *> *)getJSONFrom:(NSString *)path forId:(nullable NSString *)bundleObjectId queue:(dispatch_queue_t)queue logger:(nullable id<FBControlCoreLogger>)logger;

/**
Export file or directory from the XCTest result bundle

@param path the path of the result bundle
@param destination the location for the exported file/directory
@param bundleObjectId ID of an object in the result bundle
@param exportType file or directory
@param queue the queue to use for serialization.
@param logger the logger to log to.
@return a future that resolves when the task has finished.
*/
+ (FBFuture<FBTask *> *)exportFrom:(NSString *)path to:(NSString *)destination forId:(NSString *)bundleObjectId withType:(NSString *)exportType queue:(dispatch_queue_t)queue logger:(nullable id<FBControlCoreLogger>)logger;

/**
Describe the format of the result bundle

@param queue the queue to use for serialization.
@param logger the logger to log to.
@return a future that wraps the format description in JSON.
*/
+ (FBFuture<NSDictionary<NSString *, NSDictionary<NSString *, id> *> *> *)describeFormat:(dispatch_queue_t)queue logger:(nullable id<FBControlCoreLogger>)logger;

@end

NS_ASSUME_NONNULL_END
