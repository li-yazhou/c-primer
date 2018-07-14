#include"..\header\header.h"
#include"..\header\function.h"
#include<time.h>

extern char* loginID; // 声明为外部变量 ，在login.c文件中定义的全局变量 

/*统计*/
void count(){
	puts("4. count option."); 
	//统计操作 
	int retval = countView(loginID);
	if(retval == 0){
		return;
	} 
}

/*统计交互界面*/
/*返回 0 则上一级也进行return操作，终止统计操作，否则可以多次查询*/
int countView(char* ID){
	while(1){
		puts("输入Y或者y查询，否则退出统计");
		char inputs[10];
		gets(inputs);
		
		if(strlen(inputs) > 1){
			return 0;
		} 
		
		if(inputs[0] == 'Y' || inputs[0] == 'y'){
			printCountMenu();		
			chooseCountOption(ID);
		}else{
			puts("");  //换行 
			return 0;
		}
	 
	} 
}


/*打印统计菜单界面*/ 
void printCountMenu(){
	//可以放到查询功能（find源文件）里面 
	char options[3][20] = {"a.统计收入", "b.统计支出", "c.流水账"};
	printBorder("*");
	int i;
	for(i = 0; i < 3; i++){
		printf("\t");		
		printf(options[i]);
		printf("\n");
	} 
	printBorder("*");
	return;		
}


/*选择统计选项*/
void chooseCountOption(char* ID){
	char choice;
	char inputs[10];
	while(1){
		puts("请选择操作：[a/b/c]");	 
		gets(inputs);
		if(strlen(inputs) > 1){
			puts("输入选择不合法！");
			continue;
		} 
		choice = inputs[0];
		if(choice == 'a' || choice == 'b' || choice == 'c'){
			break;
		}else{
			puts("输入选择不合法！"); 
			continue;
		}
	}
	
	switch(choice){
		case 'a':
			countIncome(ID);
			break;
		case 'b':
			countExpend(ID);
			break;
		case 'c':
			printLog(ID);
			break;
	}		
	return;	
}


/*统计收入情况*/
void countIncome(char* ID){
	puts("countIncome"); 
	struct Date dates[2]; // 保存用户输入的起止日期 
	int result = setDatesValue(dates);
	if(result == -1){
		return;
	}
	countInfo(ID, '+', dates);  // 没有添加时间段条件，统计所有的收入记录 
	return;
}


/*统计支出情况*/ 
void countExpend(char* ID){
	puts("countExpend");
	// 让用户输入起止日期 ,分别保存到 dates[0],dates[1]中 
	struct Date dates[2];
	int result = setDatesValue(dates);
	if(result == -1){
		return;
	}
	countInfo(ID,'-',dates);
	return;
} 


/*打印用户的流水账*/
void printLog(char* ID){
	puts("printLog");
	// 让用户输入起止日期 ,分别保存到 dates[0],dates[1]中 
	struct Date dates[2];
	int result = setDatesValue(dates);
	if(result == -1){
		return;
	}
	countInfo(ID, '0', dates); //打印流水账，即所有的收入和支出信息 
	return;
}


void countInfo(char* ID, char operation, struct Date dates[2]){	
	int flag = 0; // 标识符，假如最终 flag = 0 说明没有记录 
	FILE* fp;
	fp = openFile(ID, "ab+");
	struct DataItem di;
	double sum;
	sum = 0;

	time_t start = getSecond(dates[0]); //当前日期到1970-1-1 00:00:00的秒数 
	time_t end = getSecond(dates[1]);  //当前日期到1970-1-1 00:00:00的秒数 
	
	if(start > end){ // 起始日期比终止日期大，则不合格 
		puts("输入起止日期不合格！");
		return; 
	}
	
	system("cls"); 
	puts("统计信息如下："); 
	while(fread(&di, sizeof(struct DataItem), 1, fp) != 0){
		flag = 1; // 标示符，假如 flag = 1 则提示用户当前没有数据记录 
		struct Date d = di.date;
		time_t seconds = getSecond(d);
		if(seconds < start || seconds > end){
			continue;
		}
		if(operation == '0'){ // 打印流水账 
			printCountInfo(di);
		}else if(di.operation == operation){		
			sum += di.money;
			printCountInfo(di);	//打印收入或支出的统计信息 
		}
	} 
	if(!flag){ // flag == 0 
		puts("当前尚不存在数据记录！\n"); 
	}
	//当操作全部是收入或者支出时，打印收入或支出总额 
	if(flag && operation != '0'){
		printf("\n这段期间%s：%lf\n\n", getOperationType(operation), sum);
	} 	
	return;
} 


