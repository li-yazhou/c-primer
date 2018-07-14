/*结构体*/ 
struct Date{
	int year;
	int month;
	int day;
};


struct DataItem{
	char ID[10];		//用户ID 
	struct Date date;  	//发生日期 
	char operation;    	//发生事件为 "+"或"-" 
	double money;		//操作金额 
	double balance;		//余额 
	char remark[20];	//备注 
}; 


struct User{
	char ID[10];
	char pass[10];
}; 
