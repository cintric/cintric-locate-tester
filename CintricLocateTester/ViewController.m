//
//  ViewController.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/9/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"
#import <Cintric/CintricLocate.h>
#import <MapKit/MapKit.h>

#import "LocationUpdateObject+Handler.h"
#import "LocationUpdateObject+Annotation.m"

@interface ViewController () <CintricLocateDelegate>

// From storyboard
@property (weak, nonatomic) IBOutlet MKMapView *mapView;
@property (weak, nonatomic) IBOutlet UIButton *updateLocationButton;

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [CintricLocate setDelegate:self];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)addMarkerToMapView:(id <MKAnnotation>)annotation
{
    [self.mapView setRegion:MKCoordinateRegionMakeWithDistance(annotation.coordinate, 500, 500)];
    [self.mapView addAnnotation:annotation];
}

#pragma mark - Storyboard actions

- (IBAction)updateLocationButtonPressed:(id)sender
{
    [CintricLocate updateLocation];
}

#pragma mark - Cintric Delegate

- (void)didUpdateDeviceLocation:(CLLocation *)location
{
    // Create a core data object for this update
    LocationUpdateObject *update = [LocationUpdateObject updateObjectForLat:location.coordinate.latitude lon:location.coordinate.longitude inContext:self.managedObjectContext];
    [self addMarkerToMapView:update];
}

- (NSManagedObjectContext *)managedObjectContext
{
    if (!_managedObjectContext) {
        AppDelegate *delegate = [[UIApplication sharedApplication] delegate];
        _managedObjectContext = delegate.managedObjectContext;
    }
    return _managedObjectContext;
}


@end
