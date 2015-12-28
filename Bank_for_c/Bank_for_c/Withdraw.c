//
//  Withdraw.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//

#include "Withdraw.h"

void Withdraw(int Card,int CheckMoney,sqlite3 *db)
{
    int WithdrawMoney;
    printf("请输入你要取款的金额\n");
    scanf("%d",&WithdrawMoney);
    if (CheckMoney>WithdrawMoney&&WithdrawMoney>0) {
        sqlite3_stmt *stmt4;
        char *sql="update user set money=money-? where id =?";
        
        if (sqlite3_prepare_v2(db, sql, -1, &stmt4, NULL)==SQLITE_OK)       //取款功能
        {
            sqlite3_bind_int(stmt4, 1, WithdrawMoney);
            sqlite3_bind_int(stmt4, 2, Card);
            if (sqlite3_step(stmt4)==SQLITE_DONE)
            {
                printf("取款成功!\n");
            }
            else printf("取款失败!\n");
        }
        
        sqlite3_finalize(stmt4);
    }
    else printf("余额不足，或输入了错误的金额!\n");
    
}