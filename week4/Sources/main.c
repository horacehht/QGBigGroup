#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "qgsort.h"
/*rewind(fp);//让文件指针回到文件开头
int read[size];//储存读入数字的数组
for (int i = 0; i < size; ++i) {
fscanf(fp,"%d ", &read[i]);
}读取操作*/
int main(){
    /*char *filename[3] = {"1w.txt", "5w.txt", "20w.txt"};//文件名
    int sizes[3] = {10000, 50000, 200000};*/
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

//向它传入文件的名字，生成对应的文件
void save(char name[], int size){
    int arr[size];//生成对应大小的数组存放数字
    FILE *fp = fopen(name, "w+");
    srand((unsigned)(time(NULL)));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand()%500;
        fprintf(fp,"%d ", arr[i]);
    }//对文件进行写入
    fclose(fp);
}

void load(char name[], int size, int *arr){
    //将三个文件的数字导入到数组中
    FILE *f1;
    f1 = fopen(name, "r");
    for (int i = 0; i < size; ++i){
        fscanf(f1, "%d ", &arr[i]);
    }
    fclose(f1);
}

void mainchoice(int ch){
    switch (ch)
    {
        case 1:{//大数据量排序用时
            printf("请选择需要测试的数据量\n");
            datamenu();
            int n1;
            while (scanf("%d", &n1) == 0 || getchar() != '\n')
            {
                printf("非法输入，请重新输入：");
                while (getchar() != '\n');  // 清除缓存区
            }
            datachoice(n1);
            break;
        }

        case 2:{//大量数组排序用时
            printf("请选择一种排序算法：\n");
            sortmenu();
            int n2;
            while (scanf("%d", &n2) == 0 || getchar() != '\n')
            {
                printf("非法输入，请重新输入：");
                while (getchar() != '\n');  // 清除缓存区
            }
            sortchoice(n2);
            break;
        }

        default:{//输入不规范
            printf("输入仍然不规范！请重新输入\n");
            break;
        }
    }
}

void datachoice(int n){
    int size;
    char *filename;
    if(n==1){
        size = 10000;
        filename = "1w.txt";
    }
    else if(n==2){
        size = 50000;
        filename = "5w.txt";
    }
    else if(n==3){
        size = 200000;
        filename = "20w.txt";
    }
    else{
        printf("选择不在范围内，请重新输入!\n");
        return;
    }
    save(filename, size);//将相应数量的随机数保存到文件
    int arr[size];clock_t time;
    //建立函数指针数组，通过循环依此调用一个函数
    void *func[] = {insert_time_test, merge_time_test, quick1_time_test,
                    quick2_time_test, count_time_test, RadixCount_time_test};
    char *greet[] = { "插入排序用时:", "归并排序用时:", "递归版快排用时:", "非递归版快排用时:",
                      "计数排序用时:", "基数计数排序"};
    void (*p)(int *,int ,clock_t *);//设置一个指向参数为int*,int,clock_t *型
    // 返回类型为void型的函数指针
    for (int i = 0; i < 6; ++i) {
        p = func[i];
        load(filename, size,arr);//每一次调用都要重新载入
        p(arr, size, &time);
        printf(greet[i]);
        printf("%dms\n",time);
    }
}

void sortchoice(int ch){
    ;
}