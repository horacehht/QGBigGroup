#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

/**
 *  @name        : Status initLStack(LinkStack **s)
 *	@description : initialize the LinkStack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status initLStack(LinkStack **s);

/**
 *  @name        : Status isEmptyLStack(LinkStack *s)
 *	@description : determine whether the LinkStack is empty or not
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmptyLStack(LinkStack *s);

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : get the top element data in LinkStack and store its value in e
 *	@param		 : LinkStack *s, ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopLStack(LinkStack *s,ElemType *e);

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : get the top element data in LinkStack and store its value in e
 *	@param		 : LinkStack *s, ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
Status clearLStack(LinkStack *s);

/**
 *  @name        : Status destroyLStack(LinkStack *s)
 *	@description : destroy the LinkStack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status destroyLStack(LinkStack *s);

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

/**
 *  @name        : Status pushNodes(LinkStack *s,int n)
 *	@description : push many datas into the LinkStack
 *	@param		 : LinkStack *s,int n
 *	@return		 : Status
 *  @notice      : None
 */
Status pushNodes(LinkStack *s,int n);

/**
 *  @name        : void showmenu()
 *	@description : show menu on dos
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */
void showmenu();

/**
 *  @name        : void choice(char str)
 *	@description : user choose in dos
 *	@param		 : char str
 *	@return		 : None
 *  @notice      : None
 */
void choice(char str);

/**
 *  @name        : Status TraverseLStack(LinkStack *s)
 *	@description : print the data 
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status TraverseLStack(LinkStack *s);

#endif 