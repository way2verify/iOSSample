# iOS SDK

## Getting started

### Prerequisites

You should have:

1. ios 8.0 or later
2. App ID in the "Apple development portal". If you do not have App ID yet. New app id will be automatically created by Xcode.
3. Sign up at http://way2verify.com

### Installation

1. Download the Framework zip file from the (git url)
2. Unzip the file
3. Add the Way2Verify.Framework  into your project
4. Drag and drop Way2Verify.Framework into your project (ie add it as a Framework to your project).
Embedding it this way will not require any additional script to be run.
5. Add the Way2Verify framework (from Products output of Way2Verify.Framework) into the Embedded Binaries section of the General tab of your target
6. In your info.plist add location access keys 
> Privacy - Location Usage Description : This app will use your location to provide better services in future.
> Privacy - Location When In Use Usage Description : This app will use your location to provide better services in future.


## Create YOUR_APP_KEY
To generate YOUR_APP_KEY please do follow the below steps:

1.logon to http://way2verify.com

2.register with your details

3.login with your credentials

4.create an iOS application with following feilds

. App name

. Bundle id

. Prefix

 To find the Prefix, open the Member Center on https://developer.apple.com and look at "Certificates, Identifiers & Profiles", click "Identifiers", then "App IDs" in the section under "Identifiers". Find your app, click on it and there you can see the Prefix value

>  ### Add Runscript ##

 . ProjectTargert > Buildphases > add new runscript
 . This script loops through the frameworks embedded in the application and
 . removes unused architectures.
 
 ```
 PP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"
 find "$APP_PATH" -name '*.framework' -type d | while read -r FRAMEWORK
 do
 FRAMEWORK_EXECUTABLE_NAME=$(defaults read "$FRAMEWORK/Info.plist" CFBundleExecutable)
 FRAMEWORK_EXECUTABLE_PATH="$FRAMEWORK/$FRAMEWORK_EXECUTABLE_NAME"
 echo "Executable is $FRAMEWORK_EXECUTABLE_PATH"
 
 EXTRACTED_ARCHS=()
 
 for ARCH in $ARCHS
 do
 echo "Extracting $ARCH from $FRAMEWORK_EXECUTABLE_NAME"
 lipo -extract "$ARCH" "$FRAMEWORK_EXECUTABLE_PATH" -o "$FRAMEWORK_EXECUTABLE_PATH-$ARCH"
 EXTRACTED_ARCHS+=("$FRAMEWORK_EXECUTABLE_PATH-$ARCH")
 done
 
 echo "Merging extracted architectures: ${ARCHS}"
 lipo -o "$FRAMEWORK_EXECUTABLE_PATH-merged" -create "${EXTRACTED_ARCHS[@]}"
 rm "${EXTRACTED_ARCHS[@]}"
 
 echo "Replacing original executable with thinned version"
 rm "$FRAMEWORK_EXECUTABLE_PATH"
 mv "$FRAMEWORK_EXECUTABLE_PATH-merged" "$FRAMEWORK_EXECUTABLE_PATH"
 
 done
```
#### Objective-C

1. Import the Way2VerifySDK framework in the class where you want to initialize it (for example AppDelegate) and in the class that you want to receive the verify response.

```objectivec
#import <Way2Verify/Way2Verify.h>
```

2. Add YOUR_APP_KEY to the  Way2VerifySDK. We recommend this to be done in the application:didFinishLaunchingWithOptions:

```objectivec

[[Way2VerifyManager shareManager] setupWithAppKey:<#YOUR_APP_KEY#> ];

```

**Important:** Make sure you type the YOUR_APP_KEY field correctly. In case it was incorrect, the Verification screen in Way2Verify will be shown and immediatelly dismissed.

The Way2VerifyManager is of type  (written in Objective C) which allows the following custom data:

a. The Way2VerifyManager does the Verify request automatically. To use the predefined buttons you need to **set the Button Color and title color to Custom** .
```objectivec

/*!
* @class Way2VerifyManager
* @brief The True Way2VerifyManager allows to custom theame colors.
*/

@interface Way2VerifyManager : NSObject
/*! @property backGroundColor @brief to add custom color to the back ground views without logo it won't applicable  */
@property (nonatomic, strong) UIColor *backGroundColor;

/*! @property buttonColor @brief to give custom colors to the buttons */
@property (nonatomic, strong) UIColor *buttonColor;

/*! @property buttonTitleColor @brief you can change button title color respectice to the bg color  */
@property (nonatomic, strong, readwrite) UIColor *buttonTitleColor;

/*! @property backgroundImage @brief add an your custom image or logo insted off default bg image. It will work along with background color you must provide the both background color and your logo */
@property (nonatomic, strong, readwrite) UIImage *backgroundImage;

```

3. In AppDelegate implement the code in  application:didFinishLaunchingWithOptions: and call the corresponding method of the [Way2VerifyManager shareManager].

```objectivec
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
// Override point for customization after application launch.

[Way2VerifyManager shareManager].backGroundColor  = [UIColor blueColor];// sets the background theme color

[Way2VerifyManager shareManager].buttonColor = [UIColor redColor]; // sets the predefined button background color

[Way2VerifyManager shareManager].buttonTitleColor = [UIColor redColor]; // sets the predefined buttons title color

[Way2VerifyManager shareManager].backgroundImage = [UIImage imageNamed:@"Applogo.png"]; // Add your app logo insted of defauld backgrobackgroundImage

return YES;
}
```

4.  This method will take  you to the Way2verify screen wi automatically returs the responce as success or failure or closed

```objectivec

[[Way2VerifyManager shareManager] loginWithCompletionBlock:^(NSDictionary *success, NSString *failure) {
if (success) {
NSLog(@"%@", success);
}else {
NSLog(@"%@", failure);
}

}];

```
#### Swift
1. Import the Way2VerifySDK framework in the class where you want to initialize it (for example AppDelegate) and in the class that you want to receive the verify response.

```swift
import Way2Verify
```

2. Add YOUR_APP_KEY to the  Way2VerifySDK. We recommend this to be done in the  application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions:

```swift

      Way2VerifyManager.shared().setup(withAppKey: <#YOUR_APP_KEY#>);

```

**Important:** Make sure you type the YOUR_APP_KEY field correctly. In case it was incorrect, the Verification screen in Way2Verify will be shown and immediatelly dismissed.
3. In AppDelegate implement the code in  application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: and call the corresponding method of the Way2VerifyManager.shared().

```swift
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
// Override point for customization after application launch.

Way2VerifyManager.shared().setup(withAppKey: <#YOUR_APP_KEY#>);

Way2VerifyManager.shared().backGroundColor = UIColor.red //sets the background theme color

Way2VerifyManager.shared().backgroundImage = UIImage (named:"logo.png") // Add your app logo insted of defauld backgrobackgroundImage

Way2VerifyManager.shared().buttonColor = UIColor.red // sets the predefined button background color

Way2VerifyManager.shared().buttonTitleColor = UIColor.white  // sets the predefined buttons title color


return true
}
```

4.  This method will take  you to the Way2verify screen wi automatically returs the responce as success or failure or closed

```swift

[[Way2VerifyManager shareManager] loginWithCompletionBlock:^(NSDictionary *success, NSString *failure) {
if (success) {
NSLog(@"%@", success);
}else {
NSLog(@"%@", failure);
}

}];

```







