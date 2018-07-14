#include"..\header\header.h"
#include"..\header\function.h"

/*��ĳ�ַ�ʽ���ļ� */
FILE* openFile(char* ID,char* openMode){
	FILE * fp;
	//char* filename = getFilenameByID(ID);
	char filename[50] = "";
	strcat(filename,"data/logdata/");
	strcat(filename, ID);
	strcat(filename, "_log.db");
	if((fp = fopen(filename, openMode)) == NULL){
		puts("���ļ��޷��򿪣�\n");
		//return; 
	}
	return fp;
}


/*����������¼���ļ��У������֧������������Ҫ������� */
void saveDataItem(struct DataItem di){
	FILE* fp;
	fp = openFile(di.ID, "ab");
	if(fwrite(&di, sizeof(struct DataItem), 1, fp) != 1){
		puts("�ļ�д�����\n");
		return; 
	}
	fclose(fp);
	return; 
}



//��ȡϵͳ��ǰ���� ,��time.h�еķ�����ʵ�� 
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


/*�ж��Ƿ����������*/
/*����ֵ -1 ��ʾ�����ڣ�1 ��ʾ����*/ 
int isExistDataItem(char* ID){
	FILE* fp;
	//�˴��ļ���ģʽ�� "ab+"���ܹ���д�����ļ������ڿ��Դ���������򲻿� 
	fp = openFile(ID,"ab+");
	char isnull;//�ж��ļ������Ƿ�Ϊ�� 
	isnull = fgetc(fp); 
	if(isnull == EOF){ // EOF����-1 
		return -1;
	}
} 

/*��ȡ���ļ������һ����µļ�¼��������ļ�Ϊ�գ������ļ���return*/ 
//��ѯ�����˻�������Ϣ����ʹ�� 
struct DataItem getLastDataItem(char* ID){
	struct DataItem di;
	FILE* fp;
	//�˴��ļ���ģʽ�� "ab+"���ܹ���д�����ļ������ڿ��Դ���������򲻿� 
	fp = openFile(ID,"ab+");
	//���ļ�ָ���ƶ������һ��������Ŀ�ͷ��
	//2��ʾ���ļ�ĩβ��ʼ�ƶ�ָ�� 
	fseek(fp,-sizeof(struct DataItem), 2);
	fread(&di, sizeof(struct DataItem), 1, fp);
	fclose(fp); // close the file after read or write
	return di;
} 


/*�ж��ļ��Ƿ����*/
int isExist(char* filename){
	int retval = 1;//����ü�¼�ļ�Ĭ�ϴ��ڣ�1��ʾ���ڣ�0��ʾ������
//	char filename[50] = "";
//	strcat(filename,"logdata/");
//	strcat(filename, ID);
//	strcat(filename, "_log.db");
	FILE *fp;	
	if((fp = fopen(filename, "r")) == NULL){
		//���ļ��򲻿�����ʾ�ļ�������
		retval = 0; 
	} 
	fclose(fp);
	return retval;	
}


/*get filename by userid*/
/* this function may lead leak of internal storage, wait for improving*/
/*char * getFilenameByID(char* ID){
	//�û��������ļ�����ʽ�ǣ�ID_log.db,�ļ�·���� logdata/ID_log.db 
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


/*��ȡ1970�굽�����ڵ�����*/ 
//time_t getSecond(struct Date* date){
//	//printf("%d-%d-%d\n", date.year, date.month, date.day);
//	struct tm *t;
//	t->tm_year = date->year - 1900;	
//	t->tm_mon = date->month - 1;	 
//	t->tm_mday = date->day;
//	t->tm_hour = 0;
//	t->tm_min = 0;
//	t->tm_sec = 0;
//	time_t seconds = mktime(t); //��ȡ1970�굽�����ڵ����� 
//	//free(t);
//	printf("%ld", seconds);
////	printf("%s", ctime(&seconds));
//	return seconds;
//} 


/*��ȡ1970�굽�����ڵ�����*/ 
time_t getSecond(struct Date date){
	//printf("%d-%d-%d\n", date.year, date.month, date.day);
//	struct tm *t;
//	t->tm_year = date.year - 1900;	
//	t->tm_mon = date.month - 1;	 
//	t->tm_mday = date.day;
//	t->tm_hour = 0;
//	t->tm_min = 0;
//	t->tm_sec = 0;
//	time_t seconds = mktime(t); //��ȡ1970�굽�����ڵ����� 
//	free(t);
	struct tm t;
	t.tm_year = date.year - 1900;	
	t.tm_mon = date.month - 1;	 
	t.tm_mday = date.day;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	time_t seconds = mktime(&t); //��ȡ1970�굽�����ڵ����� 
	// free(&t);
	//printf("%ld", seconds);
	return seconds;
} 



