#include"..\header\header.h"
#include"..\header\function.h"

extern char* loginID; // 声明为外部变量 ，在login.c文件中定义的全局变量 

void updatePass(){
	struct User user; 
	strcpy(user.ID, loginID);
	while(1){
		puts("请输入新密码："); 
		inputPass(user.pass);
		if(strlen(user.pass) > 10 || strlen(user.pass) == 0){
			puts("\n输入密码不合法！");
			continue;
		} 
		puts("\n请再次输入新密码："); 
		char tmpPass[10];	
		inputPass(tmpPass);
		if(strlen(tmpPass) > 10 || strlen(tmpPass) == 0){
			puts("\n输入密码不合法！");
			continue;
		} 
		
		if(strcmp(tmpPass, user.pass) != 0){ //验证两次输入密码是否一致 
			puts("\n两次输入密码不一致！");
			continue; 
		}
		break; 
	}
	updateUserInfo(user);
	return;
} 


/*更改用户密码*/
void updateUserInfo(struct User user){
	FILE *fp, *fp_bak;
	fp = fopen("data/userdata/user.db", "rb");
	fp_bak = fopen("data/userdata/user_bak.db","wb");
	struct User u;
	while(fread(&u, sizeof(struct User), 1, fp) != 0){
		// printf("\n%s---%s\n", u.ID, u.pass); 
		if(!strcmp(user.ID, u.ID)){  //如果是当前用户的账号信息，则跳过，不复制到新的用户文件中 
			continue;
		}
		fwrite(&u, sizeof(struct User), 1, fp_bak); //把原来的非当前用户信息写到一个新文件中 
	} 	
	fwrite(&user, sizeof(struct User), 1, fp_bak); 
	fclose(fp);
	fclose(fp_bak);
	// 删除 user.db 文件，对 user_bak.db 文件重命名 
	remove("data/userdata/user.db"); // unlink，删除原来的文件user.db
	rename("data/userdata/user_bak.db", "data/userdata/user.db"); //重新命名user_bak.db新文件名为user.db 
	puts("\n恭喜你，密码更改成功！");
	return;
} 




