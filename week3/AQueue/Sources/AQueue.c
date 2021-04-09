//
// Created by Horac on 2021/4/9.
//

#include "AQueue.h"
#include <stdlib.h> //malloc
#include <stdio.h> //printf
#include <string.h> //memcpy函数

int isinited = 0;//是否已初始化，1为已初始化，0为未初始化
void InitAQueue(AQueue *Q){
    isinited = 1;
    Q->front = 0;
    Q->rear = 0;
    Q->length = MAXQUEUE;
    for (int i = 0; i < MAXQUEUE; ++i) {
        Q->data[i] = (void *) malloc(20);
        //为每一个数组元素都分配20字节的空间，因为我不知道要存进来什么类型的数据
    }
}


/**
 *  @name        : void DestroyAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status DestroyAQueue(AQueue *Q){
    if(isinited==0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    for(int i = 0; i < MAXQUEUE; i++)
        free(Q->data[i]);
    Q->data[0] = NULL;
    isinited = 0;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(AQueue *Q){
    if(isinited == 0)
    {
        printf("队列未初始化！\n");
        return FALSE;
    }
    if(LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else{
        printf("队列未满！\n");
        return FALSE;
    }

}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(AQueue *Q){
    if(isinited == 0)
    {
        printf("队列未初始化！\n");
        return FALSE;
    }
    if (LengthAQueue(Q) == 0)
        return TRUE;
    else
        return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
    if(isinited == 0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空！无队头\n");
        return FALSE;
    }
    memcpy(Q->data[Q->front], e,20); //memcpy是内存拷贝函数
    //把源内存（第一个参数）处的字节拷贝到目标内存（第二个参数），拷贝的字节大小为第三个参数
    return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){//这个会被inputdata调用
    if(isinited == 0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    if (IsFullAQueue(Q))
    {
        printf("队列已满！无法入队\n");
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
    if(isinited == 0){
        printf("队列未初始化！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("空队列！无法出队\n");
        return FALSE;
    }
    Q->front = (Q->front+1)%Q->length;
    // %号是队尾rear已到数组末尾，让其回到数组开头，不用%号会越界
    return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    if(isinited == 0){
        printf("队列未初始化！\n");
    }
    if (IsEmptyAQueue(Q))
    {
        printf("空队列！\n");
        return;
    }
    Q->front = Q->rear = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int typeData)){
    //foo是我们定义的一个打印函数
    if(isinited == 0)
    {
        printf("队列未初始化！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("队列无元素!\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->data[Q->front+i], Q->type[Q->front+i]);
        //这里传进来的输出函数实际上是APrint，向其传入元素及其元素类型
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
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
 *    @description : 向队列中插入数据，会调用EnAQueue
 *    @param         *Q AQueue *Q
 *  @notice      : None
 */
void inputdata(AQueue *Q){
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
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, &a);
            break;
        }
        case CHAR: {
            char a;
            scanf("%c", &a);
            getchar();//吃回车
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, &a);
            break;
        }
        case DOUBLE: {
            double a;
            scanf("%lf", &a);
            getchar();//吃回车
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, &a);
            break;
        }
        case STRING: {
            char a[20];
            printf("请控制字符串大小在20以内！\n");
            scanf("%s", a);//由于数组名就是地址，所以不用&
            getchar();
            Q->type[Q->rear] = t;
            result = EnAQueue(Q, a);
            break;
        }
    }
    if(result == TRUE){
        printf("插入成功\n");
    }
}



void showmenu(){
    printf("**************************\n");
    printf("*       a.初始化队列     *\n");
    printf("*       b.销毁队列       *\n");
    printf("*       c.是否队满       *\n");
    printf("*       d.是否队空       *\n");
    printf("*       e.队头元素       *\n");
    printf("*       f.队列长度       *\n");
    printf("*       g.元素入队       *\n");
    printf("*     h.删除队头元素     *\n");
    printf("*       i.清空队列       *\n");
    printf("*         j.遍历         *\n");
    printf("*         k.清屏         *\n");
    printf("**************************\n");
    printf("你的选择是:");
}
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/