#include <stdio.h>
int main(int argc, char const *argv[])
{
    int ch;
    // 输入的字符会被缓存起来，当按回车键后，刷新缓存中的字符，
    // 相当于输入一行字符之后显示一行字符
    while((ch = getchar()) != EOF){
        putchar(ch);
    }
    return 0;
}