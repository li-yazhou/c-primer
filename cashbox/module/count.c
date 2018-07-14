#include"..\header\header.h"
#include"..\header\function.h"
#include<time.h>

extern char* loginID; // ����Ϊ�ⲿ���� ����login.c�ļ��ж����ȫ�ֱ��� 

/*ͳ��*/
void count(){
	puts("4. count option."); 
	//ͳ�Ʋ��� 
	int retval = countView(loginID);
	if(retval == 0){
		return;
	} 
}

/*ͳ�ƽ�������*/
/*���� 0 ����һ��Ҳ����return��������ֹͳ�Ʋ�����������Զ�β�ѯ*/
int countView(char* ID){
	while(1){
		puts("����Y����y��ѯ�������˳�ͳ��");
		char inputs[10];
		gets(inputs);
		
		if(strlen(inputs) > 1){
			return 0;
		} 
		
		if(inputs[0] == 'Y' || inputs[0] == 'y'){
			printCountMenu();		
			chooseCountOption(ID);
		}else{
			puts("");  //���� 
			return 0;
		}
	 
	} 
}


/*��ӡͳ�Ʋ˵�����*/ 
void printCountMenu(){
	//���Էŵ���ѯ���ܣ�findԴ�ļ������� 
	char options[3][20] = {"a.ͳ������", "b.ͳ��֧��", "c.��ˮ��"};
	printBorder("*");
	int i;
	for(i = 0; i < 3; i++){
		printf("\t");		
		printf(options[i]);
		printf("\n");
	} 
	printBorder("*");
	return;		
}


/*ѡ��ͳ��ѡ��*/
void chooseCountOption(char* ID){
	char choice;
	char inputs[10];
	while(1){
		puts("��ѡ�������[a/b/c]");	 
		gets(inputs);
		if(strlen(inputs) > 1){
			puts("����ѡ�񲻺Ϸ���");
			continue;
		} 
		choice = inputs[0];
		if(choice == 'a' || choice == 'b' || choice == 'c'){
			break;
		}else{
			puts("����ѡ�񲻺Ϸ���"); 
			continue;
		}
	}
	
	switch(choice){
		case 'a':
			countIncome(ID);
			break;
		case 'b':
			countExpend(ID);
			break;
		case 'c':
			printLog(ID);
			break;
	}		
	return;	
}


/*ͳ���������*/
void countIncome(char* ID){
	puts("countIncome"); 
	struct Date dates[2]; // �����û��������ֹ���� 
	int result = setDatesValue(dates);
	if(result == -1){
		return;
	}
	countInfo(ID, '+', dates);  // û�����ʱ���������ͳ�����е������¼ 
	return;
}


/*ͳ��֧�����*/ 
void countExpend(char* ID){
	puts("countExpend");
	// ���û�������ֹ���� ,�ֱ𱣴浽 dates[0],dates[1]�� 
	struct Date dates[2];
	int result = setDatesValue(dates);
	if(result == -1){
		return;
	}
	countInfo(ID,'-',dates);
	return;
} 


/*��ӡ�û�����ˮ��*/
void printLog(char* ID){
	puts("printLog");
	// ���û�������ֹ���� ,�ֱ𱣴浽 dates[0],dates[1]�� 
	struct Date dates[2];
	int result = setDatesValue(dates);
	if(result == -1){
		return;
	}
	countInfo(ID, '0', dates); //��ӡ��ˮ�ˣ������е������֧����Ϣ 
	return;
}


void countInfo(char* ID, char operation, struct Date dates[2]){	
	int flag = 0; // ��ʶ������������ flag = 0 ˵��û�м�¼ 
	FILE* fp;
	fp = openFile(ID, "ab+");
	struct DataItem di;
	double sum;
	sum = 0;

	time_t start = getSecond(dates[0]); //��ǰ���ڵ�1970-1-1 00:00:00������ 
	time_t end = getSecond(dates[1]);  //��ǰ���ڵ�1970-1-1 00:00:00������ 
	
	if(start > end){ // ��ʼ���ڱ���ֹ���ڴ��򲻺ϸ� 
		puts("������ֹ���ڲ��ϸ�");
		return; 
	}
	
	system("cls"); 
	puts("ͳ����Ϣ���£�"); 
	while(fread(&di, sizeof(struct DataItem), 1, fp) != 0){
		flag = 1; // ��ʾ�������� flag = 1 ����ʾ�û���ǰû�����ݼ�¼ 
		struct Date d = di.date;
		time_t seconds = getSecond(d);
		if(seconds < start || seconds > end){
			continue;
		}
		if(operation == '0'){ // ��ӡ��ˮ�� 
			printCountInfo(di);
		}else if(di.operation == operation){		
			sum += di.money;
			printCountInfo(di);	//��ӡ�����֧����ͳ����Ϣ 
		}
	} 
	if(!flag){ // flag == 0 
		puts("��ǰ�в��������ݼ�¼��\n"); 
	}
	//������ȫ�����������֧��ʱ����ӡ�����֧���ܶ� 
	if(flag && operation != '0'){
		printf("\n����ڼ�%s��%lf\n\n", getOperationType(operation), sum);
	} 	
	return;
} 


