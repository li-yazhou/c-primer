#include"..\header\header.h"
#include"..\header\function.h"

extern char* loginID;

//选择操作类型 
void chooseLoginOrReg(){
	char choice;
	char inputs[10];
	while(1){
		puts("请选择操作：[1-3]");	
		gets(inputs);
		if(strlen(inputs) > 1){
			puts("输入选择不合法！");
			continue;
		} 
		choice = inputs[0];
		if(choice == '1' || choice == '2'|| choice == '3'){
			break;
		}else{
			puts("输入选择不合法！"); 
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


//主界面 
void view(){
	while(1){
		LoginAndRegmenu();
		chooseLoginOrReg();
	}
	return;
}


//菜单选项 
void LoginAndRegmenu(){
	char options[3][10] = {"1.登录", "2.注册","3.退出"};
	printBorder("*");
	printf("    ");
	puts("欢迎来到小金库！");
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


//菜单选项 
void menu(){
	char options[6][10] = {"0.改密", "1.收入", "2.支出", "3.查询", "4.统计", "5.退出"};
	printBorder("*");
	printf("\t");
	printf("欢迎您,%s",loginID);
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

//选择操作类型 
void choose(char* ID){
	char choice;
	char inputs[10];
	while(1){
		puts("请选择操作：[0-5]");	
		//scanf("%c",&choice);
		//char ch = getchar(); 
		//getchar();
		//choice = ch; 
		gets(inputs);
		if(strlen(inputs) > 1){
			puts("输入选择不合法！");
			continue;
		} 
		choice = inputs[0];
		//printf("----%c\n",choice);
		if(choice == '0' ||choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5'){
			break;
		}else{
			puts("输入选择不合法！"); 
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

