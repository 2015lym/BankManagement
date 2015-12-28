//
//  NewDatabase.h
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
@interface NewDatabase : NSObject
-(void) NewDatabase:(int)rs and_db:(sqlite3 *)db;
@end
