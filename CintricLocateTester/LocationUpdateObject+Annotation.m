//
//  LocationUpdateObject+Annotation.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/12/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "LocationUpdateObject+Annotation.h"
#import "NSDate+ToString.h"

@implementation LocationUpdateObject (Annotation)

@dynamic coordinate;
@dynamic title;
@dynamic subtitle;

- (CLLocationCoordinate2D)coordinate
{
    return CLLocationCoordinate2DMake([self.latitude doubleValue], [self.longitude doubleValue]);
}

- (NSString *)title
{
    return [NSString stringWithFormat:@"%@, %@", self.latitude, self.longitude];
}

- (NSString *)subtitle
{
    return [NSString stringWithFormat:@"%@ : %@", [self.timestamp relativeDateStringShort], self.timestamp];
}

@end
