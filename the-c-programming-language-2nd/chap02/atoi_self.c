
#include <stdio.h>
#include <string.h>

/********************************************************************************
将字符数组转为整数
********************************************************************************/
int atoi(char s[]){
    int i, n;
    n = 0;
    /* 不必知道数组的长度 */ 
    for(i = 0; s[i] > '0' && s[i] < '9'; ++i){
        n = n * 10 + (s[i] - '0'); 
    }
    return n;
}


int main(int argc, char const *argv[])
{
    char s[] = "215";
    int n = atoi(s);
    printf("s = %s, n = %d", s, n);
    return 0;
}

