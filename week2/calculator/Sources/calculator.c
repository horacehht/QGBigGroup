#include"..\Headers\calculator.h"
#include"..\Headers\stack.h"

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

LL calc(numStack* operand, charStack* oprator)//计算两数结果，将栈内原来两数和运算符提取并移除，返回计算数值
{
    LL b = num_pop(operand);
    LL a = num_pop(operand);
    char ch = char_pop(oprator);

    switch (ch) {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }//在main函数里通常会接个push再把新数存入操作数栈中
}