//
//  Way2LoginController.h
//  Way2Verify
//
//  Created by way2online on 23/10/17.
//  Copyright © 2017 Way2Online. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void(^Way2VerifyBlock)(NSDictionary *success, NSString *failure);
typedef void(^Way2VerifyCancel)(NSDictionary *success, NSString *failure);

@interface Way2LoginController : UIViewController

@property (nonatomic, strong) UIColor *backGroundColor;
@property (nonatomic, strong) UIColor *buttonColor;
@property (nonatomic, strong) UIColor *buttonTitleColor;
@property (nonatomic, strong) UIImage *backgroundImage;
@property (nonatomic, strong) Way2VerifyBlock verifyBlock;
@property (nonatomic,strong) NSString *versionString;
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil withAppToken:(NSString *)appToken withAppBunleID:(NSString *)appBundleID;

@end
