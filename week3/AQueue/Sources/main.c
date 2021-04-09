#include <stdio.h>
#include<stdlib.h>
#include "AQueue.h"
AQueue Q;
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
            InitAQueue(&Q);
            printf("队列初始化成功！\n");
            break;
        }

        case 'b':{//摧毁队列
            result = DestroyAQueue(&Q);
            if(result==FALSE){
                printf("请重新选择！\n");
            }
            else{
                printf("销毁成功！\n");
            }
            break;
        }

        case 'c':{//队列满判断
            result = IsFullAQueue(&Q);
            if(result==FALSE){
                printf("请重新选择！\n");
            }
            else{
                printf("队列已满！\n");
            }
            break;
        }

        case 'd':{//队列空判断
            result = IsEmptyAQueue(&Q);
            if(result==FALSE){
                printf("请重新选择！\n");
            }
            else{
                printf("队列为空！\n");
            }
            break;
        }

        case 'e':{//获得队头元素
            void* e = malloc(20);
            result = GetHeadAQueue(&Q, e);
            if(result == FALSE){
                printf("请重新选择！\n");
            }
            else{
                printf("队头元素为:");
                APrint(e, Q.type[Q.front+1]);
                printf("\n");
            }
            break;
        }

        case 'f':{//队列的长度
            int length = LengthAQueue(&Q);
            if(length == -1){
                printf("队列未初始化！\n");
                break;
            }
            printf("队列现在的长度为:%d\n", length);
            break;
        }

        case 'g':{//入队
            inputdata(&Q);
            break;
        }

        case 'h':{//出队
            result = DeAQueue(&Q);
            if(result == TRUE){
                printf("出队成功！\n");
            }
            else{
                printf("请重新选择！\n");
            }
            break;
        }

        case 'i':{//清空队列
            ClearAQueue(&Q);
            printf("清空队列成功！\n");
            break;
        }

        case 'j':{//遍历队列元素
            result = TraverseAQueue(&Q, APrint);
            if(result == TRUE){
                printf("\n遍历完毕！\n");
            }
            else {
                printf("请重新选择！\n");x
            }
            break;
        }

        case 'k':{//清屏
            system("cls");
            break;
        }

        default:{
            printf("请输入从a到k的字母！\n");
            break;
        }
    }
}