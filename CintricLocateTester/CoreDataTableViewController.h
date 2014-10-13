//
//  CoreDataTableViewController.h
//


#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface CoreDataTableViewController : UITableViewController <NSFetchedResultsControllerDelegate>

// The controller (this class fetches nothing if this is not set).
@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;

- (void)performFetch;

// Set to YES to get some debugging output in the console.
@property BOOL debug;

@property UITableViewRowAnimation rowAnimationType;

@end
