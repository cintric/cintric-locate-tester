//
//  LocationUpdateObject+Annotation.h
//  CintricLocateTester
//
//  Created by Joel Green on 10/12/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "LocationUpdateObject.h"
#import <MapKit/MapKit.h>

@interface LocationUpdateObject (Annotation)

@property (nonatomic) CLLocationCoordinate2D coordinate;
@property (copy, nonatomic) NSString *title;
@property (copy, nonatomic) NSString *subtitle;

@end
