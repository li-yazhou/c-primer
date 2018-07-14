#include"..\header\header.h"
#include"..\header\function.h"
extern char* loginID;  // 声明为外部变量 ，在login.c文件中定义的全局变量 

void expend(){
	puts("2.expend option");
	struct DataItem di;
	struct Date dt;
	dt = getDate();
	di.date = dt; //TODO, getDate()函数需要完善 
	strcpy(di.ID,loginID);
	
	di.operation = '-'; 
	puts("请输入支出金额：");
	scanf("%lf", &di.money);
	getchar(); // accept the keyborad of Enter
	puts("请输入支出原因：");
	gets(di.remark);
	double lastBalance = findLastBalance(di.ID);
	if(lastBalance < di.money){
		puts("对不起，余额不足!\n");
		return; 
	} 
	di.balance =  lastBalance - di.money;
	printExpendInfo(di, lastBalance);// print the information of expend	
	return;	
} 

/*print the info of expend*/
void printExpendInfo(struct DataItem di, double lastBalance){
	system("cls");
	printBorder("-");
	puts("保存的数据项如下：");
	printf("ID:\t\t%s\n",di.ID); 
	printf("之前余额:\t%.2lf\n",lastBalance);
	printf("操作:\t\t%c %.2lf\n",di.operation, di.money);
	printf("支出原因:\t%s\n",di.remark);
	printf("余额:\t\t%.2lf\n", di.balance);
	printf("日期：\t\t%d年%d月%d日\n\n",di.date.year,di.date.month,di.date.day);
	printBorder("-");
	puts("\n");
	saveDataItem(di);
	
}
