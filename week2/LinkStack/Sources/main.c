#include<stdlib.h>
#include<stdio.h>
#include".\LinkStack.h"

int main()
{
    char str;
    while (1)
    {
        showmenu();
        scanf("%c",&str);
        getchar();
        choice(str);
    }    
    return 0;
}