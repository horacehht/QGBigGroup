//
// Created by Horac on 2021/4/4.
//

#ifndef CLION_WORKSPACE_CALCULATOR_H
#define CLION_WORKSPACE_CALCULATOR_H

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

//计算用的函数
int get_priority(char ch);//判断运算符优先级的函数，返回优先级0123
LL calc(numStack* operand, charStack* operator);//计算两数结果，将栈内原来两数和运算符提取并移除，返回计算数值

#endif //CLION_WORKSPACE_CALCULATOR_H
