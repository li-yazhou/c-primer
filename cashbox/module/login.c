#include"..\header\header.h"
#include"..\header\function.h"
#include<time.h>

char* loginID;

/*�û���¼*/ 
void login(){
	struct User user;
	while(1){
		puts("�������˺ţ�");	
		gets(user.ID);
		strcpy(user.pass, "");
		if(strlen(user.ID) > 10 || strlen(user.ID) == 0){
			puts("�����˺Ų����ڣ�");
			return;
		} 
		int result = existUser(user); 
		if(result == -1){
			puts("���˺Ų����ڣ�");
			return; 
		}
		
		puts("�������˺����룺");	
		inputPass(user.pass);
		if(strlen(user.pass) > 10 || strlen(user.pass) == 0){
			puts("\n�������벻��ȷ��");
			return;
		} 
		result = existUser(user);
		if(result == -1){
			puts("\n���벻��ȷ��");
			return; 
		}
		break;
	}
	
	loginID = (char*)malloc(sizeof(user.ID));
	strcpy(loginID, user.ID);
	
	system("cls");
	/*��ת��ҵ�����*/ 
	while(1){
		menu();
		choose();	
	} 
	return; 
}
