#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "qgsort.h"
int main(){
    int n;
    while (1)
    {
        mainmenu();
        while (scanf("%d", &n) == 0 || getchar() != '\n')
        {
            printf("输入了非法字符，请重新输入：");
            while (getchar() != '\n');  // 清除缓存区
        }
        mainchoice(n);
    }
    return 0;
}



