#include<stdio.h>
#include<time.h>

int main(){
	
	struct tm *tmptr;
	time_t secnow;
	time(&secnow);
	tmptr = localtime(&secnow);
	
	
	int year, month, day, hour1, min1;
	year = tmptr->tm_year;
	month = tmptr->tm_mon;
	day = tmptr->tm_mday;
	
	hour1 = tmptr->tm_hour;
	min1 = tmptr->tm_min;
	
	printf("%d\n", year+1900);
	printf("%d\n", month + 1);
	printf("%d\n", day);
	printf("%d\n", hour1);
	printf("%d\n", min1);
	return 0;
}
