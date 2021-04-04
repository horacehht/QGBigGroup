#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#define SIZE 1010
#include".\stack.h"

int get_priority(char ch);//判断运算符优先级的函数，返回优先级0123
LL calc(numStack* operand, charStack* oprator);//计算两数结果，将栈内原来两数和运算符提取并移除，返回计算数值

#endif