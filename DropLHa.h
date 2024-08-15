/* DropLHa */

#import <Cocoa/Cocoa.h>
#import "AMShellWrapper.h"

enum _appStatus { WAITING, RUNNING };

@interface DropLHa : NSObject <AMShellWrapperController>
{
    IBOutlet id taskWindow;		// Window
    IBOutlet id taskIndicator;		// progress bar in Window
    IBOutlet id remCountText;		// text box in Window
    IBOutlet id extItemText;		// text box in Window
    IBOutlet id prefWindow;		// Preference Window
    IBOutlet id methodPopup;		// popup in prefWindow
    IBOutlet id headerPopup;		// popup in prefWindow
    IBOutlet id noQuitToggle;		// toggle button in prefWindow
    IBOutlet id taskPerItemToggle;	// toggle button in prefWindow
    IBOutlet id hiddenFileToggle;	// toggle button in prefWindow
    IBOutlet id destRadio;		// radio button in prefWindow
    IBOutlet id destText;		// text box in prefWindow
    
    BOOL storeHiddenFile;		// if YES, include dot-file
    BOOL quitAfterTask;			// if YES, quit after finishing task
    BOOL doTaskAtOnce;			// if NO, include only one item
    NSMutableArray *targetItem;		// dropped or selected items
    AMShellWrapper *theTask;		// instance of task
    enum _appStatus appStatus;		// status of application
    int droppedItemCount;		// number of dropped items
    BOOL shouldQuit;			// flag for auto-quit
}

// call when "Open..." menu are selected
- (IBAction) openMenuSelected : (id)sender;
// call when "Preferences..." menu are selected
- (IBAction) prefMenuSelected:(id)sender;
// call when "Stop" button in taskWindow are clicked
- (IBAction) stopClicked : (id) sender;
// call when "OK" button in prefWindow are clicked
- (IBAction) prefOkClicked : (id) sender;
// call when "Cancel" button in prefWindow are clicked
- (IBAction) prefCancelClicked : (id) sender;
// call when "Select" button in prefWindow are clicked
- (IBAction) destSelectClicked : (id) sender;

// return lha's path
- (NSString *) getLhaPath;
// return lha's option
- (NSString *) getLhaOption;
// return destination path
- (NSString *) getDestination;
// ask destination path
- (NSString *) askDestination;
// check destination
- (BOOL) checkDestination : (NSString *) aPath;
// return output file path
- (NSString *) getArchiveName : (NSString *) aDestination;
// load preference plist
- (void) loadPreferences;
// save preference plist
- (void) savePreferences;
// execute command
- (void) doTask;
// stop command
- (void) stopTask;
@end
