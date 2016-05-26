//
//  Orion1View.h
//  OrioniOSSDK
//
//  Created by Hannu Limma on 25.03.2015.
//  Copyright (c) 2015 Finwe Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 @enum TagVRControlState
 Tag VR Control state
 */
typedef NS_ENUM(NSUInteger, TagVRControlState) {
    /** When UI should hide viewfinder */
    VR_CONTROL_STATE_TAG_OFF = 0,
    /** When UI should show viewfinder */
    VR_CONTROL_STATE_TAG_INITIALIZED,
    /** When selecting progress starts for tag */
    VR_CONTROL_STATE_TAG_SELECTING,
    /** When selecting progress changes to unsecting for tag */
    VR_CONTROL_STATE_TAG_UNSELECTING,
    /** When tag selected */
    VR_CONTROL_STATE_TAG_SELECTED,
};

@protocol Orion1ViewDelegate;

/**
 *  Class Orion1View, provides simple OrionView for viewing 360 image or video.
 */
@interface Orion1View : UIView

/**
 *  Orion1View delegate.
 */
@property (nonatomic, weak) id <Orion1ViewDelegate> delegate;

/**
 *  Gesture mode disabled. When set YES, no gestures (panning etc.) can be used to
 *  control OrionContent internally. Default NO.
 */
@property (nonatomic) BOOL touchGesturesDisabled;

/**
 *  Sensors disabled. Turning the device rotates the view, the user is able "turn" in the video/image view. Uses the device gyroscope sensors to function. Default NO.
 */
@property (nonatomic) BOOL sensorsDisabled;

/**
 *  VR mode enabled. Divides view into two halves so that the video/image suitable for a HMD device, e.g. cardboard or googles. Default NO.
 */
@property (nonatomic) BOOL vrModeEnabled;

/**
 *  Device orientation portrait. Affects screen dividing in VR mode.
 *  If YES -> screen is divided to top and botton halves, else (NO, default) -> to left and right halves.
 */
@property (nonatomic) BOOL uiInterfaceOrientationPortrait;

/**
 *  Preview image mode. When set YES, Image from previewImageUrl or new texture generated from given video URL is shown
 *  in 360 video view. Default NO.
 */
@property (nonatomic) BOOL previewImageMode;

/**
 *  Volume level of video (0.0-1.0, min-max). Default 1.0.
 */
@property (nonatomic) CGFloat volume;

/**
 * Overrides iPhone's/iPad's silent switch. If YES -> silent switch does not mute video. Default NO.
 */
@property (nonatomic) BOOL overrideSilentSwitch;

/**
 * Inital diagonal fov (field of view) in degrees (60-120, min-max). Default 90.
 */
@property (nonatomic) CGFloat initialFov;

/**
 *  Current video total duration in seconds.
 */
@property (nonatomic, readonly) CGFloat totalDuration;


/**
 *  Initializes orion 360 video with given video url, preview image url and license file url.
 *
 *  @param videoUrl        Url to 360 video
 *  @param previewImageUrl Url to 360 preview image
 *  @param licenseFileUrl  Url to license file
 */
-(void)initVideoWithUrl:(NSURL*)videoUrl previewImageUrl:(NSURL*)previewImageUrl licenseFileUrl:(NSURL*)licenseFileUrl;

/**
 *  Initializes orion 360 image with given image url and license file url.
 *
 *  @param imageUrl        Url to 360 video
 *  @param licenseFileUrl  Url to license file
 */
-(void)initImageWithUrl:(NSURL*)imageUrl licenseFileUrl:(NSURL*)licenseFileUrl;

/**
 *  Initializes orion 360 image with given UIImage and license file url.
 *
 *  @param image           UIImage
 *  @param licenseFileUrl  Url to license file
 */
-(void)initImageWithUIImage:(UIImage*)image licenseFileUrl:(NSURL*)licenseFileUrl;

/**
 *  Plays 360 video starting from given location.
 *
 *  @param seekTo Given location in seconds
 */
-(void)play:(CGFloat)seekTo;

/**
 *  Plays 360 video.
 */
-(void)play;

/**
 *  Pauses 360 video.
 */
-(void)pause;

/**
 *  Returns true, if current 360 video playback is paused.
 *
 *  @return YES, if current video playback is paused, otherwise NO
 */
-(BOOL)isPaused;

/**
 *  Seeks 360 video to given location.
 *
 *  @param seekTo Given location in seconds
 */
-(void)seekTo:(CGFloat)seekTo;

