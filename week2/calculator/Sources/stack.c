#include"..\Headers\stack.h"
#include<stdlib.h>

//符栈实现
char char_top(charStack *s){
    char ch = s->top->data;
    return ch;
}

int char_length(charStack *s){
    int len = s->count;
    return len;
}

void char_push(charStack *s,char ch){
    charStackPtr p;
    p = (charStackPtr)malloc(sizeof(charStackNode));
    p->data = ch;
    p->next = s->top;
    s->top = p;
    s->count++;
}
void char_pop(charStack *s,char *ch){
    charStackPtr p;
    p = s->top->next;
    *ch = s->top->data;
    free(s->top);
    s->top = p;
    s->count--;
}


//数栈实现
LL num_top(numStack *s){
    LL e = s->top->data;
    return e;
}
int num_length(numStack *s){
    int len = s->count;
    return len;
}
void num_push(numStack *s,LL e){
    numStackPtr p;
    p = (numStackPtr)malloc(sizeof(numStackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
}
void num_pop(numStack *s,LL *e){
    numStackPtr p;
    p = s->top->next;
    *e = s->top->data;
    free(s->top);
    s->top = p;
    s->count--;
}