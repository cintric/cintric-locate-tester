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
// Public Cintric Imports
//------------------------------------------------
#import <Cintric/CintricFind.h>
#import <Cintric/CintricAct.h>
#import <Cintric/CintricUserProfile.h>

#import <CoreData/CoreData.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <AddressBook/AddressBook.h>

//------------------------------------------------
// Cintric Class Interface
//------------------------------------------------
@interface Cintric : NSObject

/**
 Initialize Cintric with your API key and secret.
 Call this method in application:didFinishLaunchingWithOptions:

 @discussion If you do not have a developer account register here: https://www.cintric.com/register
             If you do not know you api key / secret you can log in to find it here: https://www.cintric.com/login
             You can also contact our support: https://www.cintric.com/support
             Or email us directly at contact@cintric.com
 
 @param apiKey the apiKey you received when signing up for a developer account
 @param secret the secret key you received when signing up for a developer account
 */
+ (void)initWithApiKey:(NSString *)apiKey andSecret:(NSString *)secret;

@end