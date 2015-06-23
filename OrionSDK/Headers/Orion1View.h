//
//  Orion1View.h
//  OrioniOSSDK
//
//  Created by Hannu Limma on 25.03.2015.
//  Copyright (c) 2015 Finwe Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>


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
 *  Tells the delegate that 360 video buffering status changed.
 *
 *  @param orion1View Orion1View
 *  @param buffering  New buffering status
 */
- (void)orion1ViewDidChangeBufferingStatus:(Orion1View*)orion1View buffering:(BOOL)buffering;

@end
