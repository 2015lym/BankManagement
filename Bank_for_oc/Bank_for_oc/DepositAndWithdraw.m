//
//  DepositAndWithdraw.m
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import "DepositAndWithdraw.h"

@implementation DepositAndWithdraw
-(void)Deposit:(int)DepositCard and_db:(sqlite3 *)db
{
    int DepositMoney;
    NSLog(@"请输入你要存款的金额");
    scanf("%d",&DepositMoney);
    if (DepositMoney>0) {                                               //限定不允许存负数金额
    sqlite3_stmt *stmt3;
    char *sql="update user set money=money+? where id =? ";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt3, NULL)==SQLITE_OK)       //存款功能
    {
        sqlite3_bind_int(stmt3, 1, DepositMoney);
        sqlite3_bind_int(stmt3, 2, DepositCard);
        if (sqlite3_step(stmt3)==SQLITE_DONE)
        {
            NSLog(@"存款成功!");
        }
        else NSLog(@"存款失败!");
    }
    
    sqlite3_finalize(stmt3);
    }
    else NSLog(@"请输入正确的金额!");
}


-(void)Withdraw:(int)WithdrawCard and_db:(sqlite3 *)db and_checkmoney:(int)CheckMoney
{
    
    int WithdrawMoney;
    NSLog(@"请输入你要取款的金额");
    scanf("%d",&WithdrawMoney);
    if(WithdrawMoney>0)                                                 //限定不允许取负数金额
    {
        if (CheckMoney>WithdrawMoney) {                                 //禁止取款金额大于存款

    sqlite3_stmt *stmt4;
    char *sql="update user set money=money-? where id =? ";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt4, NULL)==SQLITE_OK)       //取款功能
    {
        sqlite3_bind_int(stmt4, 1, WithdrawMoney);
        sqlite3_bind_int(stmt4, 2, WithdrawCard);
        if (sqlite3_step(stmt4)==SQLITE_DONE)
        {
            NSLog(@"取款成功!");
        }
        else NSLog(@"取款失败!");
    }
    
    sqlite3_finalize(stmt4);
        }else NSLog(@"余额不足!");
    }
    else NSLog(@"请输入正确的金额!");
}
@end
