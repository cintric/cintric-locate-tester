//
//  CintricUserProfile.h
//  Cintric SDK
//
//  Copyright (c) 2015 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 A class representing a user of your application. If you query for users with CintricAct, you will receive an array of CintricUserProfiles.
 You should also use the class methods of this class to set fields and sync information for the current user.
 It is highly recommended to set fields for you users if you have that information.
 You should always call updateFaceBookUser if you use facebook login. This will allow you to better view your users on the web panel.
 It will also help with demographics and profiling of users, making the rules engine, and demographic information much better.
 Any information you share will be securely stored, nerver shared and only accessible by you.
 */
@interface CintricUserProfile : NSObject

@property (strong, readonly) NSString *realName;
@property (strong, readonly) NSString *phoneNumber;
@property (strong, readonly) NSString *email;
@property (strong, readonly) NSString *customId;
@property (strong, readonly) NSString *cintricId;
@property (strong, readonly) NSString *facebookId;
@property (strong, readonly) id customJson;
@property (readonly) CLLocationCoordinate2D currentUserLocation;

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
 If you want to save additional custom information about your user, especially to view in the web panel, use this method.
 
 @param customJson A valid JSON object of type NSArray or NSDictionary.
 */
+ (void)setUserCustomJson:(id)customJson;

/**
 Automatically send information from facebook login to our server.
 It is highly recommended to call this method if you use facebook login. This information will be available to you in the web browser.
 All information is securely stored, never shared, and only available to you.
 
 When your user logs in with facebook, call this method with the id<FBGraphUser> object passed to you by the facebook sdk.
 
 @code
 - (void)loginViewFetchedUserInfo:(FBLoginView *)loginView user:(id<FBGraphUser>)user {
    [CintricUserProfile updateFaceBookUser:user];
 }
 @endcode
 
 @param fbGraphUser id<FBGraphUser> object from the facebook SDK.
 */
+ (void)updateFaceBookUser:(id)fbGraphUser;

/**
 Call this method at any time to enable address book sync.
 If your user has granted permission, or grants permission in the future, their address book will sync with our server.
 Using this method will allow you to view additional information about your users on the web panel.
 This greatly improves Cintric's ability to learn about who your users friends are, when, where, and for how long they spend time together.
 
 All information is securely stored, never shared, and only available to you.
 */
+ (void)syncAddresssBook;

@end
