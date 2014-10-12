//
//  LocationUpdateObject+Handler.h
//  CintricLocateTester
//
//  Created by Joel Green on 10/12/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "LocationUpdateObject.h"

@interface LocationUpdateObject (Handler)

+ (LocationUpdateObject *)updateObjectForLat:(float)lat lon:(float)lon;

@end
