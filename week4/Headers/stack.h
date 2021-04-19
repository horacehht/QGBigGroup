//
// Created by Horace on 2021/4/17.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H
typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode, *StackPtr;

typedef struct Stack
{
    StackPtr top;
    int	count;
}Stack;

//top栈顶元素，length元素个数，push压栈，pop出栈
int top(Stack *s);
void push(Stack *s,int e);
int pop(Stack *s);
#endif //UNTITLED_STACK_H
