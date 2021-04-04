#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"..\Headers\calculator.h"
#include"..\Headers\stack.h"
//初始化两个栈
charStack Stack1;
numStack Stack2;
charStack *operator = &Stack1;//operator操作符，符栈
numStack *operand =  &Stack2;//operand操作数，数栈

int main(){
    //数栈和符栈的初始化
    operand->count = 0;
    operand->top = NULL;
    operator->count = 0;
    operator->top = NULL;

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

        //中缀转后缀
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
            {//如果遇到的不是数字
                if(char_length(operator) == 0)
                {
                    if(str[i]=='(')
                    {
                        if(str[i+1]=='-' && isdigit(str[i+2]))
                        {//第一个数是负数
                            char_push(operator, str[i+1]);//压运算符
                            num_push(operand, 0);//将0压入数栈造成一种0-的效果，即可实现负数
                            number = 0;
                            int p = i+2;
                            while (p < len && isdigit(str[p]))
                            {//把负号后的数字读全
                                number = number*10 + (str[p]-'0');
                                p++;
                            }//跳出时p索引已在右括号处
                            i = p+1;//跳过右括号
                            num_push(operand, number);
                            number = calc(operand, operator);
                            num_push(operand, number);
                            continue;
                        }//跳出该循环
                        else
                        {//如果不是负数，正常压入即可
                            char_push(operator, str[i]);
                            i++;
                            continue;
                        }
                    }
                    else//这个符号不是左括号
                    {
                        char_push(operator, str[i]);
                        i++;
                        continue;
                    }
                }
                //上面讨论的是首字符

                //下面讨论的是非首字符
                priority_top = get_priority(char_top(operator));
                priority_cur = get_priority(str[i]);
                if(priority_cur == 0)
                {//如果是左括号
                    /*这要分两种情况
                    1.括起来的是负数
                    2.括起来的是一个正常的表达式*/
                    if(str[i+1]=='-' && isdigit(str[i+2]) )
                    {//是个负数，跟55-67行是一样的
                        char_push(operator, str[i+1]);//先压运算符
                        num_push(operand,0);
                        number = 0;
                        int p = i+2;
                        while (p < len && isdigit(str[p])) 
                        {
                            // 读全数字
                            number = number * 10 + (str[p] - '0');
                            p++;
                        }//跳出时p索引已在右括号处
                        i = p+1;//直接跳过右括号
                        num_push(operand, number);
                        continue;
                    }
                    //2.括起来的是个正常的表达式
                    char_push(operator, str[i]);//那就把左括号压进去就好了
                    i++;
                }

                else if(priority_cur == 3)
                {//如果遇到了右括号，计算到第一个左括号（内的表达式的值
                    while( char_top(operator) != '(' )
                    {
                        number = calc(operand, operator);
                        num_push(operand, number);
                    }
                    char_pop(operator);
                    i++;
                }

                else
                {//遇到加减乘除
                    while (char_length(operator)!= 0 && priority_cur <= priority_top)
                    {// 如果还有操作符，并且栈顶操作符优先级高
                        // 那么可以先计算栈里的数
                        number=calc(operand, operator);
                        num_push(operand, number);
                        //算完一次之后如果还有操作符，则获取其优先级
                        if( char_length(operator)!= 0 )
                        {
                            priority_top = get_priority( char_top(operator) );
                        }
                    }
                    char_push(operator, str[i]);
                    i++;
                }
            }
        }
        //中缀表达式已转换为后缀表达式
        
        while ( char_length(operator)!= 0)
        {
            number = calc(operand, operator);
            num_push(number);
        }
        
    }

}