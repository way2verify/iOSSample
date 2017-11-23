//
//  OTPController.h
//  BeautyApp
//
//  Created by way2online on 27/09/17.
//  Copyright © 2017 Pramod. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Way2Verify.h"

typedef void(^DismissController)(NSDictionary *success, NSString *failure);
@interface Way2OTPController : UIViewController<UITextFieldDelegate>
@property (nonatomic, strong) NSString *mobileNumber;
@property (nonatomic, strong) NSString *mid;
@property (nonatomic, strong) NSString *appBundleID;
@property (nonatomic, strong) NSString *appToken;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *mnc;
@property (nonatomic, strong) NSString *mcc;
@property (strong, nonatomic) DismissController dismissController;
@property (nonatomic, strong) UIColor *backGroundColor;
@property (nonatomic, strong) UIColor *buttonColor;
@property (nonatomic, strong) UIColor *buttonTitleColor;
@property (nonatomic, strong) NSString *isoCode;



- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil withAppToken:(NSString *)appToken withAppBunleID:(NSString *)appBundleID andMobileNumber:(NSString *)number;

@end
