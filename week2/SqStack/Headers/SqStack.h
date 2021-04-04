#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack
{
	ElemType *elem;//指的是一个malloc出来的空间
	int top;//栈顶指针
	int size;//空间的大小
} SqStack;


Status initStack(SqStack **s,int sizes);
Status isEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e); 
Status destroyStack(SqStack *s);
Status stackLength(SqStack *s,int *length);
Status pushStack(SqStack *s,ElemType data);
Status popStack(SqStack *s,ElemType *data);
Status clearStack(SqStack *s);//调换了下顺序，因为clearStack要调用pop来实现
Status TraverseStack(SqStack *s);
void choice(char str);
void showmenu();

#endif 
