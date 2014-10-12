//
//  LocationUpdateObject+Annotation.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/12/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "LocationUpdateObject+Annotation.h"

@implementation LocationUpdateObject (Annotation)

@dynamic coordinate;
@dynamic title;
@dynamic subtitle;

- (CLLocationCoordinate2D)coordinate
{
    return CLLocationCoordinate2DMake([self.latitude doubleValue], [self.longitude doubleValue]);
}

@end
