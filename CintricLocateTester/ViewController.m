//
//  ViewController.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/9/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "ViewController.h"
#import <Cintric/CintricLocate.h>
#import <MapKit/MapKit.h>

#import "LocationUpdateObject+Handler.h"

@interface ViewController () <CintricLocateDelegate>

// From storyboard
@property (weak, nonatomic) IBOutlet MKMapView *mapView;
@property (weak, nonatomic) IBOutlet UIButton *updateLocationButton;

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

#pragma mark - Storyboard actions

- (IBAction)updateLocationButtonPressed:(id)sender
{
    
}

#pragma mark - Cintric Delegate

- (void)didUpdateDeviceLocation:(CLLocation *)location
{
    // Create a core data object for this update
    [LocationUpdateObject updateObjectForLat:location.coordinate.latitude lon:location.coordinate.longitude];
}


@end
