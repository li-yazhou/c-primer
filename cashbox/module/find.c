#include"..\header\header.h"
#include"..\header\function.h"

extern char* loginID;  // 声明为外部变量 ，在login.c文件中定义的全局变量 

//查询账户最新信息 
void find(){
	puts("3.find option");
	struct Date date;
	struct DataItem di;
	int result = isExistDataItem(loginID);
	if(result == -1){
		puts("暂时没有数据记录！");
		return; 
	} 
	di = getLastDataItem(loginID);
	system("cls");
	printBorder("-");
	puts("该用户最新信息如下：");
	printf("ID:\t\t%s\n",di.ID); 
	printf("操作:\t\t%c %.2lf\n",di.operation, di.money);
	printf("备注:\t\t%s\n", di.remark);
	printf("余额:\t\t%.2lf\n", di.balance);
	printf("日期：\t\t%d年%d月%d日\n\n",di.date.year,di.date.month,di.date.day);
	printBorder("-");
	puts("\n");
	return;	 
} 





