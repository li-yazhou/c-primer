#include"..\header\header.h"
#include"..\header\function.h"

extern char* loginID;

//ѡ��������� 
void chooseLoginOrReg(){
	char choice;
	char inputs[10];
	while(1){
		puts("��ѡ�������[1-3]");	
		gets(inputs);
		if(strlen(inputs) > 1){
			puts("����ѡ�񲻺Ϸ���");
			continue;
		} 
		choice = inputs[0];
		if(choice == '1' || choice == '2'|| choice == '3'){
			break;
		}else{
			puts("����ѡ�񲻺Ϸ���"); 
			continue;
		}
	}
	
	switch(choice){
		case '1':
			login();
			break;
		case '2':
			registerUser();
			break; 
		case '3':
			quit();
	}
	return;
}


//������ 
void view(){
	while(1){
		LoginAndRegmenu();
		chooseLoginOrReg();
	}
	return;
}


//�˵�ѡ�� 
void LoginAndRegmenu(){
	char options[3][10] = {"1.��¼", "2.ע��","3.�˳�"};
	printBorder("*");
	printf("    ");
	puts("��ӭ����С��⣡");
	printBorder("-"); 
	int i;
	for(i = 0; i < 3; i++){
		printf("\t");
		printf(options[i]);
		printf("\n");
	} 
	printBorder("*");
	return;	
}


//�˵�ѡ�� 
void menu(){
	char options[6][10] = {"0.����", "1.����", "2.֧��", "3.��ѯ", "4.ͳ��", "5.�˳�"};
	printBorder("*");
	printf("\t");
	printf("��ӭ��,%s",loginID);
	printf("\n");
	printBorder("-");
	int i;
	for(i = 0; i < 6; i++){
		printf("\t");
		printf(options[i]);
		printf("\n");
	} 
	printBorder("*");
	return;	
}

//ѡ��������� 
void choose(char* ID){
	char choice;
	char inputs[10];
	while(1){
		puts("��ѡ�������[0-5]");	
		//scanf("%c",&choice);
		//char ch = getchar(); 
		//getchar();
		//choice = ch; 
		gets(inputs);
		if(strlen(inputs) > 1){
			puts("����ѡ�񲻺Ϸ���");
			continue;
		} 
		choice = inputs[0];
		//printf("----%c\n",choice);
		if(choice == '0' ||choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5'){
			break;
		}else{
			puts("����ѡ�񲻺Ϸ���"); 
			continue;
		}
	}
	
	switch(choice){
		case '0':
			updatePass();
			break;
		case '1':
			income();
			break;
		case '2':
			expend();
			break;
		case '3':
			find();
			break;
		case '4':
			count();
			break;
		case '5':
			quit(); 
	}
	return;
}

