//
//  CountryCell.h
//  Way2Verify
//
//  Created by way2online on 23/10/17.
//  Copyright © 2017 Way2Online. All rights reserved.
//

#import <UIKit/UIKit.h>
#define CountryCellIdentifier @"CountryCellIdentity"


@interface CountryCell : UITableViewCell

@property (nonatomic, weak) IBOutlet UILabel *countryNameLabel;
@property (nonatomic, weak) IBOutlet UILabel *countryCodeLabel;

+ (UINib *)nib;
@end
