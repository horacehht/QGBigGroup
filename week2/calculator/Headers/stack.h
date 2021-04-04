#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef long long LL;

//符栈
typedef struct charStackNode
{
	char data;
	struct charStackNode *next;
}charStackNode, *charStackPtr;

typedef struct charStack
{
	charStackPtr top;
	int	count;
}charStack;

//筛选了一些实现了的函数，把ElemType改成了char
//top栈顶元素，length元素个数，push压栈，pop出栈
char char_top(charStack *s);
int char_length(charStack *s);
void char_push(charStack *s,char ch);
char char_pop(charStack *s);


//数栈
typedef struct numStackNode
{
	LL data;
	struct numStackNode *next;
}numStackNode, *numStackPtr;

typedef struct numStack
{
	numStackPtr top;
	int	count;
}numStack;
//top栈顶元素，length元素个数，push压栈，pop出栈
LL num_top(numStack *s);
int num_length(numStack *s);
void num_push(numStack *s,LL e);
LL num_pop(numStack *s);

#endif