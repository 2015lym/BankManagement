//
//  Log_in.m
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import "Log_in.h"

@implementation Log_in
-(int) Log_in:(int) a and_b:(int)b and_db:(sqlite3 *)db
{
    sqlite3_stmt *stmt1;
    char *sql="select id,name,password,money from user where id=? and password=?";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt1, NULL)==SQLITE_OK)             //登录功能
    {
        sqlite3_bind_int(stmt1, 1, a);
        sqlite3_bind_int(stmt1, 2, b);
    }
    
    while (sqlite3_step(stmt1)==SQLITE_ROW)
    {
        NSLog(@"登录成功!");
        sqlite3_finalize(stmt1);
        return 1;
    }
    NSLog(@"用户名不存在或密码错误!");
    sqlite3_finalize(stmt1);
    return 0;

}
@end
