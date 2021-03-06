// Copyright (C) 2011-2012 by Tapjoy Inc.
//
// This file is part of the Tapjoy SDK.
//
// By using the Tapjoy SDK in your software, you agree to the terms of the Tapjoy SDK License Agreement.
//
// The Tapjoy SDK is bound by the Tapjoy SDK License Agreement and can be found here: https://www.tapjoy.com/sdk/license


/*! \mainpage Tapjoy iOS SDK
 *
 * The Tapjoy iOS SDK.
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIkit.h>



#define TJC_LIBRARY_VERSION_NUMBER			@"8.2.2"				/*!< The SDK version number. */

#define TJC_SERVICE_URL						@"https://ws.tapjoyads.com/"
#define TJC_SERVICE_URL_ALTERNATE			@"https://ws1.tapjoyads.com/"
#define TJC_TAPJOY_HOST_NAME				@"ws.tapjoyads.com"
#define TJC_TAPJOY_ALT_HOST_NAME			@"ws1.tapjoyads.com"

#define TJC_LINKSHARE_HOST_NAME				@"click.linksynergy.com"
#define TJC_UDID							@"udid"					/*!< The unique device identifier. Deprecated in iOS 5. */
#define TJC_ADVERTISER_ID					@"advertiser_id"		/*!< The advertiser ID. Available on iOS6 and above. */
#define TJC_UNIQUE_MAC_ID					@"mac_address"			/*!< The unique ID retrieved by taking the hash of mac address. */
#define TJC_UNIQUE_MAC_ID_SHA1				@"sha1_mac_address"		/*!< The SHA1 has of the mac address (uppercase, colon separated) */
#define TJC_OPEN_UDID						@"open_udid"			/*!< The Open UDID. */
#define TJC_OPEN_UDID_COUNT					@"open_udid_count"		/*!< The Open UDID slot count. */
#define TJC_DEVICE_NAME						@"device_name"			/*!< This is the specific device name ("iPhone1,1", "iPod1,1"...) */
#define TJC_DEVICE_TYPE_NAME				@"device_type"			/*!< The model name of the device. This is less descriptive than the device name. */
#define TJC_DEVICE_OS_VERSION_NAME			@"os_version"			/*!< The device system version. */
#define TJC_DEVICE_COUNTRY_CODE				@"country_code"			/*!< The country code is retrieved from the locale object, from user data (not device). */
#define TJC_DEVICE_LANGUAGE					@"language_code"		/*!< The language is retrieved from the locale object, from user data (not device). */
#define TJC_DEVICE_LAD						@"lad"					/*!< Little Alien Dude. */
#define TJC_APP_ID_NAME						@"app_id"				/*!< The application id is set by the developer, and is a unique id provided by Tapjoy. */
#define TJC_APP_VERSION_NAME				@"app_version"			/*!< The application version is retrieved from the application plist file, from the bundle version. */
#define TJC_CONNECT_LIBRARY_VERSION_NAME	@"library_version"		/*!< The library version is the SDK version number. */	
#define TJC_VERIFIER						@"verifier"				/*!< A hashed value that is verified on the server to confirm a valid connect. */
#define TJC_TIMESTAMP						@"timestamp"			/*!< The time in seconds when a connect call is made. */
#define TJC_GUID							@"guid"					/*!< Used as part of the verifier. */
#define TJC_CARRIER_NAME					@"carrier_name"			/*!< The name of the user’s home cellular service provider. */
#define TJC_ALLOWS_VOIP						@"allows_voip"			/*!< Indicates if the carrier allows VoIP calls to be made on its network. */
#define TJC_CARRIER_COUNTRY_CODE			@"carrier_country_code"	/*!< The ISO country code for the user’s cellular service provider. */
#define TJC_MOBILE_COUNTRY_CODE				@"mobile_country_code"	/*!< The mobile country code (MCC) for the user’s cellular service provider. */
#define TJC_MOBILE_NETWORK_CODE				@"mobile_network_code"	/*!< The mobile network code (MNC) for the user’s cellular service provider. */
#define TJC_PLATFORM						@"platform"				/*!< The name of the platform. */
#define TJC_PLATFORM_IOS					@"iOS"					/*!< The parameter value of the platform. */
#define TJC_PLUGIN							@"plugin"				/*!< The plugin being used, if any. */
#define TJC_PLUGIN_NATIVE					@"native"				/*!< The default value for the plugin parameter, native means not a plugin. */
#define TJC_SDK_TYPE						@"sdk_type"				/*!< The type of SDK, advertiser, publisher, virtual goods, etc. */
#define TJC_URL_PARAM_USER_ID				@"publisher_user_id"	/*!< The user ID. */
// NOTE: This doesn't actually affect currency earned, just the value displayed on the offer wall.
#define TJC_URL_PARAM_CURRENCY_MULTIPLIER	@"display_multiplier"	/*!< Currency multiplier value. */
#define TJC_CONNECTION_TYPE_NAME			@"connection_type"		/*!< The type of data connection that is being used. */
#define TJC_PACKAGE_NAMES					@"package_names"		/*!< Comma separated advertiser URL schemes. */

