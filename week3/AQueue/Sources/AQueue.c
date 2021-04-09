//
// Created by Horac on 2021/4/9.
//

#include "AQueue.h"
#include <stdlib.h> //malloc
#include <stdio.h> //printf
#include <string.h> //memcpy����

int isinited = 0;//�Ƿ��ѳ�ʼ����1Ϊ�ѳ�ʼ����0Ϊδ��ʼ��
void InitAQueue(AQueue *Q){
    isinited = 1;
    Q->front = 0;
    Q->rear = 0;
    Q->length = MAXQUEUE;
    for (int i = 0; i < MAXQUEUE; ++i) {
        Q->data[i] = (void *) malloc(20);
        //Ϊÿһ������Ԫ�ض�����20�ֽڵĿռ䣬��Ϊ�Ҳ�֪��Ҫ�����ʲô���͵�����
    }
}


/**
 *  @name        : void DestroyAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status DestroyAQueue(AQueue *Q){
    if(isinited==0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
    Q->data[0] = NULL;
    isinited = 0;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(AQueue *Q){
    if(isinited == 0)
    {
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else{
        printf("����δ����\n");
        return FALSE;
    }

}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(AQueue *Q){
    if(isinited == 0)
    {
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if (LengthAQueue(Q) == 0)
        return TRUE;
    else
        return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
    if(isinited == 0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ�գ��޶�ͷ\n");
        return FALSE;
    }
    memcpy(Q->data[Q->front], e,20); //memcpy���ڴ濽������
    //��Դ�ڴ棨��һ�������������ֽڿ�����Ŀ���ڴ棨�ڶ������������������ֽڴ�СΪ����������
    return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
    if(isinited == 0){
        return -1;
    }
    int length = (Q->rear-Q->front+Q->length)%Q->length;
    return length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){//����ᱻinputdata����
    if(isinited == 0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if (IsFullAQueue(Q))
    {
        printf("�����������޷����\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        memcpy(Q->data[Q->front], data, 20);
        Q->rear = (Q->rear + 1) % Q->length;
        return TRUE;
    }
    memcpy(Q->data[Q->rear], data, 20);
    Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
    if(isinited == 0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("�ն��У��޷�����\n");
        return FALSE;
    }
    Q->front = (Q->front+1)%Q->length;
    // %���Ƕ�βrear�ѵ�����ĩβ������ص����鿪ͷ������%�Ż�Խ��
    return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    if(isinited == 0){
        printf("����δ��ʼ����\n");
    }
    if (IsEmptyAQueue(Q))
    {
        printf("�ն��У�\n");
        return;
    }
    Q->front = Q->rear = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int typeData)){
    //foo�����Ƕ����һ����ӡ����
    if(isinited == 0)
    {
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("������Ԫ��!\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->data[Q->front+i], Q->type[Q->front+i]);
        //���ﴫ�������������ʵ������APrint�����䴫��Ԫ�ؼ���Ԫ������
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q, int typeData){
    if(typeData == DOUBLE)
        printf("--> %.2lf ", *(double*)q);
    if(typeData == CHAR)
        printf("--> %c ", *(char*)q);
    if(typeData == INT)
        printf("--> %d ", *(int*)q);
    if(typeData == STRING)
        printf("--> %s ", (char*)q);
}



/**
 *  @name        : void inputdata
 *    @description : ������в������ݣ������EnAQueue
 *    @param         *Q AQueue *Q
 *  @notice      : None
 */
void inputdata(AQueue *Q){
    printf("Ҫ�����������͵����ݣ�:\n");
    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
    int t;
    scanf("%d", &t);getchar();//�Իس�
    while(t<1 || t>4)
    {
        printf("Ӧ������[1,4]֮���������\n�����䣺");
        scanf("%d", &t);getchar();//�Իس�
    }
    printf("����ӵ����� :");
    Status result;
    switch(t) {
        case INT: {
            int a;
            scanf("%d", &a);getchar();//�Իس�
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, &a);
            break;
        }
        case CHAR: {
            char a;
            scanf("%c", &a);
            getchar();//�Իس�
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, &a);
            break;
        }
        case DOUBLE: {
            double a;
            scanf("%lf", &a);
            getchar();//�Իس�
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, &a);
            break;
        }
        case STRING: {
            char a[20];
            printf("������ַ�����С��20���ڣ�\n");
            scanf("%s", a);//�������������ǵ�ַ�����Բ���&
            getchar();
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, a);
            break;
        }
    }
    if(result == TRUE){
        printf("����ɹ�\n");
    }
}



void showmenu(){
    printf("**************************\n");
    printf("*       a.��ʼ������     *\n");
    printf("*       b.���ٶ���       *\n");
    printf("*       c.�Ƿ����       *\n");
    printf("*       d.�Ƿ�ӿ�       *\n");
    printf("*       e.��ͷԪ��       *\n");
    printf("*       f.���г���       *\n");
    printf("*       g.Ԫ�����       *\n");
    printf("*     h.ɾ����ͷԪ��     *\n");
    printf("*       i.��ն���       *\n");
    printf("*         j.����         *\n");
    printf("*         k.����         *\n");
    printf("**************************\n");
    printf("���ѡ����:");
}
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/