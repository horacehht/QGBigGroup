#include"duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
DuLinkedList L;
void showmenu();
void choice(char str);
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
void showmenu(){
    printf("------a.创建空表------\n");
    printf("------b.空表接n个结点-\n"); 
    printf("------c.前插入元素------\n");
    printf("------d.后插入元素------\n");
    printf("------e.删除元素------\n");
    printf("------f.遍历链表------\n");
    printf("------h.整表删除------\n");
    printf("请选择:");
}
void choice(char str){
    Status result;//用于记录结果
    switch (str)
    {
    case 'a':{
        result = InitList_DuL(&L);
        if(result){
            printf("链表初始化成功\n");
        }
        else{
            printf("链表初始化失败，请重新初始化\n");
        }
        break;
    }

    case 'b':{
        int n;
        printf("请输入想创造结点的个数:");
        scanf("%d",&n);
        getchar();
        CreateDuList(&L,n);
        break;
    }

    case 'c':{
        DuLinkedList p,q;
        q = (DuLinkedList)malloc(sizeof(DuLNode));
        int i;
        printf("请输入你想插入的数据及想插入到第几个:");
        scanf("%d %d",&(q->data),&i);//给q结点数据和i赋值
        getchar();
        //用自制函数Get_ith_Node获得第i个结点的地址
        p = Get_ith_Node(L,i);
        if(p==L){
            printf("插入失败！请检查插入位置。\n");
        }
        else{
            result = InsertBeforeList_DuL(p,q);
        }
        break;
    }

    case 'd':{
        DuLinkedList p,q;
        q = (DuLinkedList)malloc(sizeof(DuLNode));
        int i;
        printf("请输入你想插入的数据及想插入到第几个:");
        scanf("%d %d",&(q->data),&i);//给q结点数据和i赋值
        getchar();
        //用自制函数Get_ith_Node获得第i个结点的地址
        p = Get_ith_Node(L,i);
        if(p == L){
            printf("插入失败！请检查插入位置。\n");
        }
        else{
            result = InsertBeforeList_DuL(p,q);
        }
        break;
    }

    case 'e':{
        printf("你想删除第几个结点：");
        int i,value;
        scanf("%d",&i);
        getchar();
        DuLinkedList p = Get_ith_Node(L,i);
        if(p==L){
            printf("删除失败！请检查删除位置\n");
            break;
        }
        result = DeleteList_DuL(p,&value);
        printf("删除成功！\n");
        break;
    }

    case 'f':{
        printf("这是表中所有数据：");
        void (*pfunc)(ElemType e);
        pfunc = print;
        if((L->prior)==(L->next)) break;
        TraverseList_DuL(L,pfunc);
        printf("\n");
        break;
    }

    case 'h':{
        DestroyList_DuL(&L);     
        break;
    }

    default:{
        printf("请输入a到h的小写字母！\n");
        break;
    }
        
    }
}