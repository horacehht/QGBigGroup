#include<stdio.h>
#include"..\Headers\LinkStack.h"
LinkStack s;
int main()
{
    char str;
    while (1)
    {
        showmenu();
        scanf("%c",&str);
        getchar();
        choice(str,&s);
    }    
    return 0;
}