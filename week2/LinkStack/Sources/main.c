#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\LinkStack.h"
LinkStack *s = NULL;
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
//choice不放在这，而采用传s参的话，在initLStack即使初始化后出来也没有赋到值，反正就很麻烦
//所以我决定放在main这里(虽说不美观，但是省事)
void choice(char str){
    Status result;//用于记录结果
    switch (str)
    {
        case 'a':{//初始化栈
            result = initLStack(&s);
            if(result==SUCCESS){
                printf("初始化成功！\n");
            }
            else{
                printf("初始化失败！\n");
            }
            break;
        }

        case 'b':{//整栈摧毁
            result = destroyLStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("销毁成功！\n");
            }
            break;
        }

        case 'c':{//判断空栈
            result = isEmptyLStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            break;
        }
        
        case 'd':{//获得栈顶元素
            ElemType e;
            result = getTopLStack(s,&e);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("栈顶元素为:%d\n",e);
            }
            break;
        }

        case 'e':{//整栈清空
            result = clearLStack(s);
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
            result = LStackLength(s,&length);
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
            result = pushLStack(s,value);
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
            result = popLStack(s,&value);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("删除的元素值为:%d\n",value);
            }
            break;
        }

        case 'i':{//插入多个数据
            int n;
            printf("请输入插入数据的个数:");
            scanf("%d",&n);
            getchar();
            printf("请输入%d个数据:",n);
            result = pushNodes(s,n);
            if(result==ERROR){
                printf("请重新选择\n");
            }
            else{
                printf("插入成功！\n");
            }
            break;
        }

        case 'j':{//遍历栈元素
            result = TraverseLStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("\n");
            }
            break;
        }
        
        case 'k':{//清屏
            system("cls");
            break;
        }
        default:{
            printf("请输入从a到j的字母！\n");
            break;
        }
    }   
}