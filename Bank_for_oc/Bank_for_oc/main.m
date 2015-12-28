//
//  main.m
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
#import "NewDatabase.h"
#import "NewUser.h"
#import "Log_in.h"
#import "Select.h"
#import "DepositAndWithdraw.h"
#import "Transfer_Accounts.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int card;
        int password;
        int start;
        sqlite3 *db;
        int rs=sqlite3_open("bank2.db", &db);
        NewDatabase *database=[[NewDatabase alloc]init];
        [database NewDatabase:rs and_db:db];
        NSLog(@"欢迎来到个人银行系统!\n请输入(用户注册:1,登录:2)");      //注册or登录
        scanf("%d",&start);
        if (start==1)
        {
            NewUser *new=[[NewUser alloc]init];
            [new NewUser:db];
            return 0;
        }
        else
        {
            NSLog(@"请输入你的卡号:");
            scanf("%d",&card);
            NSLog(@"请输入你的密码:");
            scanf("%d",&password);
        }
        if (rs==SQLITE_OK)                         //登录系统，判断输入的id和password和数据库是否一致。详情Log_in.c
        {
            Log_in *log_in=[[Log_in alloc]init];
            int begin=[log_in Log_in:card and_b:password and_db:db];
            while (begin)
            {
                int choose;
                NSLog(@"输入对应数字选择您所需要的功能\n\n1.查询账户余额\t\t2.存款\n3.取款\t4.转账\t5.输入其它退出系统");
                scanf("%d",&choose);                            //switch循环，通过数字跳转到各个功能
                
                Select *select=[[Select alloc]init];            //初始化
                DepositAndWithdraw *depositAndwithdraw=[[DepositAndWithdraw alloc]init];
                Transfer_Accounts *transfer=[[Transfer_Accounts alloc]init];
                
                switch (choose) {
                    case 1:
                    {
                        
                        [select Select:card and_db:db];
                        break;
                    }
                    case 2:
                    {
                        
                        [depositAndwithdraw Deposit:card and_db:db];
                        break;
                    }
                    case 3:
                    {
                        int CheckMoney;
                        CheckMoney=[select Select:card and_db:db];                        //调用查询功能，得到金钱返回值，检测余额是否够取款
                        [depositAndwithdraw Withdraw:card and_db:db and_checkmoney:CheckMoney];
                        break;
                    }
                    case 4:
                    {
                        int CheckMoney;
                        CheckMoney=[select Select:card and_db:db];                        //调用查询功能，得到金钱返回值，检测余额是否够转账
                        [transfer Transfer:card and_db:db and_checkmoney:CheckMoney];
                        break;
                    }
                    default:
                    {   NSLog(@"谢谢使用本系统，走前请取走您的银行卡,再见!");
                        begin=0;
                        break;
                    }
                }
                
                
            }
        }

    }
    return 0;
}
