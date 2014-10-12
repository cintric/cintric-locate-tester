//
//  ViewController.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/9/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "ViewController.h"
#import <Cintric/CintricLocate.h>

#import "LocationUpdateObject.h"

@interface ViewController () <CintricLocateDelegate>

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

#pragma mark - Cintric Delegate

- (void)didUpdateDeviceLocation:(CLLocation *)location
{

}


@end
