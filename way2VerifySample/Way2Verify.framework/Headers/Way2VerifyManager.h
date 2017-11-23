//
//  Way2VerifyManager.h
//  Way2Verify
//
//  Created by way2online on 09/11/17.
//  Copyright © 2017 Way2Online. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

/*!
 * @header Way2VerifyManager.h
 * @brief The Way2VerifyManager will returned via block method once the user verify the mobile number
 */

@interface Way2VerifyManager : NSObject
/*! @property backGroundColor @brief to add custom color to the back ground views without logo it won't applicable  */
@property ( nonatomic, strong) UIColor * _Nullable backGroundColor;

/*! @property buttonColor @brief to give custom colors to the buttons */
@property (nonatomic, strong) UIColor * _Nullable buttonColor;

/*! @property buttonTitleColor @brief you can change button title color respectice to the bg color  */
@property (nonatomic, strong, readwrite) UIColor * _Nullable buttonTitleColor;

/*! @property backgroundImage @brief add an your custom image or logo insted off default bg image. It will work along with background color you must provide the both background color and your logo */
@property (nonatomic, strong, readwrite) UIImage * _Nullable backgroundImage;

+ (nonnull Way2VerifyManager *)sharedManager;

@property (nonatomic, strong) CLLocation * _Nullable currentLocation;


/*!  Implement the Way2Verify methods */

/*! This method will initiate to take the Way2verify screen automatically returs the responce as success or failure or closed */
- (void)loginWithCompletionBlock:(void(^_Nullable)(NSDictionary * _Nullable success, NSString * _Nullable failure))completionBlock;

/*! This will return the network status 2g / 3g / LTE / No network */
- (NSString *_Nullable)getNetWorkConnectionAvailableStatus;

-(void)setupWithAppKey:(NSString *_Nonnull)APPKEY;


@end
