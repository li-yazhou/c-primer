#include"..\header\header.h"
#include"..\header\function.h"

extern char* loginID; // ����Ϊ�ⲿ���� ����login.c�ļ��ж����ȫ�ֱ��� 

void updatePass(){
	struct User user; 
	strcpy(user.ID, loginID);
	while(1){
		puts("�����������룺"); 
		inputPass(user.pass);
		if(strlen(user.pass) > 10 || strlen(user.pass) == 0){
			puts("\n�������벻�Ϸ���");
			continue;
		} 
		puts("\n���ٴ����������룺"); 
		char tmpPass[10];	
		inputPass(tmpPass);
		if(strlen(tmpPass) > 10 || strlen(tmpPass) == 0){
			puts("\n�������벻�Ϸ���");
			continue;
		} 
		
		if(strcmp(tmpPass, user.pass) != 0){ //��֤�������������Ƿ�һ�� 
			puts("\n�����������벻һ�£�");
			continue; 
		}
		break; 
	}
	updateUserInfo(user);
	return;
} 


/*�����û�����*/
void updateUserInfo(struct User user){
	FILE *fp, *fp_bak;
	fp = fopen("data/userdata/user.db", "rb");
	fp_bak = fopen("data/userdata/user_bak.db","wb");
	struct User u;
	while(fread(&u, sizeof(struct User), 1, fp) != 0){
		// printf("\n%s---%s\n", u.ID, u.pass); 
		if(!strcmp(user.ID, u.ID)){  //����ǵ�ǰ�û����˺���Ϣ���������������Ƶ��µ��û��ļ��� 
			continue;
		}
		fwrite(&u, sizeof(struct User), 1, fp_bak); //��ԭ���ķǵ�ǰ�û���Ϣд��һ�����ļ��� 
	} 	
	fwrite(&user, sizeof(struct User), 1, fp_bak); 
	fclose(fp);
	fclose(fp_bak);
	// ɾ�� user.db �ļ����� user_bak.db �ļ������� 
	remove("data/userdata/user.db"); // unlink��ɾ��ԭ�����ļ�user.db
	rename("data/userdata/user_bak.db", "data/userdata/user.db"); //��������user_bak.db���ļ���Ϊuser.db 
	puts("\n��ϲ�㣬������ĳɹ���");
	return;
} 




