//
// Created by Horac on 2021/4/4.
//

#ifndef CLION_WORKSPACE_CALCULATOR_H
#define CLION_WORKSPACE_CALCULATOR_H

typedef long long LL;

//��ջ
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

//ɸѡ��һЩʵ���˵ĺ�������ElemType�ĳ���char
//topջ��Ԫ�أ�lengthԪ�ظ�����pushѹջ��pop��ջ
char char_top(charStack *s);
int char_length(charStack *s);
void char_push(charStack *s,char ch);
char char_pop(charStack *s);


//��ջ
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
//topջ��Ԫ�أ�lengthԪ�ظ�����pushѹջ��pop��ջ
LL num_top(numStack *s);
int num_length(numStack *s);
void num_push(numStack *s,LL e);
LL num_pop(numStack *s);

//�����õĺ���
int get_priority(char ch);//�ж���������ȼ��ĺ������������ȼ�0123
LL calc(numStack* operand, charStack* operator);//���������������ջ��ԭ���������������ȡ���Ƴ������ؼ�����ֵ

#endif //CLION_WORKSPACE_CALCULATOR_H
