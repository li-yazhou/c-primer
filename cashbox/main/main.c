#include"..\header\header.h"
#include"..\header\function.h"
#include<math.h>

/**
1.С������Ϣͳһ��������ļ��У�������ļ�����������
  ��¼�ɣġ����������ڣ������¼�����������������Ϣ��
  ÿ��¼һ����֧���ļ�Ҫ����һ����¼��������һ�����
  
2.����ɴ������ļ�������������֧����Ϣ���ɽ��и��ֲ�ѯ��ͳ�ƣ������ˮ�˵���Ϣ��

3.��ϵͳҪ��ͨ���ԡ��������ۡ��������㡣Ҫ����ϵͳ��ȫ��
1

4.�������������õĹ��ܡ�
*/

/*
˵����ÿ���û�����һ���������ļ����ڱ����Լ������ݣ��ļ���ΪID_log.txt 
*/ 

//��������������� 
int main(){
	view();
//	removetest();
	return 0;
}


void test01(){
	int d = rename("data/userdata/user_bak.db", "data/userdata/user.db");
	printf("%d", d); 
	FILE *fp, *fp_bak;
	fp = fopen("data/userdata/user.db", "rb");
//	fp_bak = fopen("data/userdata/user_bak.db", "rb");
	struct User user;
	struct User u;
	fread(&user, sizeof(struct User), 1, fp);
//	fread(&u, sizeof(struct User), 1, fp_bak);
	printf("%s:%s\n",user.ID, user.pass);
	puts("---------------");
//	printf("%s:%s", u.ID, u.pass); 
	fclose(fp);
	fclose(fp_bak);
//	int r = remove("data/userdata/user.db");
//	printf("%d", r); 
//	int d = rename("data/userdata/user_bak.db", "data/userdata/user.db");
//	printf("%d", d); 
}







