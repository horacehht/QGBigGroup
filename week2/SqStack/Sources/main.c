#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\SqStack.h"

SqStack *s = NULL;
int main()
{
    char str;
    while (1)
    {
        showmenu();
        scanf("%c",&str);
        getchar();
        choice(str);
    }    
    return 0;
}

void choice(char str){
    Status result;//用于记录结果
    switch (str)
    {
        case 'a':{//初始化栈
            printf("请设置栈的大小:");
            int size;
            scanf("%d",&size);
            getchar();//这里要吃回车，不然一直有个\n卡住你
            result = initStack(&s,size);
            if(result==SUCCESS){
                printf("初始化成功！\n");
            }
            else{
                printf("初始化失败！\n");
            }
            break;
        }

        case 'b':{//整栈摧毁
            result = destroyStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("销毁成功！\n");
            }
            break;
        }

        case 'c':{//判断空栈
            result = isEmptyStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            break;
        }
        
        case 'd':{//获得栈顶元素
            ElemType e;
            result = getTopStack(s,&e);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("栈顶元素为:%d\n",e);
            }
            break;
        }

        case 'e':{//整栈清空
            result = clearStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("整栈清空成功！\n");
            }
            break;
        }

        case 'f':{//栈的大小
            int length;
            result = stackLength(s,&length);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("栈的大小为:%d\n",length);
            }
            break;
        }

        case 'g':{//插入一个数据
            ElemType value;
            printf("请输入int数值范围内的数:");
            scanf("%d",&value);
            getchar();//吃回车
            while (value>2147483647 || value<-2147483648)
            {
                printf("请输入int数值范围内的数:");
                scanf("%d",&value);
                getchar();
            }
            result = pushStack(s,value);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("插入成功！\n");
            }
            break;
        }

        case 'h':{//删除栈顶元素
            ElemType value;
            result = popStack(s,&value);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("删除的元素值为:%d\n",value);
            }
            break;
        }

        case 'i':{//遍历栈元素
            result = TraverseStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("\n");
            }
            break;
        }

        case 'j':{
            system("cls");
            break;
        }
    
        default:{
            printf("请输入从a到j的字母！\n");
            break;
        }
    }   
}