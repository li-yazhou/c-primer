#include"..\header\header.h"
#include"..\header\function.h"
extern char* loginID;  // ����Ϊ�ⲿ���� ����login.c�ļ��ж����ȫ�ֱ��� 

void expend(){
	puts("2.expend option");
	struct DataItem di;
	struct Date dt;
	dt = getDate();
	di.date = dt; //TODO, getDate()������Ҫ���� 
	strcpy(di.ID,loginID);
	
	di.operation = '-'; 
	puts("������֧����");
	scanf("%lf", &di.money);
	getchar(); // accept the keyborad of Enter
	puts("������֧��ԭ��");
	gets(di.remark);
	double lastBalance = findLastBalance(di.ID);
	if(lastBalance < di.money){
		puts("�Բ�������!\n");
		return; 
	} 
	di.balance =  lastBalance - di.money;
	printExpendInfo(di, lastBalance);// print the information of expend	
	return;	
} 

/*print the info of expend*/
void printExpendInfo(struct DataItem di, double lastBalance){
	system("cls");
	printBorder("-");
	puts("��������������£�");
	printf("ID:\t\t%s\n",di.ID); 
	printf("֮ǰ���:\t%.2lf\n",lastBalance);
	printf("����:\t\t%c %.2lf\n",di.operation, di.money);
	printf("֧��ԭ��:\t%s\n",di.remark);
	printf("���:\t\t%.2lf\n", di.balance);
	printf("���ڣ�\t\t%d��%d��%d��\n\n",di.date.year,di.date.month,di.date.day);
	printBorder("-");
	puts("\n");
	saveDataItem(di);
	
}
