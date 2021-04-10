    //
// Created by Horac on 2021/4/9.
//

#include "LQueue.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int isinited = 0;//����Ƿ��ʼ��

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
        Q->front = (Node*)malloc(sizeof(Node));//��ͷ��ʵ��һ��ͷָ�������
        Q->rear = Q->front;
        Q->length = 0;
        isinited = 1;
}

/**
 *  @name        : Status DestroyLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status DestroyLQueue(LQueue *Q){
    if(isinited==0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    else{
        Node* p = Q->front;
        Node* q;//������
        while (p!=NULL){
            q = p->next;
            free(p);
            p = q;
        }

        isinited = 0;//��������
        return TRUE;
    }
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(isinited == 0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if(Q->length == 0)
        return TRUE;
    else{
        printf("���зǿգ�\n");
        return FALSE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q){
    if(isinited == 0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    else if(Q->length == 0){
        printf("�ն����޶�ͷԪ�أ�\n");
        return FALSE;
    }
    else{
        Node* p = Q->front->next;//��ö�ͷ
        printf("��ͷԪ��Ϊ");
        LPrint(p->data, p->datatype);
    }
    printf("\n");
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
    if(isinited == 0){
        return -1;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data, int datatype)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data, int datatype){//����ᱻinputdata����
        if(isinited == 0){
            printf("����δ��ʼ����\n");
            return FALSE;
        }
        Node* p = (Node*)malloc(sizeof(Node));

        Q->rear->next = p;
        Q->rear = p;
        Q->length++;//��β���

        p->datatype = datatype;
        p->next = NULL;
        p->data = malloc(20);//���ò���

        memcpy(p->data, data, 20);//�ƻ���ľ
        return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    if(isinited == 0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q)){
        printf("�ն��У��޷�����\n");
        return FALSE;
    }

    Node* p = Q->front->next;
    Q->front->next = p->next;
    free(p);
    Q->length--;

    //��������
    if(IsEmptyLQueue(Q)) {//���ɾ�����ɿն��У����轫rearָ�ض�ͷ
        Q->rear = Q->front;
    }
    return TRUE;
}

/**
 *  @name        : Status ClearLQueue(LQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue *Q){
    if(isinited == 0){
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q)) {
        printf("�ն��У�\n");
        return FALSE;
    }
    Node* p = Q->front->next;
    Node* q;
    while (p!=Q->rear){//��û����β
        q = p->next;
        free(p);
        Q->length--;
        p = q;
    }
    free(p);
    Q->length--;
    Q->rear = Q->front;//��βָ��ָ���ͷ
    return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int typeData)){
    if(isinited == 0)
    {
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q))
    {
        printf("������Ԫ��!\n");
        return FALSE;
    }
    Node *p = Q->front->next;
    while (p!=Q->rear) {
        foo(p->data, p->datatype);
        //���ﴫ�������������ʵ������APrint�����䴫��Ԫ�ؼ���Ԫ������
        p = p->next;
    }
    foo(p->data, p->datatype);
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q, int typeData)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q, int typeData){
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
 *  @name        : void inputdata(LQueue *Q)
 *    @description : ������в������ݣ������EnLQueue
 *    @param         *Q LQueue *Q
 *  @notice      : None
 */
void inputdata(LQueue *Q){
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
            result = EnLQueue(Q, &a, INT);//�ڶ�β���
            break;
        }
        case CHAR: {
            char a;
            scanf("%c", &a);getchar();//�Իس�
            result = EnLQueue(Q, &a, CHAR);
            break;
        }
        case DOUBLE: {
            double a;
            scanf("%lf", &a);getchar();//�Իس�
            result = EnLQueue(Q, &a, DOUBLE);
            break;
        }
        case STRING: {
            char a[20];
            printf("������ַ�����С��20���ڣ�\n");
            scanf("%s", a);//�������������ǵ�ַ�����Բ���&
            getchar();
            result = EnLQueue(Q, a,STRING);
            break;
        }
    }
    if(result == TRUE){
        printf("��ӳɹ�\n");
    }
}



void showmenu(){
    printf("**************************\n");
    printf("*       a.��ʼ������     *\n");
    printf("*       b.���ٶ���       *\n");
    printf("*       c.�Ƿ�ӿ�       *\n");
    printf("*       d.��ͷԪ��       *\n");
    printf("*       e.���г���       *\n");
    printf("*       f.Ԫ�����       *\n");
    printf("*     g.ɾ����ͷԪ��     *\n");
    printf("*       h.��ն���       *\n");
    printf("*         i.����         *\n");
    printf("*         j.����         *\n");
    printf("**************************\n");
    printf("���ѡ����:");
}