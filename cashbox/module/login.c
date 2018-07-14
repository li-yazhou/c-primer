#include"..\header\header.h"
#include"..\header\function.h"
#include<time.h>

char* loginID;

/*用户登录*/ 
void login(){
	struct User user;
	while(1){
		puts("请输入账号：");	
		gets(user.ID);
		strcpy(user.pass, "");
		if(strlen(user.ID) > 10 || strlen(user.ID) == 0){
			puts("输入账号不存在！");
			return;
		} 
		int result = existUser(user); 
		if(result == -1){
			puts("该账号不存在！");
			return; 
		}
		
		puts("请输入账号密码：");	
		inputPass(user.pass);
		if(strlen(user.pass) > 10 || strlen(user.pass) == 0){
			puts("\n输入密码不正确！");
			return;
		} 
		result = existUser(user);
		if(result == -1){
			puts("\n密码不正确！");
			return; 
		}
		break;
	}
	
	loginID = (char*)malloc(sizeof(user.ID));
	strcpy(loginID, user.ID);
	
	system("cls");
	/*跳转入业务界面*/ 
	while(1){
		menu();
		choose();	
	} 
	return; 
}
