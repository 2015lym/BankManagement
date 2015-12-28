//
//  Deposit.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//

#include "Deposit.h"

void Deposit(int Card,sqlite3 *db)
{
    int DepositMoney;
    printf("请输入你要存款的金额\n");
    scanf("%d",&DepositMoney);
    if(DepositMoney>0){
        sqlite3_stmt *stmt3;
        char *sql="update user set money=money+? where id =?";
        
        if (sqlite3_prepare_v2(db, sql, -1, &stmt3, NULL)==SQLITE_OK)       //存款功能
        {
            sqlite3_bind_int(stmt3, 1, DepositMoney);
            sqlite3_bind_int(stmt3, 2, Card);
            if (sqlite3_step(stmt3)==SQLITE_DONE)
            {
                printf("存款成功!\n");
            }
            else printf("存款失败!\n");
        }
        
        sqlite3_finalize(stmt3);
    }
    else printf("请输入正确的金额!\n");
}