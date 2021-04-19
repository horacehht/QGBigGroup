//
// Created by Horace on 2021/4/17.
//
#include <stdlib.h>
#include "qgsort.h"
#include"Stack.h"
#include <stdio.h>
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
    int i, j, z, index;
    for (j = 1; j < n; j++)//从1开始往右走开始排序过程
    {
        for (i = j - 1; i >= 0; i--)//往左找到比它小的数
        {
            if (a[j] > a[i])//找到了
            {
                break;
            }
        }
        index = a[j];//存储该项数据
        if (i != j - 1)//不是有序数据末尾
        {
            for (z = j; z > i; z--)//每一位数据后移，留出待插空位
            {
                a[z] = a[z - 1];
            }
            a[i + 1] = index;//把刚刚存储的数据放进去
        }
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){//temp要在外面给他申请空间
    int i = begin;
    int k = 0;
    int j = mid+1;
    while ( i <= mid && j<= end){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    if(i == mid+1){
        while (j <= end){
            temp[k++] = a[j++];
        }
    }
    if(j == end+1 ){
        while (i <= mid){
            temp[k++] = a[i++];
        }
    }
    for (j = 0, i = begin; j < k;i++, j++) {
        a[i] = temp[j];
    }
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
    if (begin >= end)
        return;//当子问题不能再分解后，跳出循环
        // 执行归并操作，即执行MergeArray函数
    int mid = ( begin + end ) / 2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);
    MergeArray(a, begin, mid, end, temp);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end){
    //快排递归版是分区，归并也是分区
    if(begin < end){//如果两个哨兵没有碰到一起且左比右小
        int i = begin;
        int j = end;
        int k = a[begin];
        while (i < j){
            while (i < j && a[j] >= k){
                j--;// 从右向左找第一个小于k的数
            }

            if(i < j){
                a[i++] = a[j];
            }

            while (i < j && a[i] < k){
                i++;// 从左向右找第一个大于等于k的数
            }

            if(i < j){
                a[j--] = a[i];
            }
        }

        a[i] = k;
        //开始递归调用
        QuickSort_Recursion(a, begin, i-1);
        QuickSort_Recursion(a, i+1, end);
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a, int size){
    Stack s;
    int position, left, right;
    left = 0; right = size-1;
    s.count = 0;s.top=NULL;//对栈初始化
    push(&s, left);
    push(&s, right);
    while (s.count!=0){
        right = top(&s);
        pop(&s);
        left = top(&s);
        pop(&s);
        position = Partition(a, left, right);
        //先快排基准左侧，则先将后侧的下标入栈
        if (position - 1 > left)
        {
            push(&s, left);
            push(&s, position-1);
        }
        if (position +1 < right)
        {
            push(&s, position+1);
            push(&s, right);
        }
    }
}


/**
 *  @name        : void Partition(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end){//被非递归的快排函数调用
    int pivot = a[begin];//pivot是枢轴的意思
    int i = begin +1;
    int j = end;
    while(1){
        //向右找到第一个小于等于pivot的元素位置
        while (i <= j && a[i] <= pivot)
            i++;
        //向左找到第一个大于等于pivot的元素位置
        while (i <= j && a[j] >= pivot)
            j--;
        if(i >= j){
            break;//碰过面即跳出循环
        }
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[begin] = a[j];
    //使中轴元素处为有序位
    a[j] = pivot;
    return j;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size){
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < size; ++i) {
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    int len = max-min+1;
    int count[len];//存放次数
    for (int i = 0; i < len; ++i) {
        count[i] = 0;
    }//次数初始都是0
    //开始计数
    for (int i = 0; i < size; ++i) {
        int num = a[i];
        count[num-min]++;//分开两步写是因为一步写会报错
    }
    int begin = 0;
    for (int i = 0; i < len; ++i) {//从count数据的次数给a排序
        if(count[i]!=0){//如果该数有被统计到
            for (int j = 0; j < count[i]; ++j) {
                a[begin++] = min+i;
            }//那么还原给原数组n次，n为统计到的次数
        }
    }//完成排序
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int arr[],int length){
    int* radixArrays[10];
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int*)malloc(sizeof(int) * (length + 1));
        radixArrays[i][0] = 0;
    }
    for (int pos = 1; pos <= 3; pos++)
    {
        for (int i = 0; i < length; i++) //分配
        {
            int num = GetNumPos(arr[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = arr[i];
        }
        for (int i = 0, j = 0; i < 10; i++)  //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                arr[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        free(radixArrays[i]);
        radixArrays[i] = NULL;
    }
}

//找到num的从低到高的第pos位的数据
int GetNumPos(int num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;
    return (num / temp) % 10;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
    //定义一个一维数组，存有红白蓝三颜色
    int number[3] = {0, 0, 0};
    //遍历nums数组，对应元素，有则++。遍历完，number数组中的值也就是对应元素存在的个数
    for (int i = 0; i < size; i++){
        number[a[i]] ++;
    }
    int temp = 0;
    //三种颜色，每种颜色包含number[i]个，然后重新赋值给nums数组
    for(int i = 0; i < 3;i ++){
        for(int j = 0; j < number[i];j++){
            a[temp ++] = i;
        }
    }
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */

int GetKNumber(int *a, int size, int k){
    //输出-1表示不合法
    if(a == NULL || size <= 0 || k <= 0 || k > size){
        return -1;
    }
    //第k大的数等价于找第size-k+1小的数
    k = size-k+1;
    int l = 0;
    int r = size-1;
    while(l <= r){
        int index = Partition(a, l, r);
        if(index+1 == k){ //找到
            return a[index];
        }
        else if(index+1 < k){ //在右边序列找
            l = index+1;
        }
        else{ //在左边序列找
            r = index-1;
        }
    }
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

//三个菜单
void mainmenu(){//主菜单
    printf("欢迎使用排序时间测试系统\n");
    printf("请选择以下两项中的一项(填入数字1，2)\n");
    printf("1.大数据量排序用时\n");
    printf("2.大量小数组排序用时\n");
    printf("请选择：");
}

void datamenu(){//进入大数据量排序后的分支菜单
    printf("1.1w数据量\n");
    printf("2.5w数据量\n");
    printf("3.20w数据量\n");
}

void sortmenu(){//进到大量小数组排序后的分支菜单
    printf("1.插入排序\n");
    printf("2.归并排序\n");
    printf("3.快速排序递归版\n");
    printf("4.快速排序非递归版\n");
    printf("5.计数排序\n");
    printf("6.基数计数排序\n");
}

//三个选择分支
void mainchoice(int ch){//主选择
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

        case 2:{//大量小数组排序用时
            sortmenu();
            printf("请选择一种排序算法:");
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
            printf("输入不规范！请重新输入\n");
            break;
        }
    }
}

void datachoice(int n){//大数据量排序分支
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
        printf("输入不规范，请重新输入!\n");
        return;
    }
    save(filename, size);//将相应数量的随机数保存到文件
    int arr[size];//建立一个用于导入文件中数字的数组
    clock_t time;//记录时间
    //建立函数指针数组，通过循环依此调用一个函数
    void *func[] = {insert_time_test, merge_time_test, quick1_time_test,
                    quick2_time_test, count_time_test, RadixCount_time_test};
    char *greet[] = { "插入排序用时:", "归并排序用时:", "递归版快排用时:", "非递归版快排用时:",
                      "计数排序用时:", "基数计数排序"};
    void (*p)(int *,int ,clock_t *);//设置一个指向参数为int*,int,clock_t *型
    // 返回类型为void型的函数指针
    for (int i = 0; i < 6; ++i) {
        p = func[i];//指向所选的排序函数
        load(filename, size, arr);//每一次调用都要重新载入数组
        // 不然下一次排序的数组已经排序好了，会对排序的时间产生细微的影响
        p(arr, size, &time);//通过函数指针调用某个排序测试函数
        printf(greet[i]);//用户交互
        printf("%dms\n",time);//输出每一个排序所花费的时间
    }
    printf("\n");
}

