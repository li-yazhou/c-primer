#include"..\header\header.h"
#include"..\header\function.h"
#include<math.h>

/**
1.小金库的信息统一放在随机文件中，该随机文件的数据项有
  记录ＩＤ　，发生日期，发生事件，操作金额和余额等信息。
  每记录一次收支，文件要增加一条记录，并计算一次余额
  
2.程序可创建该文件并添加新收入或支出信息，可进行各种查询，统计，输出流水账等信息。

3.本系统要有通用性、界面美观、操作方便。要考虑系统安全。
1

4.可增加其他有用的功能。
*/

/*
说明：每个用户都有一个独立的文件用于保存自己的数据，文件名为ID_log.txt 
*/ 

//主函数，程序入口 
int main(){
	view();
//	removetest();
	return 0;
}


void test01(){
	int d = rename("data/userdata/user_bak.db", "data/userdata/user.db");
	printf("%d", d); 
	FILE *fp, *fp_bak;
	fp = fopen("data/userdata/user.db", "rb");
//	fp_bak = fopen("data/userdata/user_bak.db", "rb");
	struct User user;
	struct User u;
	fread(&user, sizeof(struct User), 1, fp);
//	fread(&u, sizeof(struct User), 1, fp_bak);
	printf("%s:%s\n",user.ID, user.pass);
	puts("---------------");
//	printf("%s:%s", u.ID, u.pass); 
	fclose(fp);
	fclose(fp_bak);
//	int r = remove("data/userdata/user.db");
//	printf("%d", r); 
//	int d = rename("data/userdata/user_bak.db", "data/userdata/user.db");
//	printf("%d", d); 
}







