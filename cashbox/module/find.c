#include"..\header\header.h"
#include"..\header\function.h"

extern char* loginID;  // ����Ϊ�ⲿ���� ����login.c�ļ��ж����ȫ�ֱ��� 

//��ѯ�˻�������Ϣ 
void find(){
	puts("3.find option");
	struct Date date;
	struct DataItem di;
	int result = isExistDataItem(loginID);
	if(result == -1){
		puts("��ʱû�����ݼ�¼��");
		return; 
	} 
	di = getLastDataItem(loginID);
	system("cls");
	printBorder("-");
	puts("���û�������Ϣ���£�");
	printf("ID:\t\t%s\n",di.ID); 
	printf("����:\t\t%c %.2lf\n",di.operation, di.money);
	printf("��ע:\t\t%s\n", di.remark);
	printf("���:\t\t%.2lf\n", di.balance);
	printf("���ڣ�\t\t%d��%d��%d��\n\n",di.date.year,di.date.month,di.date.day);
	printBorder("-");
	puts("\n");
	return;	 
} 





