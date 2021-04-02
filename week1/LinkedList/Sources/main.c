#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>
LinkedList L;
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
    printf("------c.插入元素------\n");
    printf("------d.删除元素------\n");
    printf("------e.遍历链表------\n");
    printf("------f.查找元素------\n");
    printf("------g.逆转整表------\n");
    printf("------h.判断成环------\n");
    printf("------i.获得中间结点--\n");
    printf("------j.整表删除------\n");
    printf("请选择:");
}
void choice(char str){
    Status result;//用于记录结果
    switch (str)
    {
    case 'a':{
        result = InitList(&L);
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
        CreateList(&L,n);
        break;
    }

    case 'c':{
        LinkedList p,q;
        q = (LinkedList)malloc(sizeof(LNode));
        int i;
        printf("请输入你想插入的数据及想插入到第几个:");
        scanf("%d %d",&(q->data),&i);//给q结点数据和i赋值
        getchar();
        //用自制函数Get_ith_Node获得第i个结点的地址
        p = Get_ith_Node(L,i);
        result = InsertList(p,q);
        if(result==SUCCESS){
            printf("插入成功！\n");
        }
        else{
            printf("插入失败！请检查插入位置。\n");
        }
        break;
    }

    case 'd':{
        printf("你想删除第几个结点：");
        int i,value;
        scanf("%d",&i);
        getchar();
        LinkedList p = Get_ith_Node(L,i);
        if(p==NULL){
            printf("删除失败！请检查删除位置\n");
            break;
        }
        result = DeleteList(p,&value);
        printf("删除成功！\n");
        break;
    }

    case 'e':{
        printf("这是表中所有数据：");
        void (*pfunc)(ElemType e);
        pfunc = print;
        if(L==NULL) break;
        TraverseList(L,pfunc);
        printf("\n");
        break;
    }

    case 'f':{
        int value;
        printf("你想查找值为多少的结点：");
        scanf("%d",&value);
        getchar();
        result = SearchList(L,value);
        //提示性文字已嵌入SeachList中。此处不填写
        break;
    }

    case 'g':{
        result = ReverseList(&L);
        if(result==SUCCESS){
            printf("逆转成功！\n");
        }
        else{
            printf("逆转失败！\n");
        }
        break;
    }

    case 'h':{
        result = IsLoopList(L);
        if(result==SUCCESS){
            printf("是成环链表\n");
        }
        else{
            printf("不是成环链表\n");
        }
        break;
    }

    case 'i':{
        LinkedList p;
        p = FindMidNode(&L);
        printf("中间结点的地址为%p 值为%d\n",p,p->data);
        break;
    }

    case 'j':{
        DestroyList(&L);     
        break;
    }

    default:{
        printf("请输入a到j的小写字母！\n");
        break;
    }
        
    }
}