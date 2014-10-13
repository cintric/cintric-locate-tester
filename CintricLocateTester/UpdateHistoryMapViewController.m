//
//  UpdateHistoryMapViewController.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/13/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "UpdateHistoryMapViewController.h"
#import "AppDelegate.h"

@interface UpdateHistoryMapViewController()

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end

@implementation UpdateHistoryMapViewController


#pragma mark - Custom Setters / Getters

- (NSManagedObjectContext *)managedObjectContext
{
    if (!_managedObjectContext) {
        AppDelegate *delegate = [[UIApplication sharedApplication] delegate];
        _managedObjectContext = delegate.managedObjectContext;
    }
    return _managedObjectContext;
}

@end
