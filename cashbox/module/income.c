#include"..\header\header.h"
#include"..\header\function.h"
extern char* loginID;  // ����Ϊ�ⲿ���� ����login.c�ļ��ж����ȫ�ֱ��� 

//���� 
void income(){
	puts("1.income option");
	struct DataItem di;
	struct Date dt;
	dt = getDate();
	di.date = dt; //TODO, getDate()������Ҫ���� 
	strcpy(di.ID, loginID); 
	di.operation = '+'; 
	puts("�����������");
	scanf("%lf", &di.money);
	getchar();
	puts("������������Դ��");
	gets(di.remark); 
	double lastBalance = findLastBalance(di.ID);
	di.balance =  lastBalance + di.money;
	saveDataItem(di);
	printIncomeInfo(di, lastBalance); 

}

/*print the info of income operation*/
void printIncomeInfo(struct DataItem di, double lastBalance){
	system("cls");
	printBorder("-");
	puts("��������������£�");
	printf("ID:\t\t%s\n",di.ID); 
	printf("֮ǰ���:\t%.2lf\n",lastBalance);
	printf("����:\t\t%c %.2lf\n",di.operation, di.money);
	printf("���:\t\t%.2lf\n", di.balance);
	printf("��ע:\t\t%s\n", di.remark);
	printf("���ڣ�\t\t%d��%d��%d��\n\n",di.date.year,di.date.month,di.date.day);
	printBorder("-");
	puts("\n");	
}

/*��ѯ�����µ���� �������֧������Ҫʹ��������� */
double findLastBalance(char* ID){
	struct DataItem di;
	di = getLastDataItem(ID);
	//�û���һ�β���������� 0.0 
	return di.balance;
}





