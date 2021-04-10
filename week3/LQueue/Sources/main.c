#include <stdio.h>
#include<stdlib.h>
#include "LQueue.h"
LQueue Q;
int main(){
    char str;
    while(1)
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
        case 'a':{//初始化队列
            InitLQueue(&Q);
            printf("队列初始化成功！\n");
            break;
        }

        case 'b':{//摧毁队列
            result = DestroyLQueue(&Q);
            if(result==FALSE){
                printf("请重新选择！\n");
            }
            else{
                printf("销毁成功！\n");
            }
            break;
        }

        case 'c':{//队列空判断
            result = IsEmptyLQueue(&Q);
            if(result==FALSE){
                printf("请重新选择！\n");
            }
            else{
                printf("队列为空！\n");
            }
            break;
        }

        case 'd':{//获得队头元素
            result = GetHeadLQueue(&Q);
            if(result == FALSE){
                printf("请重新选择！\n");
            }
            break;
        }

        case 'e':{//队列的长度
            int length = LengthLQueue(&Q);
            if(length == -1){
                printf("队列未初始化！\n");
                break;
            }
            printf("队列现在的长度为:%d\n", length);
            break;
        }

        case 'f':{//入队
            inputdata(&Q);
            break;
        }

        case 'g':{//出队
            result = DeLQueue(&Q);
            if(result == TRUE){
                printf("出队成功！\n");
            }
            else{
                printf("请重新选择！\n");
            }
            break;
        }

        case 'h':{//清空队列
            result = ClearLQueue(&Q);
            if(result == TRUE)
                printf("清空队列成功！\n");
            else
                printf("请重新选择！\n");
            break;
        }

        case 'i':{//遍历队列元素
            result = TraverseLQueue(&Q, LPrint);
            if(result == TRUE){
                printf("\n遍历完毕！\n");
            }
            else {
                printf("请重新选择！\n");
            }
            break;
        }

        case 'j':{//清屏
            system("cls");
            break;
        }

        default:{
            printf("请输入从a到j的字母！\n");
            break;
        }
    }
}