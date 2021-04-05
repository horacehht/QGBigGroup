#include "..\Headers\calculator.h"
#include<stdlib.h>

int get_priority(char ch){
    switch (ch) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case ')':
            return 3;
    }
}

LL calc(numStack* operand, charStack* operator)//���������������ջ��ԭ���������������ȡ���Ƴ������ؼ�����ֵ
{
    LL b = num_pop(operand);
    LL a = num_pop(operand);
    char ch = char_pop(operator);

    switch (ch) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }//��main������ͨ����Ӹ�push�ٰ��������������ջ��
}

//��ջʵ��
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
char char_pop(charStack *s){
    charStackPtr p;
    char ch;
    p = s->top->next;
    ch = s->top->data;
    //ɾ��ջ��Ԫ��
    free(s->top);
    s->top = p;
    s->count--;
    return ch;//����ջ������
}


//��ջʵ��
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
LL num_pop(numStack *s){
    numStackPtr p;
    p = s->top->next;
    LL e = s->top->data;
    free(s->top);
    s->top = p;
    s->count--;
    return e;
}
