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
            printf("�����˷Ƿ��ַ������������룺");
            while (getchar() != '\n');  // ���������
        }
        mainchoice(n);
    }
    return 0;
}