/*��ӡͳ����Ϣ*/
void printCountInfo(struct DataItem di){
	printBorder("-"); 
	printf("�û�ID��\t%s\n", di.ID);
	printf("������\t\t%s\n", getOperationType(di.operation));
	printf("��\t\t%lf\n", di.money);
	printf("��ע��\t\t%s\n", di.remark);
	printf("��\t\t%lf\n", di.balance);
	printf("���ڣ�\t\t%d��%d��%d��\n", di.date.year, di.date.month, di.date.day);
	printBorder("-"); 	
}


/* '0','0'��ʾ�������֧����������� '+' ���� '-' ��ȡ�û��������ͣ��������֧��*/
char* getOperationType(char operation){
	char* operationType;
	operationType = (char*)malloc(10);
	operationType = (operation == '+' ? "����":"֧��"); 
	return operationType;
	
}


/* ��ȡ��ֹ���� */
int setDatesValue(struct Date dates[2]){
	int i; 
	char str[20];
	char tip[2][10] = {"��ʼ", "��ֹ"}; 
	char *tmp;
	//char delim[2] = "-";
	char *delim;
	delim = (char*)malloc(16);
	delim = "-";
	int date[3];
	for(i = 0; i < 2; i++){
		printf("������%s��-��-�գ����� 2016-3-12����", tip[i]);
		gets(str);
		//getchar(); 
		tmp = strtok(str, delim);
		int count = 0;  
        while(tmp != NULL){  
			date[count++] = atoi(tmp);  //���ַ���ת��Ϊ���� ����׼�⺯�� atoi(char *) 
            tmp = strtok(NULL, delim); 
		}
		free(delim);  
		free(tmp);
		dates[i].year = date[0];
		dates[i].month = date[1];
		dates[i].day = date[2];	
		int result = judgeDate(dates[i]);  //�ж������Ƿ�Ϸ� 
		if(result == -1){  
			return -1; //���ڲ��Ϸ� 
		}	
	} 
	return 1;
}


/*��֤���������Ƿ�Ϸ�*/
/* ����ֵ�� 1��ʾ�Ϸ��� -1��ʾ���Ϸ�*/
int judgeDate(struct Date date){
	int y = date.year;
	int m = date.month;
	int d = date.day;
	
	// �����֤ 
	if(y < 1970 || y > 2100){
		puts("invalidate date.year...");
		return -1;
	}
	
	// �·���֤ 
	if(m < 1 || m > 12){
		puts("invalidate date.month...");
		return -1;
	}
	
	// ���ڳ�����֤ 
	if(d < 1 || d > 31){
		puts("invalidate date.day...");
		return -1;
	}
	
	int day_31[] = {1, 3, 5, 7, 8, 10, 12};
	int day_30[] = {4, 6, 9, 11};
	int i;
	for(i = 0; i < 7; i++){
		if(m == day_31[i] && d > 31){
			puts("invalidate date.day...");
			return -1;
		}
	}
	
	for(i = 0; i < 4; i++){
		if(m == day_30[i] && d > 30){
			puts("invalidate date.day...");
			return -1;
		}
	}
	
	//ƽ������� 2 �·�������֤ 
	if((y%4 == 0 && y%100 != 0 || y % 400 == 0)){
		if(m == 2 && d > 29){
	   		puts("invalidate day");
	   		return -1;
		}
	}else{
		if(m == 2 && d > 28){
			puts("invalidate day");
			return -1;
		}
	}
	return 1;
}

