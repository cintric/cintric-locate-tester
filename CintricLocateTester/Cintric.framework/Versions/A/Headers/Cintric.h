//
//  Cintric.h
//  Cintric SDK
//
//  This has all the public imports and initalizations methods
//
//  Copyright (c) 2015 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//------------------------------------------------
// Cintric Dependencies
//------------------------------------------------

#import <CoreLocation/CoreLocation.h>
#import <CoreData/CoreData.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <SystemConfiguration/SystemConfiguration.h>

//------------------------------------------------
// Cintric Imports
//------------------------------------------------

#import <Cintric/CintricPublicConstants.h>
#import <Cintric/CintricDelegate.h>
#import <Cintric/CintricVisit.h>

//------------------------------------------------
// For Backwards Compatability
//------------------------------------------------

#import <Cintric/CintricFind.h>

//------------------------------------------------
// Cintric Class Interface
//------------------------------------------------
@interface Cintric : NSObject

/**
 Initialize Cintric with your SDK key and secret.
 Call this method in application:didFinishLaunchingWithOptions:

 @discussion If you do not have a developer account register here: https://www.cintric.com/register
             If you do not know you sdk key / secret you can log in to find it here: https://www.cintric.com/login
             You can also contact our support: https://www.cintric.com/support
             Or email us directly at contact@cintric.com
 
 @param sdkKey the sdkKey you received when signing up for a developer account
 @param secret the secret key you received when signing up for a developer account
 */
+ (void)initWithSDKKey:(NSString *)sdkKey andSecret:(NSString *)secret;

/**
 Call this method when you are ready to ask your user for location permission.
 This will enable Cintric's always on visit tracking. You will receive callbacks from the delegate method didVisit:
 You should also get callbacks to didUpdateLocation: on launch.
 If your application provides functionality based on the background location tracking, you should enable legacy mode.
 @code
    [Cintric setLegacyLocationTrackingEnabled:YES];
 @endcode
 */
+ (void)startAlwaysModeAndRequestPermission;

/**
 Cintric always mode will by default track user visits and build user profile / analytics for you in the dashboard.
 If you need location tracking with callbacks in real time and for intermediary locations enable this method.
 Note that this will slightly increase battery impact (usually still less than 1% per day though).
 
 @param enabled Bool specifying if you should turn legacy mode on or off.
 */
+ (void)setLegacyLocationTrackingEnabled:(BOOL)enabled;

/**
 Call this method if you want a gps location update at any time.
 The cintric delegate method didUpdateLocation will be called once the user's location has been determined.
 */
+ (void)updateLocation;

/**
 This method has the same behavior as updateLocation. However, in addition to the delegate callback,
 a completion block is called with a CLLocation, useful if you want to quickly get the location in some class
 without setting a delegate.
 
 @param completionBlock a block that passes a CLLocation
 */
+ (void)updateLocationWithCompletion:(cintricDidUpdateLocation)completionBlock;

/**
 Call this method if for some reason you no longer want location tracking enabled.
 Call startAlwaysModeAndRequestPermission to re-enable.
 */
+ (void)disableLocationUpdates;

/**
 Get the users current location.
 
 @return CLLocation of the users current locaiton
 */
+ (CLLocation *)getCurrentLocation;

/// Call this to disable non-critical cintric NSLog statements
+ (void)setDebug:(BOOL)loggingEnabled;

/// Set the delegate for cintric delegate callbacks.
+ (void)setDelegate:(id <CintricDelegate>)delegateResponder;

//------------------------------------------------
// Cintric User Data Methods
//------------------------------------------------
# pragma mark - User Data Methods

/// Set the real name of the current user.
+ (void)setUserRealName:(NSString *)realName;

/// Set the phone number of your current user.
+ (void)setUserPhoneNumber:(NSString *)phoneNumber;

/// Set the email of your current user.
+ (void)setUserEmail:(NSString *)email;

/// Set a custom unique id for your user, this can be used to match users in your database with our database.
+ (void)setUserCustomId:(NSString *)customId;

/// If you know the facebook id of your user, but dont use facebook login call this method.
+ (void)setUserFacebookId:(NSString *)facebookId;

/**
 Automatically send information from facebook login to our server.
 It is highly recommended to call this method if you use facebook login. This information will be available to you in the web browser.
 All information is securely stored for your use.
 
 When your user logs in with facebook, call this method with the id<FBGraphUser> object passed to you by the facebook sdk.
 
 @code
 - (void)loginViewFetchedUserInfo:(FBLoginView *)loginView user:(id<FBGraphUser>)user {
 [Cintric updateFaceBookUser:user];
 }
 @endcode
 
 @param fbGraphUser id<FBGraphUser> object from the facebook SDK.
 */
+ (void)updateFaceBookUser:(id)fbGraphUser;

/**
 This method is deprecated. Call initWithSDKKey:andSecret: instead. Cintric now tracks visits and will only call didUpdateLocation on launch by default.
 If you use the cintric location tracking for app functionality, call setLegacyLocationTrackingEnabled:YES.
 */
+ (void)initWithApiKey:(NSString *)apiKey andSecret:(NSString *)secret __deprecated_msg("Use initWithSDKKey:andSecret: instead. See methods header doc for more information.");

@end