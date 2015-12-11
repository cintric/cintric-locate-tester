//
//  CintricDelegate.h
//  Cintric
//
//  Created by Joel Green on 11/10/15.
//  Copyright © 2015 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "CintricVisit.h"

@protocol CintricDelegate <NSObject>

@optional

/**
 This is called when a user visits a location.
 
 @param visit CintricVisit object representing a visit to a particular location.
 */
- (void)didVisit:(CintricVisit *)visit;

/**
 This is called whenever the location is updated.
 
 @discussion Use this to do things like update your UI, or notify your server of the location change
 You should expect the location to be at its be
 st accuracy when this is called
 
 @param location CLLocation : the device's current location
 */
- (void)didUpdateLocation:(CLLocation *)location;

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
