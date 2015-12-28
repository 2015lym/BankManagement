//
//  main.c
//  BankManagement
//
//  Created by Lym on 15/12/18.
//  Copyright © 2015年 Lym. All rights reserved.
//

#include <stdio.h>
#include <sqlite3.h>
#include "Log_in.h"
#include "Select.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "Transfer_Accounts.h"
#include "NewUser.h"
#include "NewDatabase.h"
int main(int argc, const char * argv[]) {
    int card;
    int password;
    int start;
    sqlite3 *db;                                               //连接sqlite3数据库
    int rs=sqlite3_open("bank.db", &db);
    NewDatabase(rs,db);
    printf("欢迎来到个人银行系统!\n请输入(用户注册:1,登录:2)\n");     //没有用户名密码可以注册一个☝️
    scanf("%d",&start);
    if (start==1)
    {
        NewUser(db);
        return 0;
    }
    else {
        printf("请输入你的卡号:\n");
        scanf("%d",&card);
        printf("请输入你的密码:\n");
        scanf("%d",&password);
    }
    
    
    if (rs==SQLITE_OK)                         //登录系统，判断输入的id和password和数据库是否一致。详情Log_in.c
    {
        int begin=log_in(card,password,db);
        while (begin)
        {
            int b;
            printf("选择您所需要的功能\n\n1.查询账户余额\t\t2.存款\n3.取款\t4.转账\t5.输入任意键退出系统\n");
            
            scanf("%d",&b);                    //switch循环，通过数字跳转到各个功能
            switch (b) {
                case 1:
                {
                    Select(card,db);
                    break;
                }
                case 2:
                {
                    Deposit(card,db);
                    break;
                }
                case 3:
                {
                    int check=Select(card, db);
                    Withdraw(card,check,db);
                    break;
                }
                case 4:
                {
                    int check=Select(card, db);
                    Transfer(card,check,db);
                    break;
                }
                default:
                {
                    printf("谢谢使用本系统，走前请取走您的银行卡,再见!\n");
                    begin=0;
                    break;
                }
            }
            
            
        }
    }
    
    return 0;
}
