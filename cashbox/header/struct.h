/*�ṹ��*/ 
struct Date{
	int year;
	int month;
	int day;
};


struct DataItem{
	char ID[10];		//�û�ID 
	struct Date date;  	//�������� 
	char operation;    	//�����¼�Ϊ "+"��"-" 
	double money;		//������� 
	double balance;		//��� 
	char remark[20];	//��ע 
}; 


struct User{
	char ID[10];
	char pass[10];
}; 
