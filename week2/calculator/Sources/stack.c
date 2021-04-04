#include"..\Headers\stack.h"
#include<stdlib.h>

Status initLStack(LinkStack **s){
    *s = (LinkStack*)malloc(sizeof(LinkStack));
    if(*s==NULL){//空间申请失败
        return ERROR;
    }
    else{
        (*s)->count = 0;
        (*s)->top = NULL;
        isempty = 1;
        isinited = 1;
        isdestroyed = 0;
    }
    return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e){
    if(isinited==0){
        printf("栈未初始化\n");
        return ERROR;
    }
    else{
        if(isdestroyed==1){
            printf("栈已被销毁！无栈顶元素\n");
            return ERROR;
        }
        else{
            if(isempty==1){
                printf("栈为空栈！无栈顶元素\n");
                return ERROR;
            }
            else{
                *e = s->top->data;
                return SUCCESS;
            }
        }
    }
}

Status LStackLength(LinkStack *s,int *length){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else if(isdestroyed==1){
        printf("栈已被销毁！\n");
        return ERROR;
    }
    else{
        *length = s->count;
        return SUCCESS;
    }
}

Status pushLStack(LinkStack *s,ElemType data){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else{
        if(isdestroyed==1){
            printf("栈已被摧毁！\n");
            return ERROR;
        }
        else{
            LinkStackPtr r = (LinkStackPtr)malloc(sizeof(StackNode));
            r->data = data;
            r->next = s->top;
            s->top = r;
            s->count++;
            isempty = 0;
            return SUCCESS;
        }
    }
}

Status popLStack(LinkStack *s,ElemType *data){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else{
        if(isdestroyed==1){
            printf("栈已被摧毁！\n");
            return ERROR;
        }
        else{
            if(isempty==1){
                printf("空栈无法删除！\n");
                return ERROR;
            }
            else{
                LinkStackPtr p;
                p = s->top;
                *data = p->data;
                s->top = p->next;
                s->count--;
                free(p);
                return SUCCESS;
            }
        }
    }
}