#include"..\header\header.h"
#include"..\header\function.h"

/*以某种方式打开文件 */
FILE* openFile(char* ID,char* openMode){
	FILE * fp;
	//char* filename = getFilenameByID(ID);
	char filename[50] = "";
	strcat(filename,"data/logdata/");
	strcat(filename, ID);
	strcat(filename, "_log.db");
	if((fp = fopen(filename, openMode)) == NULL){
		puts("该文件无法打开！\n");
		//return; 
	}
	return fp;
}


/*保存这条记录到文件中，收入和支出两个功能需要这个函数 */
void saveDataItem(struct DataItem di){
	FILE* fp;
	fp = openFile(di.ID, "ab");
	if(fwrite(&di, sizeof(struct DataItem), 1, fp) != 1){
		puts("文件写入出错！\n");
		return; 
	}
	fclose(fp);
	return; 
}



//获取系统当前日期 ,用time.h中的方法来实现 
struct Date getDate(){
	struct Date date;	
	struct tm *tmptr;
	time_t secnow;
	time(&secnow); // get current system time
	tmptr = localtime(&secnow); 
	date.year = tmptr->tm_year + 1900;
	date.month = tmptr->tm_mon + 1;
	date.day = tmptr->tm_mday;
	return date;
}


/*判断是否存在数据项*/
/*返回值 -1 表示不存在，1 表示存在*/ 
int isExistDataItem(char* ID){
	FILE* fp;
	//此处文件打开模式是 "ab+"，能够读写，当文件不存在可以创建，否则打不开 
	fp = openFile(ID,"ab+");
	char isnull;//判断文件内容是否为空 
	isnull = fgetc(fp); 
	if(isnull == EOF){ // EOF即是-1 
		return -1;
	}
} 

/*获取到文件中最后一项（最新的记录），如果文件为空，创建文件并return*/ 
//查询余额和账户最新信息函数使用 
struct DataItem getLastDataItem(char* ID){
	struct DataItem di;
	FILE* fp;
	//此处文件打开模式是 "ab+"，能够读写，当文件不存在可以创建，否则打不开 
	fp = openFile(ID,"ab+");
	//把文件指针移动到最后一个数据项的开头处
	//2表示从文件末尾开始移动指针 
	fseek(fp,-sizeof(struct DataItem), 2);
	fread(&di, sizeof(struct DataItem), 1, fp);
	fclose(fp); // close the file after read or write
	return di;
} 


/*判断文件是否存在*/
int isExist(char* filename){
	int retval = 1;//假设该记录文件默认存在，1表示存在，0表示不存在
//	char filename[50] = "";
//	strcat(filename,"logdata/");
//	strcat(filename, ID);
//	strcat(filename, "_log.db");
	FILE *fp;	
	if((fp = fopen(filename, "r")) == NULL){
		//此文件打不开，表示文件不存在
		retval = 0; 
	} 
	fclose(fp);
	return retval;	
}


/*get filename by userid*/
/* this function may lead leak of internal storage, wait for improving*/
/*char * getFilenameByID(char* ID){
	//用户的数据文件名格式是：ID_log.db,文件路径是 logdata/ID_log.db 
	char filename[50] = "";
	strcat(filename,"logdata/");
	strcat(filename, ID);
	strcat(filename, "_log.db");
	puts("------------");
	puts(filename);
	return filename;
}
*/


/*print border of info*/
void printBorder(char* str){
	int i;
	for(i = 0; i < 25; i++){
		printf(str);
	}
	printf("\n");
	return;
}


/*获取1970年到该日期的秒数*/ 
//time_t getSecond(struct Date* date){
//	//printf("%d-%d-%d\n", date.year, date.month, date.day);
//	struct tm *t;
//	t->tm_year = date->year - 1900;	
//	t->tm_mon = date->month - 1;	 
//	t->tm_mday = date->day;
//	t->tm_hour = 0;
//	t->tm_min = 0;
//	t->tm_sec = 0;
//	time_t seconds = mktime(t); //获取1970年到该日期的秒数 
//	//free(t);
//	printf("%ld", seconds);
////	printf("%s", ctime(&seconds));
//	return seconds;
//} 


/*获取1970年到该日期的秒数*/ 
time_t getSecond(struct Date date){
	//printf("%d-%d-%d\n", date.year, date.month, date.day);
//	struct tm *t;
//	t->tm_year = date.year - 1900;	
//	t->tm_mon = date.month - 1;	 
//	t->tm_mday = date.day;
//	t->tm_hour = 0;
//	t->tm_min = 0;
//	t->tm_sec = 0;
//	time_t seconds = mktime(t); //获取1970年到该日期的秒数 
//	free(t);
	struct tm t;
	t.tm_year = date.year - 1900;	
	t.tm_mon = date.month - 1;	 
	t.tm_mday = date.day;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	time_t seconds = mktime(&t); //获取1970年到该日期的秒数 
	// free(&t);
	//printf("%ld", seconds);
	return seconds;
} 



