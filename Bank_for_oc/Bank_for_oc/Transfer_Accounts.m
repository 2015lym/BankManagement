//
//  Transfer_Accounts.m
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import "Transfer_Accounts.h"

@implementation Transfer_Accounts
-(void) Transfer:(int) MyCard and_db:(sqlite3 *)db and_checkmoney:(int)CheckMoney
{
    int OtherCard;
    int TransferMoney;
    NSLog(@"请输入你要转账的卡号");
    scanf("%d",&OtherCard);
    sqlite3_stmt *stmt5;
    char *sql="select id,name from user where id=?";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt5, NULL)==SQLITE_OK) {         //判断对象用户是否存在
        sqlite3_bind_int(stmt5, 1,OtherCard);
        if (sqlite3_step(stmt5)==SQLITE_ROW)
        {
            char *name=(char *)sqlite3_column_text(stmt5, 1);
            int id=sqlite3_column_int(stmt5, 0);
            NSLog(@"该用户名为:%s,卡号为:%d",name,id);

    NSLog(@"请输入你要转账的金额");
    scanf("%d",&TransferMoney);
    if(TransferMoney>0)                                                     //禁止输入负数
    {
        if(CheckMoney>TransferMoney)                                        //禁止转账金额大于存款
        {
    sqlite3_stmt *stmt6;
    char *sql="update user set money=money+? where id=? ";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt6, NULL)==SQLITE_OK) {         //转给对方的钱
        sqlite3_bind_int(stmt6, 1, TransferMoney);
        sqlite3_bind_int(stmt6, 2, OtherCard);
        sqlite3_finalize(stmt6);
        
        sqlite3_stmt *stmt7;
        char *sql="update user set money=money-? where id=?";
        if (sqlite3_prepare_v2(db, sql, -1, &stmt7, NULL)==SQLITE_OK) {     //自己扣的钱
            sqlite3_bind_int(stmt7, 1, TransferMoney);
            sqlite3_bind_int(stmt7, 2, MyCard);
        }
        
        if (sqlite3_step(stmt6)&&sqlite3_step(stmt7))
        {
            NSLog(@"转账成功!");
            sqlite3_finalize(stmt7);
        }
        else NSLog(@"转账失败!");
    }

        }else NSLog(@"余额不足!");
    }
    else NSLog(@"请输入正确的金额!");
}
else NSLog(@"该用户名不存在!");
}

    
}
@end
