#include"..\header\header.h"
#include"..\header\function.h"
#include<time.h>
#include <conio.h>
#include <ctype.h>


/*���û�ע��*/
/*ע�����*/
void registerUser(){
	struct User user;
	while(1){
		puts("���������˺ţ�");	
		gets(user.ID);
		strcpy(user.pass, ""); 
		if(strlen(user.ID) > 10 || strlen(user.ID) == 0){
			puts("�����˺Ų��Ϸ���");
			continue;
		} 
		
		int result = existUser(user);
		if(result == 1){
			puts("���˺��Ѵ��ڣ�");
			continue; 
		}
		puts("�������˺����룺");
		char tmpPass[10];	
		inputPass(tmpPass);
		//gets(tmpPass);
		if(strlen(tmpPass) > 10 || strlen(tmpPass) == 0){
			puts("\n�������벻�Ϸ���");
			continue;
		} 
		
		puts("\n�����������˺����룺");	
		inputPass(user.pass);
		//gets(user.pass);
		if(strlen(user.pass) > 10 || strlen(user.pass) == 0){
			puts("\n�������벻�Ϸ���");
			continue;
		} 
		if(strcmp(tmpPass, user.pass) != 0){ //��֤�������������Ƿ�һ�� 
			puts("\n�����������벻һ�£�");
			continue; 
		}
		break; 
	}
	saveUserInfo(user);	 
	puts("\n��ϲ�㣬ע��ɹ���");
	return;
}


/*ģ���Ǻ�������������*/
void inputPass(char pass[10]){
        char pwd[10] = "";
        char temp = 0;
        int num=0;
        
        while (num<9) {
                temp = getch();  // getch()�ǲ����Ժ������� conio.hͷ�ļ������� 
                if (isprint(temp))  // isprint() �ж������ַ��Ƿ�ɴ�ӡ 
                {
                        pwd[num]=temp;
                        num++;
                        putchar('*');
                }
                if (temp == '\r') {
                        break;
                }
                
                if ((temp == 8) && (num != 0)) {
                	    printf("\b \b"); //�˸� 
                        num--;
                        pwd[num]='\0';
                }
        }
        strcpy(pass,pwd); 
        //printf("\n%s\n", pwd);
        return;
}


/*�����û���Ϣ*/
void saveUserInfo(struct User user){
	FILE* fp;
	fp = fopen("data/userdata/user.db", "ab");
	if(fwrite(&user, sizeof(struct User), 1, fp) != 1){
		puts("�ļ�д�����\n");
		return; 
	}
	fclose(fp);
	return; 
}


/*��ѯ�û��Ƿ����*/
int existUser(struct User user){
	FILE* fp;
	if((fp=fopen("data/userdata/user.db", "r")) == NULL){
		return -1; 
	} 
	int result = -1 ; // -1��ʾ�û������ڣ�1��ʾ����	
	struct User u;
	while(fread(&u, sizeof(struct User), 1, fp) != 0){
		if(strlen(user.pass) != 0){  // ͬʱ��֤�˺ź����� ����¼ʱ��ʹ�� 
			if(!strcmp(user.ID, u.ID) && !strcmp(user.pass, u.pass)){
				result = 1;
				break; 	
			}
		}else{
			if(!strcmp(user.ID, u.ID)){  // ֻ��֤�˺ţ�ע��ʱ��ʹ�� 
				result = 1;
				break;
			}
		}
	} 
	fclose(fp);	
	return result;
} 
