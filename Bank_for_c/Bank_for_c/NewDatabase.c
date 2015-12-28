//
//  NewDatabase.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//

#include "NewDatabase.h"
void NewDatabase(int rs,sqlite3 *db)
{
    char *zErrMsg=0;
    char *sql="create table user(id number primary key,name varchar2(20),password number,money number)";
    rs=sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    
}