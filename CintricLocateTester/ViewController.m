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

@property (strong, nonatomic) LocationUpdateObject *currentLocationAnnotation;

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
    self.currentLocationAnnotation = [LocationUpdateObject updateObjectForLat:location.coordinate.latitude lon:location.coordinate.longitude inContext:self.managedObjectContext];
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

/// This removes the previous annotation from the map, and adds the new one
- (void)setCurrentLocationAnnotation:(LocationUpdateObject *)currentLocationAnnotation
{
    if (_currentLocationAnnotation) {
        [self.mapView removeAnnotation:_currentLocationAnnotation];
    }
    _currentLocationAnnotation = currentLocationAnnotation;
    [self addMarkerToMapView:_currentLocationAnnotation];
}

@end
