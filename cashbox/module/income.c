#include"..\header\header.h"
#include"..\header\function.h"
extern char* loginID;  // 声明为外部变量 ，在login.c文件中定义的全局变量 

//收入 
void income(){
	puts("1.income option");
	struct DataItem di;
	struct Date dt;
	dt = getDate();
	di.date = dt; //TODO, getDate()函数需要完善 
	strcpy(di.ID, loginID); 
	di.operation = '+'; 
	puts("请输入收入金额：");
	scanf("%lf", &di.money);
	getchar();
	puts("请输入收入来源：");
	gets(di.remark); 
	double lastBalance = findLastBalance(di.ID);
	di.balance =  lastBalance + di.money;
	saveDataItem(di);
	printIncomeInfo(di, lastBalance); 

}

/*print the info of income operation*/
void printIncomeInfo(struct DataItem di, double lastBalance){
	system("cls");
	printBorder("-");
	puts("保存的数据项如下：");
	printf("ID:\t\t%s\n",di.ID); 
	printf("之前余额:\t%.2lf\n",lastBalance);
	printf("操作:\t\t%c %.2lf\n",di.operation, di.money);
	printf("余额:\t\t%.2lf\n", di.balance);
	printf("备注:\t\t%s\n", di.remark);
	printf("日期：\t\t%d年%d月%d日\n\n",di.date.year,di.date.month,di.date.day);
	printBorder("-");
	puts("\n");	
}

/*查询到最新的余额 ，收入和支出都需要使用这个函数 */
double findLastBalance(char* ID){
	struct DataItem di;
	di = getLastDataItem(ID);
	//用户第一次操作，余额是 0.0 
	return di.balance;
}





