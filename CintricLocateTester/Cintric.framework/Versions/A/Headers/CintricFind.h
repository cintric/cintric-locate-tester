//
//  CintricFind.h
//  Cintric
//
//  Created by Joel Green on 11/17/15.
//  Copyright © 2015 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

@protocol CintricFindDelegate;

/// This class is deprecated, use Cintric.h
@interface CintricFind : NSObject

+ (void)setDelegate:(id <CintricFindDelegate>)delegateResponder;

+ (void)updateLocation;

+ (void)disableLocationUpdates;

+ (CLLocation *)getCurrentLocation;

+ (void)setDebug:(BOOL)loggingEnabled;

+ (void)setUniqueIdForUser:(NSString *)idString;

+ (void)initWithApiKey:(NSString *)apiKey andSecret:(NSString *)secret __deprecated_msg("Use [Cintric initWithSDKKey:andSecret:] instead. See Cintric header doc for more information.");;

- (void)didUpdateLocation:(CLLocation *)location;

@end

@protocol CintricFindDelegate <NSObject>

@optional

- (void)didUpdateDeviceLocation:(CLLocation *)location;

- (void)locationServicesAuthorized;

- (void)locationServicesRestricted;

- (void)locationServicesDenied;

@end
