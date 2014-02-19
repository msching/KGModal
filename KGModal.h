//
//  KGModal.h
//  KGModal
//
//  Created by David Keegan on 10/5/12.
//  Copyright (c) 2012 David Keegan. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString *const KGModalWillShowNotification;
extern NSString *const KGModalDidShowNotification;
extern NSString *const KGModalWillHideNotification;
extern NSString *const KGModalDidHideNotification;

typedef NS_ENUM(NSUInteger, KGModalBackgroundDisplayStyle){
    KGModalBackgroundDisplayStyleGradient,
    KGModalBackgroundDisplayStyleSolid
};

typedef NS_ENUM(NSUInteger, KGModalCloseButtonType){
    KGModalCloseButtonTypeNone,
    KGModalCloseButtonTypeLeft,
    KGModalCloseButtonTypeRight
};

typedef NS_ENUM(NSUInteger, KGModalContentPosition){
    KGModalContentPositionCenter,
    KGModalContentPositionTop
};

@interface KGModal : NSObject

// Determines if the modal should dismiss if the user taps outside of the modal view
// Defaults to YES
@property (nonatomic) BOOL tapOutsideToDismiss;

// Determines if the close button or tapping outside the modal should animate the dismissal
// Defaults to YES
@property (nonatomic) BOOL animateWhenDismissed;

// Determins close button type (None/Left/Right)
// Defaults to Left
@property (nonatomic) KGModalCloseButtonType closeButtonType;

// The background color of the modal window
// Defaults black with 0.5 opacity
@property (strong, nonatomic) UIColor *modalBackgroundColor;

// Determines if the modal should show border
// Defaults to YES
@property (nonatomic) BOOL bordered;

// The background display style, can be a transparent radial gradient or a transparent black
// Defaults to gradient, this looks better but takes a bit more time to display on the retina iPad
@property (nonatomic) KGModalBackgroundDisplayStyle backgroundDisplayStyle;

// The content display top margin on portrait, working for contentPositionTop only
// Defaults to 0
@property (nonatomic) CGFloat contentPortraitTopMargin;

// The content display top margin on landscape, working for contentPositionTop only
// Defaults to 0
@property (nonatomic) CGFloat contentLandscapeTopMargin;

// The content display position
// Defaults to center
@property (nonatomic) KGModalContentPosition contentPosition;

// Determines if the modal should rotate when the device rotates
// Defaults to YES, only applies to iOS5
@property (nonatomic) BOOL shouldRotate;

// The shared instance of the modal
+ (instancetype)sharedInstance;

// Set the content view to display in the modal and display with animations
- (void)showWithContentView:(UIView *)contentView;

// Set the content view to display in the modal and display with animations,
// run the completion after the modal is shown
- (void)showWithContentView:(UIView *)contentView withCompletionBlock:(void(^)())completion;

// Set the content view to display in the modal and whether the modal should animate in
- (void)showWithContentView:(UIView *)contentView animated:(BOOL)animated withCompletionBlock:(void(^)())completion;

// Set the content view controller to display in the modal and display with animations
- (void)showWithContentViewController:(UIViewController *)contentViewController;

// Set the content view controller to display in the modal and display with animations,
// run the completion after the modal is shown
- (void)showWithContentViewController:(UIViewController *)contentViewController withCompletionBlock:(void(^)())completion;

// Set the content view controller to display in the modal and whether the modal should animate in
- (void)showWithContentViewController:(UIViewController *)contentViewController animated:(BOOL)animated withCompletionBlock:(void(^)())completion;

// Hide the modal with animations
- (void)hide;

// Hide the modal with animations,
// run the completion after the modal is hidden
- (void)hideWithCompletionBlock:(void(^)())completion;

// Hide the modal and whether the modal should animate away
- (void)hideAnimated:(BOOL)animated;

// Hide the modal and whether the modal should animate away,
// run the completion after the modal is hidden
- (void)hideAnimated:(BOOL)animated withCompletionBlock:(void(^)())completion;

@end
