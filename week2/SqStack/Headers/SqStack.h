#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;
ElemType arr[100];

typedef struct SqStack 
{
	ElemType *elem;//指的是一个数组吗？
	int top;//栈顶指针
	int size;//数组的最大容量
} SqStack;


Status initStack(SqStack *s,int sizes);
Status isEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e); 
Status clearStack(SqStack *s);
Status destroyStack(SqStack *s);
Status stackLength(SqStack *s,int *length);
Status pushStack(SqStack *s,ElemType data);
Status popStack(SqStack *s,ElemType *data);


#endif 
