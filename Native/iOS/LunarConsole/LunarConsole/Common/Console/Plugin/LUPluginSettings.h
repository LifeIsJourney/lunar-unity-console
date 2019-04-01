//
//  LUPluginSettings.h
//  LunarConsole
//
//  Created by Alex Lementuev on 3/15/19.
//  Copyright © 2019 Space Madness. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const LUNotificationSettingsDidChange;

typedef enum : NSUInteger {
	LUDisplayModeNone,
	LUDisplayModeErrors,
	LUDisplayModeExceptions,
	LUDisplayModeAll
} LUDisplayMode;

@interface LUExceptionWarningSettings : NSObject<NSCoding>

@property (nonatomic, assign) LUDisplayMode displayMode;

/** Constructs instance from a JSON-dictionary */
- (nullable instancetype)initWithDictionary:(NSDictionary *)dict;

@end

@interface LUColor : NSObject<NSCoding>

@property (nonatomic, assign) UInt8 r;
@property (nonatomic, assign) UInt8 g;
@property (nonatomic, assign) UInt8 b;
@property (nonatomic, assign) UInt8 a;
@property (nonatomic, readonly) UIColor *UIColor;

/** Constructs instance from a JSON-dictionary */
- (nullable instancetype)initWithDictionary:(NSDictionary *)dict;

@end

@interface LULogEntryColors : NSObject<NSCoding>

@property (nonatomic, strong) LUColor *foreground;
@property (nonatomic, strong) LUColor *background;

/** Constructs instance from a JSON-dictionary */
- (nullable instancetype)initWithDictionary:(NSDictionary *)dict;

@end

@interface LULogColors : NSObject<NSCoding>

@property (nonatomic, strong) LULogEntryColors *exception;
@property (nonatomic, strong) LULogEntryColors *error;
@property (nonatomic, strong) LULogEntryColors *warning;
@property (nonatomic, strong) LULogEntryColors *debug;

/** Constructs instance from a JSON-dictionary */
- (nullable instancetype)initWithDictionary:(NSDictionary *)dict;

@end

@interface LULogOverlaySettings : NSObject<NSCoding>

/** Indicates if log overlay is enabled. */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/** Max number of simultaneously visible lines. */
@property (nonatomic, assign) NSUInteger maxVisibleLines;

/** Delay in seconds before each line disappears (<code>0</code> means never disappear) */
@property (nonatomic, assign) NSTimeInterval timeout;

/** Indicates if the line background should be transparent. */
@property (nonatomic, strong) LULogColors *colors;

/** Constructs instance from a JSON-dictionary */
- (nullable instancetype)initWithDictionary:(NSDictionary *)dict;

@end

typedef enum : NSUInteger {
	LUConsoleGestureNone,
	LUConsoleGestureSwipeDown
} LUConsoleGesture;

/** Global settings from Unity editor. */
@interface LUPluginSettings : NSObject<NSCoding>

/** Exception warning settings. */
@property (nonatomic, strong) LUExceptionWarningSettings *exceptionWarning;

/** Log overlay settings */
@property (nonatomic, strong) LULogOverlaySettings *logOverlay;

/** Log output would not grow bigger than this capacity. */
@property (nonatomic, assign) NSUInteger capacity;

/** Log output will be trimmed this many lines when overflown. */
@property (nonatomic, assign) NSUInteger trim;

/** Gesture type to open the console. */
@property (nonatomic, assign) LUConsoleGesture gesture;

/** Indicates if reach text tags should be ignored. */
@property (nonatomic, assign) BOOL removeRichTextTags;

/** Indicates if actions should be sorted. */
@property (nonatomic, assign) BOOL sortActions;

/** Indicates if variables should be sorted. */
@property (nonatomic, assign) BOOL sortVariables;

/** Optional list of the email recipients for sending a report. */
@property (nonatomic, strong) NSArray<NSString *> *emails;

/** Constructs instance from a JSON-dictionary */
- (nullable instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END