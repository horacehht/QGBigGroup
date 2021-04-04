#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#define SIZE 1010
#include".\stack.h"

char str[SIZE];//开一个足够大的数组

int get_priority(char ch);//判断运算符优先级的函数，返回优先级0123
LL gcd(LL a,LL b);//返回最大公约数
LL lcm(LL a,LL b);//返回最小公倍数（调用gcd）
LL calc();//计算两数结果，将栈内原来两数和运算符提取并移除，返回计算数值
void yuefen(LL *new_upon,LL *lcm_num);//约分函数
void fenshucalc();//分数计算函数,包含压栈操作

#endif