/**
 *  Takes snapshot (UIImage) from 360 video or image with the flash.
 *
 *  @param flashStrength Flash strenght
 *
 *  @return Taken snapshot
 */
-(UIImage*)takeSnapshot:(NSInteger)flashStrength;

/**
 *  Creates tag with given tag index, Orion 360 content must be initialized before calling createTag
 *
 *  @param tagIndex Index number(>0) of tag, duplicates will be replaced
 */
-(void)createTag:(NSUInteger)tagIndex;

/**
 *  Removes tag with given tag index.
 *
 *  @param tagIndex Index number of tag
 */
-(void)removeTag:(NSUInteger)tagIndex;

/**
 *  Set image asset url to existing tag
 *
 *  @param tagIndex Index number of tag
 *  @param tagAssetURL  Url to image asset
 */
-(void)setTagAssetURL:(NSUInteger)tagIndex tagAssetURL:(NSURL*)tagAssetURL;

/**
 *  Set/change tag location to existing tag
 *
 *  @param tagIndex Index number of tag
 *  @param yawAngle     rotation around y-axis in degrees: -180(left), 0(center), +180(right)
 *  @param pitchAngle   rotation around x-axis in degrees: +90(top), 0(center), -90(bottom)
 */
-(void)setTagLocation:(NSUInteger)tagIndex yawAngle:(CGFloat)yawAngle pitchAngle:(CGFloat)pitchAngle;

/**
 *  Set/change tag scale, default value 1.0
 *
 *  @param tagIndex Index number of tag
 *  @param scale    scale factor
 */
-(void)setTagScale:(NSUInteger)tagIndex scale:(CGFloat)scale;


/**
 *  Set/change tag alpha, default value 1.0
 *
 *  @param tagIndex Index number of tag
 *  @param alpha    tag alpha
 */
-(void)setTagAlpha:(NSUInteger)tagIndex alpha:(CGFloat)alpha;

@end

/**
 *  Orion1ViewDelegate protocol defines the optional methods implemented by
 *  delegates of the Orion1View class.
 */
@protocol Orion1ViewDelegate
@optional

/**
 *  Tells the delegate that 360 video reached end.
 *
 *  @param orion1View Orion1View
 */
- (void)orion1ViewVideoDidReachEnd:(Orion1View*)orion1View;

/**
 *  Tells the delegate that 360 video is ready to be played.
 *
 *  @param orion1View Orion1View
 */
- (void)orion1ViewReadyToPlayVideo:(Orion1View*)orion1View;

/**
 *  Tells the delegate that video progress values were updated.
 *
 *  @param orion1View    Orion1View
 *  @param currentTime   Current progress time
 *  @param availableTime Available time
 *  @param totalDuration Total video duration
 */
- (void)orion1ViewDidUpdateProgress:(Orion1View*)orion1View currentTime:(CGFloat)currentTime availableTime:(CGFloat)availableTime totalDuration:(CGFloat)totalDuration;

/**
 *  Tells the delegate that video progress values were updated.
 *
 *  @param orion1View    Orion1View
 *  @param currentTime   Current progress time
 *  @param totalDuration Total video duration
 *  @param loadedTimeRanges This property provides a collection of time ranges for which the player has the media data readily available. The ranges provided might be discontinuous.
 */
- (void)orion1ViewDidUpdateProgress:(Orion1View*)orion1View currentTime:(CGFloat)currentTime totalDuration:(CGFloat)totalDuration loadedTimeRanges:(NSArray*)loadedTimeRanges;

/**
 *  Tells the delegate that 360 video buffering status changed.
 *
 *  @param orion1View Orion1View
 *  @param buffering  New buffering status
 */
- (void)orion1ViewDidChangeBufferingStatus:(Orion1View*)orion1View buffering:(BOOL)buffering;

/**
 *  Tells the delegate that user touched tag
 *
 *  @param orion1View   Orion1View
 *  @param tagIndex     Index of touched tag
 */
- (void)orion1ViewTagDidSelect:(Orion1View*)orion1View tagIndex:(NSUInteger)tagIndex;

/**
 *  Tells the delegate status changes of tag selection in vrmode
 *
 *  @param orion1View   Orion1View
 *  @param state        TagVRControlState
 *  @param tagIndex     Index of current tag
 */
- (void)orion1ViewTagDidChangeVRControlState:(Orion1View*)orion1View state:(TagVRControlState)state tagIndex:(NSUInteger)tagIndex;

@end
