#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"..\Headers\calculator.h"
#include"..\Headers\stack.h"
//初始化两个栈
charStack Stack1;
numStack Stack2;
charStack *oprator = &Stack1;//operator操作符，符栈
numStack *operand =  &Stack2;//operand操作数，数栈

int main(){
    //数栈和符栈的初始化
    operand->count = 0;
    operand->top = NULL;
    oprator->count = 0;
    oprator->top = NULL;

    //用户提示
    printf("请选择一个模式(输入数字)\n");
    printf("1.普通计算器(支持带括号运算和负数运算)\n");
    printf("2.分数计算器(可算同优先级的分数加减乘除，不出现负数)\n");
    printf("3.大数计算器(目前只支持加法，因为coder太菜了)\n");

    //选择模式
    char mode;
    scanf("%c",&mode);
    getchar();//吃回车
    
    if(mode=='1')//普通计算器
    {
        scanf("%s",str);//录入表达式
        int priority_top, priority_cur;
        LL number;
        int i = 0, len = strlen(str)-1;
        while (i < len)
        {
            if(isdigit(str[i]))
            {//如果是数字
                number = 0;
                while (i < len && isdigit(str[i]))
                {//读全数字
                    number = number*10 + (str[i]-'0');
                    i++;
                }
                num_push(operand, number);
            }
            else
            {
                if()
            }
            
        }
        
    }

}