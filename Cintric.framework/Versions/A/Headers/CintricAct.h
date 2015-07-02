//
//  CintricAct.h
//  Cintric SDK
//
//  Copyright (c) 2015 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/// Completeion block which returns NSArray response
typedef void (^cintricResponse)(NSArray *);

@interface CintricAct : NSObject

/**
 Asynchronously request an array of CintricUserProfile objects nearest to a specified coordinate.
 
 @discussion This method will send a request to the Cintric Act API to get nearby users.
 Once complete the completionBlock will be called with the array of user objects.
 The number of users returned will be "count" (or fewer if you don't have that many users).
 "count" can not be more than 200 (a larger number will be set to 200).
 
 @param coordinate The coordinate which you are specifying for nearby users.
 @param count The total number of nearby users you want returned, this will never exceed 200.
 @param completionBlock A block which returns a NSArray of CintricUserProfile objects.
 */
+ (void)requestNearestUsersToLocation:(CLLocationCoordinate2D)coordinate count:(int)count completion:(cintricResponse)completionBlock;

+ (void)setGoalConversionForCoordinate:(CLLocationCoordinate2D)coord
                                radius:(double)radius
                             startTime:(NSDate *)startTime
                               endTime:(NSDate *)endTime
                                  name:(NSString *)name
                                  tags:(NSArray *)tags
                              uniqueId:(NSString *)uniqueId __deprecated;

+ (void)customCintricEventNamed:(NSString *)eventName withValue:(NSString *)value andTags:(NSArray *)tags __deprecated;

@end
