#include<stdio.h>
#include<stdlib.h>
#include "binary_sort_tree.h"
BinarySortTree T;
int main(){
    BST_init(&T);
    int num;
    while(1)
    {
        //显示菜单
        showmenu();
        while(scanf("%d", &num) == 0 || getchar() != '\n')
        {
            printf("输入不规范，请重新输入:");
            while(getchar() != '\n'); // 清空缓冲区
        }
        Status result;//用于记录结果
        switch (num)
        {
            case 1:{//插入数字
                int e;
                printf("请输入需要插入的数字:");
                while(scanf("%d", &e) == 0 || getchar() != '\n')
                {
                    printf("输入不规范，请重新输入:");
                    while(getchar() != '\n'); // 清空缓冲区
                }
                result = BST_insert(&T.root, e);
                if(result == succeed){
                    printf("插入成功！\n");
                }
                else{
                    printf("已存在该结点！插入失败！\n");
                }
                break;
            }

            case 2:{//查找数字
                int e;
                printf("请输入需要查找的数字:");
                while(scanf("%d", &e) == 0 || getchar() != '\n')
                {
                    printf("输入不规范，请重新输入:");
                    while(getchar() != '\n'); // 清空缓冲区
                }
                NodePtr p;
                result = BST_search(T.root, e, NULL, &p);
                if(result==succeed){
                    printf("树中有该结点！\n");
                }
                else{
                    printf("树中无该结点！\n");
                }
                break;
            }

            case 3:{//删除数字
                int e;
                printf("请输入需要删除的结点:");
                while(scanf("%d", &e) == 0 || getchar() != '\n')
                {
                    printf("输入不规范，请重新输入:");
                    while(getchar() != '\n'); // 清空缓冲区
                }
                result = BST_delete(&T.root, e);
                if(result == succeed){
                    printf("删除成功！\n");
                }
                else{
                    printf("删除失败！\n");
                }
                break;
            }

            case 4:{//递归前序遍历
                printf("递归前序遍历:");
                BST_preorderR(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 5:{//递归中序遍历
                printf("递归中序遍历:");
                BST_inorderR(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 6:{//递归后序遍历
                printf("递归后序遍历:");
                BST_postorderR(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 7:{//迭代前序遍历
                printf("迭代前序遍历:");
                BST_preorderI(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 8:{//迭代中序遍历
                printf("迭代中序遍历");
                BST_inorderI(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 9:{//迭代后序遍历
                printf("迭代后序遍历");
                BST_postorderI(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 10:{//层序遍历
                printf("层序遍历");
                BST_levelOrder(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 11:{//退出程序
                system("pause");
                break;
            }

            default:{
                printf("请输入1到11的数字！\n");
                break;
            }
        }
    }
    return 0;
}