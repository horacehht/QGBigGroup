/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

#define INT 1
#define CHAR 2
#define DOUBLE 3
#define STRING 4
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//链式队列结构
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
    int datatype;                 //存放的数据类型
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;


/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q);

/**
 *  @name        : Status DestroyLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status DestroyLQueue(LQueue *Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q);

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data, int datatype)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data, int datatype);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q);

/**
 *  @name        : Status ClearLQueue(LQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int typeData));

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q, int typeData);



/**
 *  @name        : void inputdata
 *    @description : 向队列中插入数据，会调用EnLQueue
 *    @param         *Q LQueue *Q
 *  @notice      : None
 */
void inputdata(LQueue *Q);



/**
 *  @name        : void choice(char str)
 *    @description : 菜单中做选择
 *    @param         str char str
 *  @notice      : None
 */
void choice(char str);



/**
 *  @name        : void menu()
 *    @description : 显示菜单
 *    @param         None
 *  @notice      : None
 */
void showmenu();

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED