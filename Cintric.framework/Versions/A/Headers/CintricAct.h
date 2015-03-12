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
 Create a goal to track whether a user goes to a location or not within some time span.
 You can track goal conversion rates and details on the web panel.
 
 For example, you may want to track what percent of users go to a POI within a week, after viewing it on a map.
 Each time the user views a POI you call setGoalConversionForCoordinate and it will automatically be tracked by the server.
 Use the name to differentiate types of goals, you might call this one "POI Conversion".
 
 You can then see the conversion rates of all users who have a goal called "POI Conversion".
 You may want to use the tags to filter and sort your goals. Perhaps if the POI is a restaurant have a tag "restaurant".
 
 The purpose of the unique ID is so that duplicate goals are not created for the same user.
 You may want to use a different unique ID for each POI, but any time the user views the same POI use the same unique ID.
 This will update the goal that was previously set with that unique ID. Unique IDs only have to be unique per user.
 A good choice for your unique id would be the unique id of the POI the user is viewing.
 
 In this example, you would set the startTime as the current time, and the endTime as the current time + one week.
 Then use the coordinate for your POI, and a radius depending on the size of the POI in interest.
 If you don’t have a clear idea for your radius size, a good default choice is 50 (radius is in meters).
 
 @param coord     The lat lon coordinate of the goal destination
 @param radius    The radius in meters, how far from the coordinate counts as a conversion. 50 is a good default.
 @param startTime The time for the start of your goal. If a user goes to the location before this date, it does not count as a conversion. A good default is [NSDate date].
 @param endTime   The end time for your goal to count as a conversion. This is important to see how many people do not complete the goal.
 @param name      The name of your goal. This is used to aggregate and sort similar goals on the web panel
 @param tags      NSArray of NSString. Tags are used to sort and filter goals on the web panel.
 @param uniqueId  A unique NSString. Using the same unique id for a goal for the same user will update the parameters of the goal rather than creating a new one.
 */
+ (void)setGoalConversionForCoordinate:(CLLocationCoordinate2D)coord
                                radius:(double)radius
                             startTime:(NSDate *)startTime
                               endTime:(NSDate *)endTime
                                  name:(NSString *)name
                                  tags:(NSArray *)tags
                              uniqueId:(NSString *)uniqueId;

/**
 Declare the occurrence of an event you would like to track. 
 For example you may want to track when the user likes a status (so you can see when and where they were). 
 You might do something like:
 @code
 [CintricAct customCintricEventNamed:@"Liked Status" withValue:@"status name" andTags:@[@"status", @"social"]];
 @endcode
 
 @param eventName NSString identifying the event.
 @param value     NSString describing the details specific to that event, or what happened.
 @param tags      NSArray of NSStrings which are used to filter / sort events on the dashboard.
 */
+ (void)customCintricEventNamed:(NSString *)eventName withValue:(NSString *)value andTags:(NSArray *)tags;

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

@end
