//
//  ViewController.m
//  way2VerifySample
//
//  Created by Venkata rao on 17/11/17.
//  Copyright © 2017 Way2Online. All rights reserved.
//

#import "ViewController.h"
#import "DetailViewController.h"
#import <Way2Verify/Way2Verify.h>
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationController.navigationBar.hidden =YES;
    // Do any additional setup after loading the view, typically from a nib.

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)loginAction:(id)sender {
    [[Way2VerifyManager sharedManager] loginWithCompletionBlock:^(NSDictionary *success, NSString *failure) {
        if (success) {
            NSLog(@"%@", success);
       
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    DetailViewController *detail = (DetailViewController *)[storyboard instantiateViewControllerWithIdentifier:@"myViewCont"];
        [self.navigationController pushViewController:detail animated:YES];
            
        }else {
            NSLog(@"%@", failure);
        }
        
    }];
    
}


@end
