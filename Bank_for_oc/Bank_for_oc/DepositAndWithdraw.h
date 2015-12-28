//
//  DepositAndWithdraw.h
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "Select.h"
@interface DepositAndWithdraw : NSObject
-(void)Deposit:(int)DepositCard and_db:(sqlite3 *)db;
-(void)Withdraw:(int)WithdrawCard and_db:(sqlite3 *)db and_checkmoney:(int)CheckMoney;
@end
