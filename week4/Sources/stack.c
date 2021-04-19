//
// Created by Horace on 2021/4/17.
//
//ÊıÕ»ÊµÏÖ
#include "stack.h"
#include <stdlib.h>
int top(Stack *s){
    int e = s->top->data;
    return e;
}
void push(Stack *s,int e){
    StackPtr p;
    p = (StackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
}
int pop(Stack *s){
    StackPtr p;
    p = s->top->next;
    int e = s->top->data;
    free(s->top);
    s->top = p;
    s->count--;
    return e;
}

#include "stack.h"
