//
//  NewDatabase.m
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import "NewDatabase.h"

@implementation NewDatabase
-(void) NewDatabase:(int)rs and_db:(sqlite3 *)db
{
    char *zErrMsg=0;                                //建立新数据库,check限定数字id必须为正数
    char *sql="create table user(id number primary key,name varchar2(20),password number,money number check(id>0))";
    rs=sqlite3_exec(db, sql, 0, 0, &zErrMsg);

}
@end
