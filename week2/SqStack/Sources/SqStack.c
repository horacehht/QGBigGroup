#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>

int isdestroyed = 1;//是否被销毁，1为销毁，0为未销毁
int isinited = 0;//是否已初始化，1为已初始化，0为未初始化

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *elem;
	int top;
	int size;
} SqStack;


Status initStack(SqStack **s,int sizes){
    *s = (SqStack*)malloc(sizeof(SqStack));
    if(*s==NULL){
        printf("申请空间失败\n");
        return ERROR;
    }
    else{
        (*s)->top = -1;//-1标志空栈
        (*s)->size = sizes;//最大容量
        (*s)->elem = (ElemType*)malloc(sizes*sizeof(ElemType));//指向数组
        isinited = 1;
        isdestroyed = 0;
    }
    return SUCCESS;
}

Status isEmptyStack(SqStack *s){
    if(isinited == 0){
        printf("未初始化！\n");
        return ERROR;
    }
    else{
        if(s->top == -1){
            printf("空栈!\n");
            return SUCCESS;
        }
        else if(s->top > 0){
            printf("栈非空！\n");
            return SUCCESS;
        }
    }
    return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e){
    if(isinited == 0){
        printf("未初始化！\n");
        return ERROR;
    }
    else{
        if(s->top == -1){
            printf("栈为空栈！无栈顶元素\n");
            return ERROR;
        }
        else{
            *e = s->elem[s->top];
            return SUCCESS;
        }
    }
}

Status clearStack(SqStack *s){
    if(isinited == 0){
        printf("未初始化！\n");
        return ERROR;
    }
    else if(isinited == 1 && s->top == -1){
        printf("已为空栈，无需删除\n");
        return ERROR;
    }
    else{
        //这里用pop函数操作
        ElemType e;
        while (s->top > 0)
        {
            popStack(s,&e);
        }
        return SUCCESS;
    }
    return SUCCESS;
}

Status destroyStack(SqStack *s){
    if(isinited == 0){
        printf("未进行初始化！\n");
        return ERROR;
    }
    else{
        if(s->top == -1){//那么只需销毁掉结构体
            free(s);
            s = NULL;
            isdestroyed = 1;
            isinited = 0;
            return SUCCESS;
        }
        else{//要把顺序栈销毁，并把结构体销毁
            free(s->elem);
            free(s);
            isdestroyed = 1;
            isinited = 0;
            return SUCCESS;
        }
    }
}

Status stackLength(SqStack *s,int *length){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else{
        *length = s->top+1;
        return SUCCESS;
    }
}

Status pushStack(SqStack *s,ElemType data){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else{
        if(s->top == s->size-1){//栈满了
            printf("栈满！\n");
            return ERROR;
        }
        else{
            s->top++;
            s->elem[s->top] = data;
        }
        return SUCCESS;
    }
}

Status popStack(SqStack *s,ElemType *data){
    if(isinited == 0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else{
        if(s->top == -1){
            printf("空栈无法删除!\n");
            return ERROR;
        }
        else{
            *data = s->elem[s->top];
            s->top--;
            return SUCCESS;
        }
    }
}

Status TraverseStack(SqStack *s){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    if(s->top == -1){
        printf("空栈无元素！\n");
        return ERROR;
    }
    printf("栈顶到栈底的元素为:");
    for(int i = 0; i < s->top; i++){
        printf("%d ",s->elem[i]);
    }
    return SUCCESS;
}

void showmenu(){
    printf("**************************\n");
    printf("*       a.初始化栈       *\n");
    printf("*       b.销毁整栈       *\n");
    printf("*       c.是否空栈       *\n");
    printf("*       d.栈顶元素       *\n");
    printf("*       e.清空整栈       *\n");
    printf("*       f.元素个数       *\n");
    printf("*       g.插入元素       *\n");
    printf("*     h.删除栈顶元素     *\n");
    printf("*         i.遍历         *\n");
    printf("**************************\n");
    printf("你的选择是:");
}

#endif 