#define TJC_CONNECT_API						@"connect"				/*!< API for Tapjoy connect. */
#define TJC_SET_USER_ID_API					@"set_publisher_user_id"/*!< API for setting publisher user id. */
#define TJC_SDK_LESS_CONNECT_API			@"apps_installed"		/*!< API for passing advertiser apps. */

#define TJC_PASTEBOARD_SLOT_MAX				256
#define TJC_PASTEBOARD_TYPE					@"public.plain-text" //@"com.tapjoy"
#define TJC_PASTEBOARD_SLOT_PREFIX			@"com.tapjoy.slot."
#define TJC_TAPJOY_UUID						@"TJC_TAPJOY_UUID"

// Event tracking API
#define TJC_EVENT_TRACKING_API				@"user_events"
#define TJC_URL_PARAM_EVENT_TYPE			@"event_type_id"

enum TJCConnectionType
{
	TJC_CONNECT_TYPE_CONNECT = 0,
	TJC_CONNECT_TYPE_ALT_CONNECT,
	TJC_CONNECT_TYPE_USER_ID,
	TJC_CONNECT_TYPE_SDK_LESS,
  	TJC_CONNECT_TYPE_EVENT_SHUTDOWN,
	TJC_CONNECT_TYPE_MAX
};


/*!	\interface TapjoyConnect
 *	\brief The Tapjoy Connect Main class.
 *
 */
@interface TapjoyConnect :  NSObject
{
@private
	NSString *appID_;					/*!< The application ID unique to this app. */
	NSString *secretKey_;				/*!< The Tapjoy secret key for this applicaiton. */
	NSString *userID_;					/*!< The user ID, used to banner ads. This is the UDID by default. */
	NSString *plugin_;					/*!< The name of the plugin used. If no plugin is used, this value is set to "native" by default. */
	float currencyMultiplier_;			/*!< The currency multiplier value, used to adjust currency earned. */
	NSMutableData *data_;				/*!< Holds data for any data that comes back from a URL request. */
	int connectAttempts_;				/*!< The connect attempts is used to determine whether the alternate URL will be used. */
	BOOL isInitialConnect_;				/*!< Used to keep track of an initial connect call to prevent multiple repeated calls. */
	int responseCode_;					/*!< The response code received from the server. */
	NSURLConnection *connectConnection_;
	NSURLConnection *userIDConnection_;
	NSURLConnection *SDKLessConnection_;
    NSURLConnection *eventTrackingConnection_;
}

@property (nonatomic, copy) NSString *appID;
@property (nonatomic, copy) NSString *secretKey;
@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *plugin;
@property (assign) BOOL isInitialConnect;
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_4_0
@property (nonatomic, assign) UIBackgroundTaskIdentifier backgroundTaskID;
#endif

/*!	\fn requestTapjoyConnect:secretKey:(NSString *appID, NSString *secretKey)
 *	\brief This method is called to initialize the TapjoyConnect system.
 *
 * This method should be called upon app delegate initialization in the applicationDidFinishLaunching method.
 *	\param appID The application ID. Retrieved from the app dashboard in your Tapjoy account.
 *  \param secretKey The application secret key. Retrieved from the app dashboard in your Tapjoy account.
 *	\return The globally accessible #TapjoyConnect object.
 */
+ (TapjoyConnect*)requestTapjoyConnect:(NSString*)appID secretKey:(NSString*)secretKey;

/*!	\fn actionComplete:(NSString*)actionID
 *	\brief This is called when an action is completed.
 *
 * Actions are much like connects, except that this method is only called when a user completes an in-game action.
 *	\param actionID The action ID.
 *	\return The globally accessible #TapjoyConnect object.
 */
+ (TapjoyConnect*)actionComplete:(NSString*)actionID;

/*!	\fn sharedTapjoyConnect
 *	\brief Retrieves the globally accessible #TapjoyConnect singleton object.
 *
 *	\param n/a
 *	\return The globally accessible #TapjoyConnect singleton object.
 */
+ (TapjoyConnect*)sharedTapjoyConnect;

/*!	\fn deviceNotificationReceived
 *	\brief This is called whenever the application returns to the foreground.
 *
 *	\param n/a
 *	\return n/a
 */
+ (void)deviceNotificationReceived;

/*!	\fn exitNotificationReceived
 *	\brief This is called whenever the application is exited or termintated.
 *
 *	\param n/a
 *	\return n/a
 */
+ (void)exitNotificationReceived;

/*!	\fn TJCSHA256CommonParamsWithTimeStamp:string:(NSString* timeStamp, NSString* string)
 *	\brief Generates a SHA-256 hash value with the given time stamp.
 *
 * The following are sent as common parameters: appID, UDID, and timestamp.
 *	\param timeStamp The time stamp to generate the hash with.
 *	\param string This is appended to the string that will be hashed.
 *	\return The SHA-256 hash value.
 */
