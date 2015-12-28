//
//  Transfer_Accounts.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//

#include "Transfer_Accounts.h"

void Transfer(int Card,int CheckMoney,sqlite3 *db)
{
    int OtherCard;
    int TransferMoney;
    printf("请输入你要转账的卡号\n");
    scanf("%d",&OtherCard);
    
    sqlite3_stmt *stmtCheckid;
    char *sql="select id,name from user where id=?";
    
    if (sqlite3_prepare_v2(db, sql, -1,&stmtCheckid, NULL)==SQLITE_OK)       //查询功能
    {
        sqlite3_bind_int(stmtCheckid, 1,OtherCard);
        
        if (sqlite3_step(stmtCheckid)==SQLITE_ROW)
        {
            char *name=(char *)sqlite3_column_text(stmtCheckid, 1);
            int id=sqlite3_column_int(stmtCheckid, 0);
            printf("对方的姓名为:%s，卡号%d\n",name,id);
            
            
            
            printf("请输入你要转账的金额\n");
            scanf("%d",&TransferMoney);
            if(CheckMoney>TransferMoney&&TransferMoney>0)
            {
                sqlite3_stmt *stmt5;
                char *sql="update user set money=money+? where id=?";
                if (sqlite3_prepare_v2(db, sql, -1, &stmt5, NULL)==SQLITE_OK) {     //转给对方的钱
                    sqlite3_bind_int(stmt5, 1, TransferMoney);
                    sqlite3_bind_int(stmt5, 2, OtherCard);
                    
                    sqlite3_finalize(stmt5);
                }
                char *sql1="update user set money=money-? where id=?";
                sqlite3_stmt *stmt6;
                if (sqlite3_prepare_v2(db, sql1, -1, &stmt6, NULL)==SQLITE_OK) {     //自己扣的钱
                    sqlite3_bind_int(stmt6, 1, TransferMoney);
                    sqlite3_bind_int(stmt6, 2, Card);
                }
                
                if (sqlite3_step(stmt5)&&sqlite3_step(stmt6))
                {
                    printf("转账成功!\n");
                }
                else printf("转账失败!\n");
                
                sqlite3_finalize(stmtCheckid);
                sqlite3_finalize(stmt6);
            }
            else printf("余额不足，或输入了错误的金额!\n");
        }
        else printf("该用户不存在!");
    }
    
    
}