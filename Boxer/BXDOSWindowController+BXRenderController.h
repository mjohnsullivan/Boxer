/* 
 Boxer is copyright 2009 Alun Bestor and contributors.
 Boxer is released under the GNU General Public License 2.0. A full copy of this license can be
 found in this XCode project at Resources/English.lproj/GNU General Public License.txt, or read
 online at [http://www.gnu.org/licenses/gpl-2.0.txt].
 */


//The BXRenderController category separates off rendering-specific functionality from general
//window controller housework. The methods herein pass frame rendering on to the rendering view,
//and manage window size and fullscreen mode.

#import <Cocoa/Cocoa.h>
#import "BXDOSWindowController.h"

@class BXDOSWindow;
@class BXEmulator;
@class BXFrameBuffer;

@interface BXDOSWindowController (BXRenderController)

#pragma mark -
#pragma mark Renderer-related methods

- (void) updateWithFrame: (BXFrameBuffer *)frame;
- (NSSize) maxFrameSize;
- (NSSize) viewportSize;


#pragma mark -
#pragma mark Window-sizing and fullscreen methods

//Returns YES if the window is in the process of resizing itself.
- (BOOL) isResizing;

//Sets the window to use the specified frame-autosave name, and adjusts the resulting
//frame to ensure the aspect ratio is consistent with what it was before.
- (void) setFrameAutosaveName: (NSString *)savedName;

//Returns the size that the rendering view would currently be *if it were in windowed mode.*
//This will differ from the actual render view size if in fullscreen mode.
- (NSSize) windowedRenderingViewSize;

//Switch to and from fullscreen mode instantly with no animation.
- (void) setFullScreen: (BOOL)fullScreen;

//Zoom in and out of fullscreen mode with a smooth window sizing animation.
- (void) setFullScreenWithZoom: (BOOL) fullScreen;

//Whether the rendering view is currently fullscreen.
- (BOOL) isFullScreen;

//The screen which we will render to in fullscreen mode.
- (NSScreen *) fullScreenTarget;

@end