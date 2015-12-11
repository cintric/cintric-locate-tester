//
//  CintricUserProfile.h
//  Cintric
//
//  Created by Joel Green on 11/17/15.
//  Copyright © 2015 Cintric. All rights reserved.
//

#import <Foundation/Foundation.h>

/// This class is deprecated, use Cintric.h
@interface CintricUserProfile : NSObject

+ (void)setUserRealName:(NSString *)realName;

+ (void)setUserPhoneNumber:(NSString *)phoneNumber;

+ (void)setUserEmail:(NSString *)email;

+ (void)setUserCustomId:(NSString *)customId;

+ (void)setUserFacebookId:(NSString *)facebookId;

+ (void)setUserAdvertisingIdentifier:(NSString *)adId;

+ (void)setUserCustomJson:(id)customJson;

+ (void)updateFaceBookUser:(id)fbGraphUser;

+ (void)syncAddresssBook;

@end
