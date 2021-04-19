//
// Created by Horace on 2021/4/17.
//
#include <stdlib.h>
#include "qgsort.h"
#include"Stack.h"
#include <stdio.h>
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n){
    int i, j, z, index;
    for (j = 1; j < n; j++)//��1��ʼ�����߿�ʼ�������
    {
        for (i = j - 1; i >= 0; i--)//�����ҵ�����С����
        {
            if (a[j] > a[i])//�ҵ���
            {
                break;
            }
        }
        index = a[j];//�洢��������
        if (i != j - 1)//������������ĩβ
        {
            for (z = j; z > i; z--)//ÿһλ���ݺ��ƣ����������λ
            {
                a[z] = a[z - 1];
            }
            a[i + 1] = index;//�Ѹոմ洢�����ݷŽ�ȥ
        }
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){//tempҪ�������������ռ�
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
    if (begin >= end)
        return;//�������ⲻ���ٷֽ������ѭ��
        // ִ�й鲢��������ִ��MergeArray����
    int mid = ( begin + end ) / 2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);
    MergeArray(a, begin, mid, end, temp);
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end){
    //���ŵݹ���Ƿ������鲢Ҳ�Ƿ���
    if(begin < end){//��������ڱ�û������һ���������С
        int i = begin;
        int j = end;
        int k = a[begin];
        while (i < j){
            while (i < j && a[j] >= k){
                j--;// ���������ҵ�һ��С��k����
            }

            if(i < j){
                a[i++] = a[j];
            }

            while (i < j && a[i] < k){
                i++;// ���������ҵ�һ�����ڵ���k����
            }

            if(i < j){
                a[j--] = a[i];
            }
        }

        a[i] = k;
        //��ʼ�ݹ����
        QuickSort_Recursion(a, begin, i-1);
        QuickSort_Recursion(a, i+1, end);
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a, int size){
    Stack s;
    int position, left, right;
    left = 0; right = size-1;
    s.count = 0;s.top=NULL;//��ջ��ʼ��
    push(&s, left);
    push(&s, right);
    while (s.count!=0){
        right = top(&s);
        pop(&s);
        left = top(&s);
        pop(&s);
        position = Partition(a, left, right);
        //�ȿ��Ż�׼��࣬���Ƚ������±���ջ
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end){//���ǵݹ�Ŀ��ź�������
    int pivot = a[begin];//pivot���������˼
    int i = begin +1;
    int j = end;
    while(1){
        //�����ҵ���һ��С�ڵ���pivot��Ԫ��λ��
        while (i <= j && a[i] <= pivot)
            i++;
        //�����ҵ���һ�����ڵ���pivot��Ԫ��λ��
        while (i <= j && a[j] >= pivot)
            j--;
        if(i >= j){
            break;//�����漴����ѭ��
        }
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[begin] = a[j];
    //ʹ����Ԫ�ش�Ϊ����λ
    a[j] = pivot;
    return j;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
    int count[len];//��Ŵ���
    for (int i = 0; i < len; ++i) {
        count[i] = 0;
    }//������ʼ����0
    //��ʼ����
    for (int i = 0; i < size; ++i) {
        int num = a[i];
        count[num-min]++;//�ֿ�����д����Ϊһ��д�ᱨ��
    }
    int begin = 0;
    for (int i = 0; i < len; ++i) {//��count���ݵĴ�����a����
        if(count[i]!=0){//��������б�ͳ�Ƶ�
            for (int j = 0; j < count[i]; ++j) {
                a[begin++] = min+i;
            }//��ô��ԭ��ԭ����n�Σ�nΪͳ�Ƶ��Ĵ���
        }
    }//�������
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
        for (int i = 0; i < length; i++) //����
        {
            int num = GetNumPos(arr[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = arr[i];
        }
        for (int i = 0, j = 0; i < 10; i++)  //�ռ�
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

//�ҵ�num�Ĵӵ͵��ߵĵ�posλ������
int GetNumPos(int num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;
    return (num / temp) % 10;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size){
    //����һ��һά���飬���к��������ɫ
    int number[3] = {0, 0, 0};
    //����nums���飬��ӦԪ�أ�����++�������꣬number�����е�ֵҲ���Ƕ�ӦԪ�ش��ڵĸ���
    for (int i = 0; i < size; i++){
        number[a[i]] ++;
    }
    int temp = 0;
    //������ɫ��ÿ����ɫ����number[i]����Ȼ�����¸�ֵ��nums����
    for(int i = 0; i < 3;i ++){
        for(int j = 0; j < number[i];j++){
            a[temp ++] = i;
        }
    }
}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */

int GetKNumber(int *a, int size, int k){
    //���-1��ʾ���Ϸ�
    if(a == NULL || size <= 0 || k <= 0 || k > size){
        return -1;
    }
    //��k������ȼ����ҵ�size-k+1С����
    k = size-k+1;
    int l = 0;
    int r = size-1;
    while(l <= r){
        int index = Partition(a, l, r);
        if(index+1 == k){ //�ҵ�
            return a[index];
        }
        else if(index+1 < k){ //���ұ�������
            l = index+1;
        }
        else{ //�����������
            r = index-1;
        }
    }
}

//���������ļ������֣����ɶ�Ӧ���ļ�
void save(char name[], int size){
    int arr[size];//���ɶ�Ӧ��С������������
    FILE *fp = fopen(name, "w+");
    srand((unsigned)(time(NULL)));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand()%500;
        fprintf(fp,"%d ", arr[i]);
    }//���ļ�����д��
    fclose(fp);
}

void load(char name[], int size, int *arr){
    //�������ļ������ֵ��뵽������
    FILE *f1;
    f1 = fopen(name, "r");
    for (int i = 0; i < size; ++i){
        fscanf(f1, "%d ", &arr[i]);
    }
    fclose(f1);
}

//�����˵�
void mainmenu(){//���˵�
    printf("��ӭʹ������ʱ�����ϵͳ\n");
    printf("��ѡ�����������е�һ��(��������1��2)\n");
    printf("1.��������������ʱ\n");
    printf("2.����С����������ʱ\n");
    printf("��ѡ��");
}

void datamenu(){//����������������ķ�֧�˵�
    printf("1.1w������\n");
    printf("2.5w������\n");
    printf("3.20w������\n");
}

void sortmenu(){//��������С���������ķ�֧�˵�
    printf("1.��������\n");
    printf("2.�鲢����\n");
    printf("3.��������ݹ��\n");
    printf("4.��������ǵݹ��\n");
    printf("5.��������\n");
    printf("6.������������\n");
}

//����ѡ���֧
void mainchoice(int ch){//��ѡ��
    switch (ch)
    {
        case 1:{//��������������ʱ
            printf("��ѡ����Ҫ���Ե�������\n");
            datamenu();
            int n1;
            while (scanf("%d", &n1) == 0 || getchar() != '\n')
            {
                printf("�Ƿ����룬���������룺");
                while (getchar() != '\n');  // ���������
            }
            datachoice(n1);
            break;
        }

        case 2:{//����С����������ʱ
            sortmenu();
            printf("��ѡ��һ�������㷨:");
            int n2;
            while (scanf("%d", &n2) == 0 || getchar() != '\n')
            {
                printf("�Ƿ����룬���������룺");
                while (getchar() != '\n');  // ���������
            }
            sortchoice(n2);
            break;
        }

        default:{//���벻�淶
            printf("���벻�淶������������\n");
            break;
        }
    }
}

void datachoice(int n){//�������������֧
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
        printf("���벻�淶������������!\n");
        return;
    }
    save(filename, size);//����Ӧ��������������浽�ļ�
    int arr[size];//����һ�����ڵ����ļ������ֵ�����
    clock_t time;//��¼ʱ��
    //��������ָ�����飬ͨ��ѭ�����˵���һ������
    void *func[] = {insert_time_test, merge_time_test, quick1_time_test,
                    quick2_time_test, count_time_test, RadixCount_time_test};
    char *greet[] = { "����������ʱ:", "�鲢������ʱ:", "�ݹ�������ʱ:", "�ǵݹ�������ʱ:",
                      "����������ʱ:", "������������"};
    void (*p)(int *,int ,clock_t *);//����һ��ָ�����Ϊint*,int,clock_t *��
    // ��������Ϊvoid�͵ĺ���ָ��
    for (int i = 0; i < 6; ++i) {
        p = func[i];//ָ����ѡ��������
        load(filename, size, arr);//ÿһ�ε��ö�Ҫ������������
        // ��Ȼ��һ������������Ѿ�������ˣ���������ʱ�����ϸ΢��Ӱ��
        p(arr, size, &time);//ͨ������ָ�����ĳ��������Ժ���
        printf(greet[i]);//�û�����
        printf("%dms\n",time);//���ÿһ�����������ѵ�ʱ��
    }
    printf("\n");
}

void sortchoice(int n){
    if(n > 6 || n < 1){
        printf("���벻�淶��\n");
        return;//ֱ�ӽ����ú���
    }
    printf("���Ըú�����������Ϊ100���������100������\n");
    char *filename = "100.txt";
    int size = 100;
    save(filename, size);//����Ӧ��������������浽�ļ�
    int arr[size];//������Ӧ����
    clock_t total_time = 0;//��¼��ʱ��
    void *func[] = {insert_time_test, merge_time_test, quick1_time_test,
                    quick2_time_test, count_time_test, RadixCount_time_test};
    char *greet[] = { "������������ʱ:", "�鲢��������ʱ:",    "�ݹ���������ʱ:", "�ǵݹ���������ʱ:",
                      "������������ʱ:", "������������ʱ"};//���˸���
    void (*p)(int *, int ,clock_t *);//��datachoice��pͬ��
    p = func[n-1];//ѡ��һ��������
    for (int i = 0; i < 100; ++i) {//����100��
        clock_t time = 0;//���ڼ�¼ÿһ�������ʱ��
        load(filename, size, arr);
        p(arr, size, &time);
        total_time += time;//ÿ�ε�ʱ������ۼ�
    }
    printf(greet[n-1]);
    printf("%dms\n\n", total_time);//�����ʱ��
}

//�����㷨�Ĳ��Ժ���
//ԭ���Ҷ����ڲ��Ժ������������ʱ��ģ������ڵڶ���ѡ��sortchoiceҪ��һ������������100��
// ���Ƕ�������棬����printfҲ��ѭ��100�Σ��û��۸м����sortchioceҪ������ʱ��
// ���Ժ���������һ��clock_tָ��time����time�Ӻ����������ѡ���Ƿ�printf
void insert_time_test(int *arr, int size, clock_t *time){
    //����������ʱ
    clock_t start = clock();//����һ��ʱ����
    insertSort(arr, size);
    clock_t diff = clock()-start;//����ʱ��
    *time = diff;
}

void merge_time_test(int *arr, int size, clock_t *time){
    //�鲢������ʱ
    clock_t start = clock();//����һ��ʱ����
    int* t1 = (int*)malloc(sizeof(int)*size);
    MergeSort(arr, 0, size-1, t1);
    clock_t diff = clock()-start;//����ʱ��
    *time = diff;
}

void quick1_time_test(int *arr, int size, clock_t *time){
    //���ŵݹ����ʱ
    clock_t start = clock();//����һ��ʱ����
    QuickSort_Recursion(arr, 0,size-1);
    clock_t diff = clock()-start;//����ʱ��
    *time = diff;
}

void quick2_time_test(int *arr,int size, clock_t *time){
    //�ǵݹ��������ʱ
    clock_t start = clock();//����һ��ʱ����
    QuickSort(arr, size);
    clock_t diff = clock()-start;//����ʱ��
    *time = diff;
}

void count_time_test(int *arr, int size, clock_t *time){
    //����������ʱ
    clock_t start = clock();//����һ��ʱ����
    CountSort(arr, size);
    clock_t diff = clock()-start;//����ʱ��
    *time = diff;
}

void RadixCount_time_test(int *arr, int size, clock_t *time){
    //��������������ʱ
    clock_t start = clock();//����һ��ʱ����
    RadixCountSort(arr, size);
    clock_t diff = clock()-start;//����ʱ��
    *time = diff;
}