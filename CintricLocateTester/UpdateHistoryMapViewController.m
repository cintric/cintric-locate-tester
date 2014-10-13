//
//  UpdateHistoryMapViewController.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/13/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "UpdateHistoryMapViewController.h"
#import "AppDelegate.h"
#import "LocationUpdateObject+Annotation.h"

@interface UpdateHistoryMapViewController()

@property (weak, nonatomic) IBOutlet MKMapView *mapView;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) NSMutableArray *mapAnnotations;

@end

@implementation UpdateHistoryMapViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self loadMapAnnotations];
}

- (void)loadMapAnnotations
{
    // Remove old annotations
    [self removeMapAnnotations:self.mapAnnotations];
    
    // Load the annotations from core data
    NSFetchRequest *request = [NSFetchRequest fetchRequestWithEntityName:@"LocationUpdateObject"];
    NSArray *annotations = [self.managedObjectContext executeFetchRequest:request error:nil];
    self.mapAnnotations = [[NSMutableArray alloc] initWithArray:annotations];
    
    // Add them to the map
    for (LocationUpdateObject *annotation in self.mapAnnotations) {
        [self.mapView addAnnotation:annotation];
    }
    
    // Move the map camera to view them
    [self.mapView showAnnotations:self.mapAnnotations animated:NO];
}

- (void)removeMapAnnotations:(NSArray *)annotations
{
    if ([annotations count]) {
        for (LocationUpdateObject *annotation in annotations) {
            [self.mapView removeAnnotation:annotation];
        }
    }
}

#pragma mark - Custom Setters / Getters

- (NSManagedObjectContext *)managedObjectContext
{
    if (!_managedObjectContext) {
        AppDelegate *delegate = [[UIApplication sharedApplication] delegate];
        _managedObjectContext = delegate.managedObjectContext;
    }
    return _managedObjectContext;
}

- (NSMutableArray *)mapAnnotations
{
    if (!_mapAnnotations) {
        _mapAnnotations = [[NSMutableArray alloc] init];
    }
    return _mapAnnotations;
}

@end
