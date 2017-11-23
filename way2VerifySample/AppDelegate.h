//
//  AppDelegate.h
//  way2VerifySample
//
//  Created by Venkata rao on 17/11/17.
//  Copyright © 2017 Way2Online. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

