#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef char ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//三个状态量
int isempty = 1;//isempty用来检验栈是否为空栈，1为空，0为非空
int isdestroyed = 1;//是否被销毁，1为销毁，0为未销毁
int isinited = 0;//是否已初始化，1为已初始化，0为未初始化

//筛选了一些实现了的函数，把ElemType改成了char
/**
 *  @name        : Status initLStack(LinkStack **s)
 *	@description : initialize the LinkStack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status initLStack(LinkStack **s);

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : get the top element data in LinkStack and store its value in e
 *	@param		 : LinkStack *s, ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopLStack(LinkStack *s,ElemType *e);

/**
 *  @name        : Status LStackLength(LinkStack *s,int *length)
 *	@description : get the length of the LinkStack
 *	@param		 : LinkStack *s,int *length
 *	@return		 : Status
 *  @notice      : None
 */
Status LStackLength(LinkStack *s,int *length);

/**
 *  @name        : Status pushLStack(LinkStack *s,ElemType data)
 *	@description : push the data into the LinkStack
 *	@param		 : LinkStack *s,ElemType data
 *	@return		 : Status
 *  @notice      : None
 */
Status pushLStack(LinkStack *s,ElemType data);

/**
 *  @name        : Status popLStack(LinkStack *s,ElemType *data)
 *	@description : pop out the top element in the LinkStack
 *	@param		 : LinkStack *s,ElemType *data
 *	@return		 : Status
 *  @notice      : None
 */
Status popLStack(LinkStack *s,ElemType *data);

#endif