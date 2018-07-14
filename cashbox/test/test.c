#include"..\header\header.h"
#include"..\header\function.h"


//测试文件保存是否成功
void test02(){
	FILE* fp;
	fp = openFile("rb");
	puts("test02...."); 
	printf("%d\n", sizeof(struct DataItem));
	struct DataItem di;
	int a = fread(&di, sizeof(struct DataItem), 1, fp);
	printf("%d",a);
	printf("%lf", di.balance);
	printf("%d",di.date.year);
	fclose(fp);
} 

// 测试函数 
void test01(){
	struct DataItem dataItem;
	puts("输入ID："); 
	gets(dataItem.ID);
	getchar(); 
	struct Date date;
	date.year = 2016;
	date.month = 3;
	date.day = 9;
	dataItem.date = date; 
	dataItem.money = 100.0;
	dataItem.balance = 1900.0;
	
	printf(dataItem.ID);
} 


