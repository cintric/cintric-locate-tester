//
//  NSDate+ToString.h
//  CintricLocateTester
//
//  Created by Joel Green on 10/13/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (ToString)

/**
 Turns date into a string such as @"2d" @"6m" @"3s" @"8mo" @"5y" relative to how long ago the date was
 @returns string representing the time since the date
 */
- (NSString *)relativeDateStringShort;

@end