/*打印统计信息*/
void printCountInfo(struct DataItem di){
	printBorder("-"); 
	printf("用户ID：\t%s\n", di.ID);
	printf("操作：\t\t%s\n", getOperationType(di.operation));
	printf("金额：\t\t%lf\n", di.money);
	printf("备注：\t\t%s\n", di.remark);
	printf("余额：\t\t%lf\n", di.balance);
	printf("日期：\t\t%d年%d月%d日\n", di.date.year, di.date.month, di.date.day);
	printBorder("-"); 	
}


/* '0','0'表示收入或者支出两种情况； '+' 或者 '-' 获取用户操作类型，收入或者支出*/
char* getOperationType(char operation){
	char* operationType;
	operationType = (char*)malloc(10);
	operationType = (operation == '+' ? "收入":"支出"); 
	return operationType;
	
}


/* 获取起止日期 */
int setDatesValue(struct Date dates[2]){
	int i; 
	char str[20];
	char tip[2][10] = {"起始", "终止"}; 
	char *tmp;
	//char delim[2] = "-";
	char *delim;
	delim = (char*)malloc(16);
	delim = "-";
	int date[3];
	for(i = 0; i < 2; i++){
		printf("请输入%s年-月-日（形如 2016-3-12）：", tip[i]);
		gets(str);
		//getchar(); 
		tmp = strtok(str, delim);
		int count = 0;  
        while(tmp != NULL){  
			date[count++] = atoi(tmp);  //将字符串转化为整数 ，标准库函数 atoi(char *) 
            tmp = strtok(NULL, delim); 
		}
		free(delim);  
		free(tmp);
		dates[i].year = date[0];
		dates[i].month = date[1];
		dates[i].day = date[2];	
		int result = judgeDate(dates[i]);  //判断日期是否合法 
		if(result == -1){  
			return -1; //日期不合法 
		}	
	} 
	return 1;
}


/*验证输入日期是否合法*/
/* 返回值是 1表示合法， -1表示不合法*/
int judgeDate(struct Date date){
	int y = date.year;
	int m = date.month;
	int d = date.day;
	
	// 年份验证 
	if(y < 1970 || y > 2100){
		puts("invalidate date.year...");
		return -1;
	}
	
	// 月份验证 
	if(m < 1 || m > 12){
		puts("invalidate date.month...");
		return -1;
	}
	
	// 日期初步验证 
	if(d < 1 || d > 31){
		puts("invalidate date.day...");
		return -1;
	}
	
	int day_31[] = {1, 3, 5, 7, 8, 10, 12};
	int day_30[] = {4, 6, 9, 11};
	int i;
	for(i = 0; i < 7; i++){
		if(m == day_31[i] && d > 31){
			puts("invalidate date.day...");
			return -1;
		}
	}
	
	for(i = 0; i < 4; i++){
		if(m == day_30[i] && d > 30){
			puts("invalidate date.day...");
			return -1;
		}
	}
	
	//平年瑞年的 2 月份日期验证 
	if((y%4 == 0 && y%100 != 0 || y % 400 == 0)){
		if(m == 2 && d > 29){
	   		puts("invalidate day");
	   		return -1;
		}
	}else{
		if(m == 2 && d > 28){
			puts("invalidate day");
			return -1;
		}
	}
	return 1;
}