+ (NSString*)TJCSHA256CommonParamsWithTimeStamp:(NSString*)timeStamp string:(NSString*)string;

/*!	\fn TJCSHA256WithString:(NSString*)dataStr
 *	\brief Generates a SHA-256 hash value with the given string.
 *
 *	\param dataStr The string from which the hash value will be generated from.
 *	\return The SHA-256 hash value.
 */
+ (NSString*)TJCSHA256WithString:(NSString*)dataStr;

/*!	\fn getAppID
 *	\brief Retrieves the Tapjoy app ID.
 *
 *	\param n/a
 *	\return The Tapjoy app ID passed into requestTapjoyConnect.
 */
+ (NSString*)getAppID;

/*!	\fn setUserID:(NSString*)theUserID
 *	\brief Sets the user ID.
 *
 * The user ID defaults to the UDID. This is only changed when NOT using Tapjoy Managed Currency.
 *	\param theUserID The user ID.
 *	\return n/a
 */
+ (void)setUserID:(NSString*)theUserID;

/*!	\fn getUserID
 *	\brief Retrieves the user ID.
 *
 *	\param n/a
 *	\return The Tapjoy user ID. The user ID defaults to the UDID. If UDID is opted out, this returns null.
 */
+ (NSString*)getUserID;

/*!	\fn getSecretKey
 *	\brief Retrieves the secret.
 *
 *	\param n/a
 *	\return The Tapjoy secret key for this application.
 */
+ (NSString*)getSecretKey;

/*!	\fn setPlugin:(NSString*)thePlugin
 *	\brief Sets the plugin.
 *
 * The plugin defaults to "native".
 *	\param thePlugin The name of the plugin.
 *	\return n/a
 */
+ (void)setPlugin:(NSString*)thePlugin;

- (void)connectWithType:(int)connectionType withParams:(NSDictionary*)params;
- (NSString*)getURLStringWithConnectionType:(int)connectionType;
- (void)initiateConnectionWithConnectionType:(int)connectionType requestString:(NSString*)requestString paramsString:(NSString*)paramsString;

/*! \fn isJailBroken
 *	\brief Simple check to detect jail broken devices/apps.
 *
 * Note that this is NOT guaranteed to be accurate! There are very likely going to be ways to circumvent this check in the future.
 *	\param n/a
 *	\return YES for indicating that the device/app has been jailbroken, NO otherwise.
 */ 
- (BOOL)isJailBroken;

/*! \fn isJailBrokenStr
 *	\brief Simple check to detect jail broken devices/apps.
 *
 * Note that this is NOT guaranteed to be accurate! There are very likely going to be ways to circumvent this check in the future.
 *	\param n/a
 *	\return A string "YES" for indicating that the device/app has been jailbroken, "NO" otherwise.
 */ 
- (NSString*)isJailBrokenStr;

/*! \fn genericParameters
 *	\brief Retrieves the dictionary of generic parameters that are sent with every URL request.
 *
 *	\param n/a
 *	\return A dictionary of generic parameters, listed at the top of this file.
 */ 
- (NSMutableDictionary*)genericParameters;

/*! \fn createQueryStringFromDict:(NSDictionary*)paramDict
 *	\brief Takes the given dictionary and contructs a legal URL string from it.
 *
 *	\param n/a
 *	\return A legal URL string constructed from the given dicionary.
 */ 
- (NSString*)createQueryStringFromDict:(NSDictionary*)paramDict;
// Wrapper method.
+ (NSString*)createQueryStringFromDict:(NSDictionary*)paramDict;
- (NSString*)createQueryStringFromString:(NSString*)string;
+ (NSString*)createQueryStringFromString:(NSString*)string;

/*!	\fn setCurrencyMultiplier:(float)mult
 *	\brief Sets the currency multiplier for virtual currency to be earned.
 *
 *	\param mult The currency multiplier.
 *	\return n/a
 */
- (void)setCurrencyMultiplier:(float)mult;
// Wrapper method.
+ (void)setCurrencyMultiplier:(float)mult;

/*!	\fn getCurrencyMultiplier
 *	\brief Gets the currency multiplier for virtual currency to be earned.
 *
 *	\param n/a
 *	\return The currency multiplier value.
 */
- (float)getCurrencyMultiplier;
// Wrapper method.
+ (float)getCurrencyMultiplier;

/*!	\fn clearCache
 *	\brief Nukes the NSURLConnection cache. This seems to address some memory leak issue associated with NSURLConnections.
 *
 *	\param n/a
 *	\return n/a
 */
+ (void)clearCache;


+ (NSString*)getMACAddress;
+ (NSString*)getMACID;
+ (NSString*)getSHA1MacAddress;
+ (NSString*)getUniqueIdentifier;
+ (NSString*)getAdvertiserIdentifier;
+ (NSString*)getTimeStamp;

@end


#import "TapjoyConnectConstants.h"