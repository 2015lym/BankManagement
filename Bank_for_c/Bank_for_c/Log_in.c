//
//  Log_in.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//

#include "Log_in.h"

int log_in(int card,int psw,sqlite3 *db)
{
    sqlite3_stmt *stmt1;
    char *sql="select id,name,password from user where id=? and password=?";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt1, NULL)==SQLITE_OK)             //登录功能
    {
        sqlite3_bind_int(stmt1, 1, card);
        sqlite3_bind_int(stmt1, 2, psw);
    }
    
    while (sqlite3_step(stmt1)==SQLITE_ROW)
    {
        printf("登录成功!\n");
        sqlite3_finalize(stmt1);
        return 1;
    }
    printf("用户名不存在或密码错误!\n");
    
    return 0;
}