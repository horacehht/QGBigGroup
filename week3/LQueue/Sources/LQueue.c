    //
// Created by Horac on 2021/4/9.
//

#include "LQueue.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int isinited = 0;//标记是否初始化

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
        Q->front = (Node*)malloc(sizeof(Node));//队头其实起到一个头指针的作用
        Q->rear = Q->front;
        Q->length = 0;
        isinited = 1;
}

/**
 *  @name        : Status DestroyLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status DestroyLQueue(LQueue *Q){
    if(isinited==0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    else{
        Node* p = Q->front;
        Node* q;//工具人
        while (p!=NULL){
            q = p->next;
            free(p);
            p = q;
        }

        isinited = 0;//参数设置
        return TRUE;
    }
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(isinited == 0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    if(Q->length == 0)
        return TRUE;
    else{
        printf("队列非空！\n");
        return FALSE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q){
    if(isinited == 0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    else if(Q->length == 0){
        printf("空队列无队头元素！\n");
        return FALSE;
    }
    else{
        Node* p = Q->front->next;//获得队头
        printf("队头元素为");
        LPrint(p->data, p->datatype);
    }
    printf("\n");
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data, int datatype){//这个会被inputdata调用
        if(isinited == 0){
            printf("队列未初始化！\n");
            return FALSE;
        }
        Node* p = (Node*)malloc(sizeof(Node));

        Q->rear->next = p;
        Q->rear = p;
        Q->length++;//队尾入队

        p->datatype = datatype;
        p->next = NULL;
        p->data = malloc(20);//设置参数

        memcpy(p->data, data, 20);//移花接木
        return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    if(isinited == 0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q)){
        printf("空队列！无法出队\n");
        return FALSE;
    }

    Node* p = Q->front->next;
    Q->front->next = p->next;
    free(p);
    Q->length--;

    //特殊条件
    if(IsEmptyLQueue(Q)) {//如果删掉后变成空队列，则需将rear指回队头
        Q->rear = Q->front;
    }
    return TRUE;
}

/**
 *  @name        : Status ClearLQueue(LQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue *Q){
    if(isinited == 0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q)) {
        printf("空队列！\n");
        return FALSE;
    }
    Node* p = Q->front->next;
    Node* q;
    while (p!=Q->rear){//还没到队尾
        q = p->next;
        free(p);
        Q->length--;
        p = q;
    }
    free(p);
    Q->length--;
    Q->rear = Q->front;//队尾指针指向队头
    return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int typeData)){
    if(isinited == 0)
    {
        printf("队列未初始化！\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q))
    {
        printf("队列无元素!\n");
        return FALSE;
    }
    Node *p = Q->front->next;
    while (p!=Q->rear) {
        foo(p->data, p->datatype);
        //这里传进来的输出函数实际上是APrint，向其传入元素及其元素类型
        p = p->next;
    }
    foo(p->data, p->datatype);
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q, int typeData)
 *    @description : 操作函数
 *    @param         q 指针q

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
 *    @description : 向队列中插入数据，会调用EnLQueue
 *    @param         *Q LQueue *Q
 *  @notice      : None
 */
void inputdata(LQueue *Q){
    printf("要插入哪种类型的数据？:\n");
    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
    int t;
    scanf("%d", &t);getchar();//吃回车
    while(t<1 || t>4)
    {
        printf("应输入在[1,4]之间的整数！\n请重输：");
        scanf("%d", &t);getchar();//吃回车
    }
    printf("想入队的数据 :");
    Status result;
    switch(t) {
        case INT: {
            int a;
            scanf("%d", &a);getchar();//吃回车
            result = EnLQueue(Q, &a, INT);//在队尾入队
            break;
        }
        case CHAR: {
            char a;
            scanf("%c", &a);getchar();//吃回车
            result = EnLQueue(Q, &a, CHAR);
            break;
        }
        case DOUBLE: {
            double a;
            scanf("%lf", &a);getchar();//吃回车
            result = EnLQueue(Q, &a, DOUBLE);
            break;
        }
        case STRING: {
            char a[20];
            printf("请控制字符串大小在20以内！\n");
            scanf("%s", a);//由于数组名就是地址，所以不用&
            getchar();
            result = EnLQueue(Q, a,STRING);
            break;
        }
    }
    if(result == TRUE){
        printf("入队成功\n");
    }
}



void showmenu(){
    printf("**************************\n");
    printf("*       a.初始化队列     *\n");
    printf("*       b.销毁队列       *\n");
    printf("*       c.是否队空       *\n");
    printf("*       d.队头元素       *\n");
    printf("*       e.队列长度       *\n");
    printf("*       f.元素入队       *\n");
    printf("*     g.删除队头元素     *\n");
    printf("*       h.清空队列       *\n");
    printf("*         i.遍历         *\n");
    printf("*         j.清屏         *\n");
    printf("**************************\n");
    printf("你的选择是:");
}