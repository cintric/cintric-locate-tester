//
//  NSDate+ToString.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/13/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "NSDate+ToString.h"

@implementation NSDate (ToString)

- (NSString *)relativeDateStringShort
{
    NSCalendarUnit units = NSCalendarUnitSecond | NSCalendarUnitMinute | NSCalendarUnitHour | NSCalendarUnitDay | NSCalendarUnitWeekOfYear |
    NSCalendarUnitMonth | NSCalendarUnitYear;
    
    // if `date` is before "now" (i.e. in the past) then the components will be positive
    NSDateComponents *components = [[NSCalendar currentCalendar] components:units
                                                                   fromDate:self
                                                                     toDate:[NSDate date]
                                                                    options:0];
    
    if (components.year > 0) {
        return [NSString stringWithFormat:@"%ldy", (long)components.year];
    } else if (components.month > 0) {
        return [NSString stringWithFormat:@"%ldmo", (long)components.month];
    } else if (components.weekOfYear > 0) {
        return [NSString stringWithFormat:@"%ldw", (long)components.weekOfYear];
    } else if (components.day > 0) {
        return [NSString stringWithFormat:@"%ldd", (long)components.day];
    } else if (components.hour > 0) {
        return [NSString stringWithFormat:@"%ldh", (long)components.hour];
    } else if (components.minute > 0) {
        return [NSString stringWithFormat:@"%ldm", (long)components.minute];
    } else if (components.second > 2) {
        return [NSString stringWithFormat:@"%lds", (long)components.second];
    } else {
        return @"Now";
    }
}

@end
