/************ͷ�ļ�����************/
#include"struct.h"  
#include<time.h> 


/*************��������*************/ 

/*testԴ�ļ����Ժ���*/ 
void test01(); //���Խṹ�� 
void test02(); //���Ա����ļ��Ƿ�ɹ� 


/*toolԴ�ļ����ߺ���*/
struct Date getDate();
void saveDataItem(struct DataItem di);
int isExistDataItem(char* ID); 
struct DataItem getLastDataItem(char* ID);
int isExist(char* ID);
char*  getFilenameByID(char* ID);
void printBorder(char* str);
//time_t getSecond(struct Date* date);
time_t getSecond(struct Date date);


/*module�ļ��й��ܺ���*/ 
//incomeԴ�ļ�
void income();
double findLastBalance(char* ID);
void printIncomeInfo(struct DataItem di, double lastBalance);


//expendԴ�ļ� 
void expend();
void printExpendInfo(struct DataItem di, double lastBalance);

//countԴ�ļ� 
void count();
int countView(char* ID);
void printCountMenu();
void chooseCountOption(char* ID);
void countIncome(char* ID);
void countExpend(char* ID);
void printLog(char* ID);

char* getOperationType(char operation);
void printCountInfo(struct DataItem di);
void countInfo(char* ID, char operation, struct Date dates[2]);
int setDatesValue(struct Date dates[2]);
int judeDate(struct Date date); 


//quitԴ�ļ� 
void quit(); 


/*viewԴ�ļ���ͼ����*/
void view(); 
void menu();
void choose(); 
void chooseLoginOrReg();
void LoginAndRegmenu(); 


/*registerԴ�ļ��к���*/
void saveUserInfo(struct User user); 
int existUser(struct User user);
void inputPass(char pass[10]); 


/*loginԴ�ļ�*/
void login(); 


/*updatePassԴ�ļ�*/
void updatePass();
void updateUserInfo(struct User user);



