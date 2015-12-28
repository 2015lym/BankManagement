//
//  Select.h
//  Bank_for_oc
//
//  Created by Lym on 15/12/27.
//  Copyright © 2015年 李一鸣. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>
@interface Select : NSObject
-(int)Select:(int) a and_db:(sqlite3*)db;
@end
