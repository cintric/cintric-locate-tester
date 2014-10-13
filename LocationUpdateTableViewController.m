//
//  LocationUpdateTableViewController.m
//  CintricLocateTester
//
//  Created by Joel Green on 10/13/14.
//  Copyright (c) 2014 Joel Green. All rights reserved.
//

#import "LocationUpdateTableViewController.h"
#import "AppDelegate.h"
#import "LocationUpdateObject+Annotation.h"

@interface LocationUpdateTableViewController ()

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end

@implementation LocationUpdateTableViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [self loadContext];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Location Update Cell" forIndexPath:indexPath];
    
    LocationUpdateObject *locationUpdate = [self.fetchedResultsController objectAtIndexPath:indexPath];
    
    cell.textLabel.text = locationUpdate.title;
    cell.detailTextLabel.text = locationUpdate.subtitle;
    
    return cell;
}

- (NSManagedObjectContext *)loadContext
{
    if (!self.managedObjectContext) {
        AppDelegate *delegate = [[UIApplication sharedApplication] delegate];
        self.managedObjectContext = delegate.managedObjectContext;
    }
    return self.managedObjectContext;
}

- (void)setManagedObjectContext:(NSManagedObjectContext *)managedObjectContext
{
    _managedObjectContext = managedObjectContext;
    
    NSFetchRequest *request = [NSFetchRequest fetchRequestWithEntityName:@"LocationUpdateObject"];
    request.sortDescriptors = @[[NSSortDescriptor sortDescriptorWithKey:@"timestamp" ascending:YES]];
    
    self.fetchedResultsController = [[NSFetchedResultsController alloc] initWithFetchRequest:request
                                                                        managedObjectContext:managedObjectContext
                                                                          sectionNameKeyPath:nil
                                                                                   cacheName:nil];
}

@end
