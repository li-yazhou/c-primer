#include"..\header\header.h"
#include"..\header\function.h"
#include<time.h>
#include <conio.h>
#include <ctype.h>


/*新用户注册*/
/*注册界面*/
void registerUser(){
	struct User user;
	while(1){
		puts("请输入新账号：");	
		gets(user.ID);
		strcpy(user.pass, ""); 
		if(strlen(user.ID) > 10 || strlen(user.ID) == 0){
			puts("输入账号不合法！");
			continue;
		} 
		
		int result = existUser(user);
		if(result == 1){
			puts("给账号已存在！");
			continue; 
		}
		puts("请输入账号密码：");
		char tmpPass[10];	
		inputPass(tmpPass);
		//gets(tmpPass);
		if(strlen(tmpPass) > 10 || strlen(tmpPass) == 0){
			puts("\n输入密码不合法！");
			continue;
		} 
		
		puts("\n请重新输入账号密码：");	
		inputPass(user.pass);
		//gets(user.pass);
		if(strlen(user.pass) > 10 || strlen(user.pass) == 0){
			puts("\n输入密码不合法！");
			continue;
		} 
		if(strcmp(tmpPass, user.pass) != 0){ //验证两次输入密码是否一致 
			puts("\n两次输入密码不一致！");
			continue; 
		}
		break; 
	}
	saveUserInfo(user);	 
	puts("\n恭喜你，注册成功！");
	return;
}


/*模拟星号替代输入的密码*/
void inputPass(char pass[10]){
        char pwd[10] = "";
        char temp = 0;
        int num=0;
        
        while (num<9) {
                temp = getch();  // getch()是不会显函数，在 conio.h头文件中声明 
                if (isprint(temp))  // isprint() 判断输入字符是否可打印 
                {
                        pwd[num]=temp;
                        num++;
                        putchar('*');
                }
                if (temp == '\r') {
                        break;
                }
                
                if ((temp == 8) && (num != 0)) {
                	    printf("\b \b"); //退格 
                        num--;
                        pwd[num]='\0';
                }
        }
        strcpy(pass,pwd); 
        //printf("\n%s\n", pwd);
        return;
}


/*保存用户信息*/
void saveUserInfo(struct User user){
	FILE* fp;
	fp = fopen("data/userdata/user.db", "ab");
	if(fwrite(&user, sizeof(struct User), 1, fp) != 1){
		puts("文件写入出错！\n");
		return; 
	}
	fclose(fp);
	return; 
}


/*查询用户是否存在*/
int existUser(struct User user){
	FILE* fp;
	if((fp=fopen("data/userdata/user.db", "r")) == NULL){
		return -1; 
	} 
	int result = -1 ; // -1表示用户不存在，1表示存在	
	struct User u;
	while(fread(&u, sizeof(struct User), 1, fp) != 0){
		if(strlen(user.pass) != 0){  // 同时验证账号和密码 ，登录时候使用 
			if(!strcmp(user.ID, u.ID) && !strcmp(user.pass, u.pass)){
				result = 1;
				break; 	
			}
		}else{
			if(!strcmp(user.ID, u.ID)){  // 只验证账号，注册时候使用 
				result = 1;
				break;
			}
		}
	} 
	fclose(fp);	
	return result;
} 
