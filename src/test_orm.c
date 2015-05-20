/*
 * test_orm.c
 *
 *  Created on: 2015年5月20日
 *      Author: yuan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#include "orm/db.h"

const char *g_host_name = "localhost";
const char *g_user_name = "root";
const char *g_password = "123456";
const char *g_db_name = "ast3_storage_test";
const unsigned int g_db_port = 3306;


#define LEN 1024 	// 缓冲区最大字节数

MYSQL g_mysql;
MYSQL *g_conn; 				// mysql 连接
MYSQL_RES *g_res; 			// mysql 记录集
MYSQL_ROW g_row; 			// 字符串数组，mysql 记录行


int main(void) {

	mysql_init(&g_mysql);		//初始化数据库连接

	//connect to MySQL as usual
	g_conn = mysql_real_connect(&g_mysql, g_host_name, g_user_name, g_password, g_db_name, g_db_port, NULL, 0);

	//pass the MySQL connection to function, that initializes the "ORM"
	db_init (&g_mysql);


	//the *__new method creates empty structure
	db_disk_info *disk_info;
//	disk_info = db_disk_info__new();
//
//
//	//获取系统当前时间并格式化
//	time_t calendar_time = time(NULL);
////	struct tm * tm_local = localtime(&calendar_time);
////	char str_f_t [LEN];
////	strftime(str_f_t, sizeof(str_f_t), "%G-%m-%d %H:%M:%S", tm_local);
//
//	//初始化Disk_Info
//	disk_info->disk_name = "disk_003";
//	disk_info->disk_uuid = "5a9068d5a7bf4b3bbec918af44e9d4e0";
//	disk_info->disk_type = "ext3/ext4";
//	disk_info->disk_capacity = 1024.00;
//	disk_info->disk_used = 300.00;
//	disk_info->recent_use_time = calendar_time;
//	disk_info->disk_status = 0;
//	disk_info->permisssion = 0;
//
//    /*
//     * this method inserts the structure into according table.
//     * If it has serial field, its value is reflected into structure
//    */
//    db_disk_info__insert(disk_info);

	//Test query
	disk_info = db_disk_info__get_by_id(3);

	printf("Disk Name=====>>>>%s\n", disk_info->disk_name);


    return EXIT_SUCCESS;
}
