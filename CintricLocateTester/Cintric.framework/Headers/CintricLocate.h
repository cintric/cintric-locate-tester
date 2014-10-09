//
//  CintricLocate.h
//  Cintric
//
//  Created by Joel Green on 10/1/14.
//  Copyright (c) 2014 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol CintricLocateDelegate;

/**
 CintricLocate enables battery efficient location monitoring 24/7.

 @discussion It will handle permissions and will update even after the user has force quit the app.
 Our testing shows that our location updates will use 2% or less of a users battery on an average day.
 To use this SDK you must request an api key from http://cintric.com

 Make sure in your appDelegate application:didFinishLaunchingWithOptions: method you call
 
 @code
 [CintricLocate initWithApiKey:@"your_api_key_here"]
 @endcode
 */
@interface CintricLocate : NSObject

/**
 Initalize cintric location with your api key.
 If the api key is valid location updates will start.
 @param apiKey NSString : the api key you receive when creating a Cintric developer account
 @returns CintricLocate : reference to self
 */
+ (CintricLocate *)initWithApiKey:(NSString *)apiKey;

/**
 Set the delegate to be notified when the locaiton updates or permissions change
 
 @param delegateResponder an object which implements the CintricLocateDelegate protocol
 */
+ (void)setDelegate:(id <CintricLocateDelegate>)delegateResponder;

/**
 The current location of the device.
 @discussion This should stay accurate to within 400 feet at all times.
             Some cases such as very poor reception may reduce accuracy, however this is uncommon.
             To get the lat and lon:
 @code
 CLLocation *location = [CintricLocate getCurrentLocation];
 location.coordinate.latitude //CGFloat
 location.coordinate.longitude // CGFloat
 @endcode
 */
+ (CLLocation *)getCurrentLocation;

/**
 Set this to YES to enable helpful NSLogging for debugging
 
 @param loggingEnabled YES enables logging
 */
+ (void)setDebug:(BOOL)loggingEnabled;

/**
 Updates the location to the best accuracy availble
 
 @discussion This will trigger the didUpdateDeviceLocation delegate method.
             Although you can expect the location to stay very accurate most of the time,
             this may be useful if you want to make sure the
             location is currently at the best accuracy possible.
             Call this when first showing the users locaiton on a map.
 */
+ (void)updateLocation;

/**
 Stops all locaiton updates

 @discussion Location updates will resume if you call updateLocation or
             initWithApiKey (which should always be called in application:didFinishLaunchingWithOptions:)
 */
+ (void)stopUpdatingLocation;

/**
 Set a unique ID for the current user (call this on user login or app launch)

 @discussion Calling this method will allow you to better integrate with Cloud and Metrics.
             If you are using facebook login, we suggest to use the users facebook ID here.
             Otherwise use whatever unique identifying string you have for the user.
             If you don't call this method we will use our randomly generated ID for each user.

 @param idString unique user identifying string
 */
+ (void)setUniqueIdForUser:(NSString *)idString;

@end

///------------------------------------------------
/// Delegate Protocol
///------------------------------------------------

@protocol CintricLocateDelegate <NSObject>

@optional

/**
 This is called whenever the location is updated.
 @param location CLLocation : the device's current location

 @discussion Use this to do things like update your UI, or notify your server of the location change
 You should expect the location to be at its best accuracy when this is called
 */
- (void)didUpdateDeviceLocation:(CLLocation *)location;

/** This will be called if the user allows location updates */
- (void)locationServicesAuthorized;

/** 
 This will be called if the user's device can not update location.
 Some devices may be restricted, for example, by parental controls.
 Do NOT ask your user to change their settings in this case.
 */
- (void)locationServicesRestricted;

/**
 This will be called if the user denied access location services
 We recommend you ask the user to open settings and enable their locaiton services
 */
- (void)locationServicesDenied;

@end
