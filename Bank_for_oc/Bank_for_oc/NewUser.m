//
//  NewUser.m
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import "NewUser.h"

@implementation NewUser
-(void) NewUser:(sqlite3 *)db
{
    int id;
    char name[20];
    int psw;
    NSLog(@"请输入要注册的数字id:");         //定义类型，输入数值
    scanf("%d",&id);
    NSLog(@"请输入您的姓名:");
    scanf("%s",name);
    NSLog(@"请输入密码:");
    scanf("%d",&psw);

    char *sql="insert into user(id,name,password,money)values(?,?,?,0)";  //新建用户，金钱初始值为0
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)==SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_text(stmt, 2, name, -1, NULL);
        sqlite3_bind_int(stmt, 3, psw);
        if (sqlite3_step(stmt)==SQLITE_DONE) {
            NSLog(@"%s注册成功!请重启系统登录",name);
        }
        else NSLog(@"该卡号已有人注册!");
    }
    sqlite3_finalize(stmt);
   
}
@end
