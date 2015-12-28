//
//  Select.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//

#include "Select.h"
int Select(int Card,sqlite3 *db)
{
    int _money;
    sqlite3_stmt *stmt2;
    char *sql="select id,name,money from user where id=?";
    
    if (sqlite3_prepare_v2(db, sql, -1,&stmt2, NULL)==SQLITE_OK)       //查询功能
    {
        sqlite3_bind_int(stmt2, 1,Card);
        
        while (sqlite3_step(stmt2)==SQLITE_ROW)
        {
            char *name=(char *)sqlite3_column_text(stmt2, 1);
            int id=sqlite3_column_int(stmt2, 0);
            int money=sqlite3_column_int(stmt2, 2);
            printf("你好%s，你的卡号%d的帐户余额为%d💰\n\n",name,id,money);
            _money=money;
        }
        
    }
    sqlite3_finalize(stmt2);
    return _money;
}