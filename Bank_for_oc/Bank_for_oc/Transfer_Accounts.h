//
//  Transfer_Accounts.h
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import "DepositAndWithdraw.h"
#import <sqlite3.h>
@interface Transfer_Accounts : DepositAndWithdraw
-(void) Transfer:(int) MyCard and_db:(sqlite3 *)db and_checkmoney:(int)CheckMoney;
@end
