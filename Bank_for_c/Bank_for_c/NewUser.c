//
//  NewUser.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//


#include "NewUser.h"
#include <stdlib.h>

void NewUser(sqlite3 *db)
{
    //    char _id;
    //    char name[20];
    //    char _psw;
    //    printf("请输入要注册的数字id:\n");         //定义类型，输入数值
    //    scanf("%s",&_id);
    //    int id=atoi(&_id);
    //    int checkID=(int)_id;
    //    if(checkID>47&&checkID<58){
    //
    //    }
    //        else
    //    {
    //        printf("请输入数字的ID号!\n");
    //        exit(0);
    //    }
    //    printf("请输入您的姓名:\n");
    //    scanf("%s",name);
    //    printf("请输入密码:\n");
    //    scanf("%s",&_psw);
    //    int psw=atoi(&_psw);
    //
    //    int checkPsw=(int)_psw;
    //    if(checkPsw>47&&checkPsw<58){
    //
    //    }
    //    else
    //    {
    //        printf("当前只支持数字密码!\n");
    //        exit(0);
    //    }
    
    int id;
    char name[20];
    int psw;
    printf("请输入要注册的数字id:\n");         //定义类型，输入数值
    scanf("%d",&id);
    printf("请输入您的姓名:\n");
    scanf("%s",name);
    printf("请输入密码:\n");
    scanf("%d",&psw);
    
    char *sql="insert into user(id,name,password,money)values(?,?,?,0)";  //新建用户，金钱初始值为0
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)==SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_text(stmt, 2, name, -1, NULL);
        sqlite3_bind_int(stmt, 3, psw);
        if (sqlite3_step(stmt)==SQLITE_DONE) {
            printf("%s注册成功!请重启系统登录\n",name);
        }
        else printf("该卡号已有人注册!\n");
    }
    sqlite3_finalize(stmt);
    
}
