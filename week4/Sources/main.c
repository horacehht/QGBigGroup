#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "qgsort.h"
/*rewind(fp);//���ļ�ָ��ص��ļ���ͷ
int read[size];//����������ֵ�����
for (int i = 0; i < size; ++i) {
fscanf(fp,"%d ", &read[i]);
}��ȡ����*/
int main(){
    /*char *filename[3] = {"1w.txt", "5w.txt", "20w.txt"};//�ļ���
    int sizes[3] = {10000, 50000, 200000};*/
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

void mainchoice(int ch){
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

        case 2:{//��������������ʱ
            printf("��ѡ��һ�������㷨��\n");
            sortmenu();
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
            printf("������Ȼ���淶������������\n");
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
        printf("ѡ���ڷ�Χ�ڣ�����������!\n");
        return;
    }
    save(filename, size);//����Ӧ��������������浽�ļ�
    int arr[size];clock_t time;
    //��������ָ�����飬ͨ��ѭ�����˵���һ������
    void *func[] = {insert_time_test, merge_time_test, quick1_time_test,
                    quick2_time_test, count_time_test, RadixCount_time_test};
    char *greet[] = { "����������ʱ:", "�鲢������ʱ:", "�ݹ�������ʱ:", "�ǵݹ�������ʱ:",
                      "����������ʱ:", "������������"};
    void (*p)(int *,int ,clock_t *);//����һ��ָ�����Ϊint*,int,clock_t *��
    // ��������Ϊvoid�͵ĺ���ָ��
    for (int i = 0; i < 6; ++i) {
        p = func[i];
        load(filename, size,arr);//ÿһ�ε��ö�Ҫ��������
        p(arr, size, &time);
        printf(greet[i]);
        printf("%dms\n",time);
    }
}

void sortchoice(int ch){
    ;
}