void sortchoice(int n){
    if(n > 6 || n < 1){
        printf("输入不规范！\n");
        return;//直接结束该函数
    }
    printf("测试该函数对数据量为100的数组进行100次排序\n");
    char *filename = "100.txt";
    int size = 100;
    save(filename, size);//将相应数量的随机数保存到文件
    int arr[size];//生成相应数组
    clock_t total_time = 0;//记录总时间
    void *func[] = {insert_time_test, merge_time_test, quick1_time_test,
                    quick2_time_test, count_time_test, RadixCount_time_test};
    char *greet[] = { "插入排序总用时:", "归并排序总用时:",    "递归版快排总用时:", "非递归版快排总用时:",
                      "计数排序总用时:", "基数计数总用时"};//加了个总
    void (*p)(int *, int ,clock_t *);//与datachoice的p同理
    p = func[n-1];//选择一个排序函数
    for (int i = 0; i < 100; ++i) {//排序100次
        clock_t time = 0;//用于记录每一次排序的时间
        load(filename, size, arr);
        p(arr, size, &time);
        total_time += time;//每次的时间进行累加
    }
    printf(greet[n-1]);
    printf("%dms\n\n", total_time);//输出总时间
}

//排序算法的测试函数
//原本我都是在测试函数中输出花费时间的，但由于第二个选项sortchoice要对一个排序函数测试100次
// 如果嵌入在里面，那条printf也会循环100次，用户观感极差，且sortchioce要的是总时间
// 所以函数都加了一个clock_t指针time，将time从函数里出来再选择是否printf
void insert_time_test(int *arr, int size, clock_t *time){
    //插入排序用时
    clock_t start = clock();//生成一个时间量
    insertSort(arr, size);
    clock_t diff = clock()-start;//结束时间
    *time = diff;
}

void merge_time_test(int *arr, int size, clock_t *time){
    //归并排序用时
    clock_t start = clock();//生成一个时间量
    int* t1 = (int*)malloc(sizeof(int)*size);
    MergeSort(arr, 0, size-1, t1);
    clock_t diff = clock()-start;//结束时间
    *time = diff;
}

void quick1_time_test(int *arr, int size, clock_t *time){
    //快排递归版用时
    clock_t start = clock();//生成一个时间量
    QuickSort_Recursion(arr, 0,size-1);
    clock_t diff = clock()-start;//结束时间
    *time = diff;
}

void quick2_time_test(int *arr,int size, clock_t *time){
    //非递归版排序用时
    clock_t start = clock();//生成一个时间量
    QuickSort(arr, size);
    clock_t diff = clock()-start;//结束时间
    *time = diff;
}

void count_time_test(int *arr, int size, clock_t *time){
    //计数排序用时
    clock_t start = clock();//生成一个时间量
    CountSort(arr, size);
    clock_t diff = clock()-start;//结束时间
    *time = diff;
}

void RadixCount_time_test(int *arr, int size, clock_t *time){
    //基数计数排序用时
    clock_t start = clock();//生成一个时间量
    RadixCountSort(arr, size);
    clock_t diff = clock()-start;//结束时间
    *time = diff;
}