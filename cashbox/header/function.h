/************头文件引用************/
#include"struct.h"  
#include<time.h> 


/*************函数声明*************/ 

/*test源文件测试函数*/ 
void test01(); //测试结构体 
void test02(); //测试保存文件是否成功 


/*tool源文件工具函数*/
struct Date getDate();
void saveDataItem(struct DataItem di);
int isExistDataItem(char* ID); 
struct DataItem getLastDataItem(char* ID);
int isExist(char* ID);
char*  getFilenameByID(char* ID);
void printBorder(char* str);
//time_t getSecond(struct Date* date);
time_t getSecond(struct Date date);


/*module文件夹功能函数*/ 
//income源文件
void income();
double findLastBalance(char* ID);
void printIncomeInfo(struct DataItem di, double lastBalance);


//expend源文件 
void expend();
void printExpendInfo(struct DataItem di, double lastBalance);

//count源文件 
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


//quit源文件 
void quit(); 


/*view源文件视图函数*/
void view(); 
void menu();
void choose(); 
void chooseLoginOrReg();
void LoginAndRegmenu(); 


/*register源文件中函数*/
void saveUserInfo(struct User user); 
int existUser(struct User user);
void inputPass(char pass[10]); 


/*login源文件*/
void login(); 


/*updatePass源文件*/
void updatePass();
void updateUserInfo(struct User user);



