//
//  CintricFind.h
//  Cintric SDK
//
//  Copyright (c) 2015 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

@protocol CintricFindDelegate;

/**
 CintricFind enables battery efficient location monitoring 24/7.

 @discussion It will handle permissions and will update even after the user has force quit the app.
             Our testing shows that our location updates will use 1% or less of a users battery on an average day.
             To use this SDK you must request an api key from http://cintric.com

 Make sure in your appDelegate application:didFinishLaunchingWithOptions: method you call
 
 @code
 [Cintric initWithApiKey:@"YOUR_API_KEY_HERE" andSecret:@"YOUR_SECRET_HERE"];
 @endcode
 
 To start location updates, you must also at some point in your app, call:
 @code
 [CintricFind updateLocation];
 @endcode
 
 @see http://cintric.com/documentation
 */
@interface CintricFind : NSObject

/**
 Set the delegate to be notified when the location updates or permissions change
 
 @param delegateResponder an object which implements the CintricFindDelegate protocol
 */
+ (void)setDelegate:(id <CintricFindDelegate>)delegateResponder;

/**
 Updates the location to the best accuracy availble. This will also enable location updates if disabled.
 
 @discussion This will trigger the didUpdateDeviceLocation delegate method.
 Although you can expect the location to stay very accurate most of the time,
 this may be useful if you want to make sure the
 location is currently at the best accuracy possible.
 Call this when first showing the users location on a map.
 */
+ (void)updateLocation;

/**
 Stops all location updates until updateLocation is called.
 */
+ (void)disableLocationUpdates;

/**
 The current location of the device.
 @discussion This should stay accurate to within 400 feet at all times.
             Some cases such as very poor reception may reduce accuracy, however this is uncommon.
             To get the lat and lon:
 @code
 CLLocation *location = [CintricFind getCurrentLocation];
 location.coordinate.latitude //CGFloat
 location.coordinate.longitude // CGFloat
 @endcode
 */
+ (CLLocation *)getCurrentLocation;

/**
 Set this to NO to turn off NSLogging. This is enabled in debug build by default.
 In production this will automatically be set to NO.
 
 @param loggingEnabled NO disables logging
 */
+ (void)setDebug:(BOOL)loggingEnabled;

/**
 Depricated. This method still works however it is recommended to use
 [CintricUserProfile setUserCustomId:]
 
 Set a unique ID for the current user (call this on user login or app launch)
 @discussion Calling this method will allow you to better integrate with Cloud and Metrics.
 If you are using facebook login, we suggest to use the users facebook ID here.
 Otherwise use whatever unique identifying string you have for the user.
 If you don't call this method we will use our randomly generated ID for each user.
 @param idString unique user identifying string
 */
+ (void)setUniqueIdForUser:(NSString *)idString __deprecated;

/**
 Deprecated.
 This function remains for backward compatability. It is now recommended to call this function from the Cintric.h file instead.
 Initialize Cintric with your API key and secret. This will also enable location updates.
 Call this method in application:didFinishLaunchingWithOptions:
 
 @discussion If you do not have a developer account register here: https://www.cintric.com/register
 If you do not know you api key / secret you can log in to find it here: https://www.cintric.com/login
 You can also contact our support: https://www.cintric.com/support
 Or email us directly at contact@cintric.com
 
 @param apiKey the apiKey you received when signing up for a developer account
 @param secret the secret key you received when signing up for a developer account
 */
+ (void)initWithApiKey:(NSString *)apiKey andSecret:(NSString *)secret __deprecated;

@end

//------------------------------------------------
// Delegate Protocol
//------------------------------------------------

@protocol CintricFindDelegate <NSObject>

@optional

/**
 This is called whenever the location is updated.
 
 @discussion Use this to do things like update your UI, or notify your server of the location change
             You should expect the location to be at its be
 st accuracy when this is called
 
 @param location CLLocation : the device's current location
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
 We recommend you ask the user to open settings and enable their location services
 */
- (void)locationServicesDenied;

@end
