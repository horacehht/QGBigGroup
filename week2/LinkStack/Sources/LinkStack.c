#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\LinkStack.h"//引用不同文件夹的头文件
//每前进一个目录加一个点

//三个状态量
int isempty = 1;//isempty用来检验栈是否为空栈，1为空，0为非空
int isdestroyed = 1;//是否被销毁，1为销毁，0为未销毁
int isinited = 0;//是否已初始化，1为已初始化，0为未初始化

/**
 *  @name        : Status initLStack(LinkStack **s)
 *	@description : initialize the LinkStack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
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

/**
 *  @name        : Status isEmptyLStack(LinkStack *s)
 *	@description : determine whether the LinkStack is empty or not
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmptyLStack(LinkStack *s){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else{
        if(isempty==1){
            printf("栈为空！\n");
            return SUCCESS;
        }
        if(isempty==0){
            printf("栈非空！\n");
            return SUCCESS;
        }
    }
    return SUCCESS;    
}

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : get the top element data in LinkStack and store its value in e
 *	@param		 : LinkStack *s, ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
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

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : get the top element data in LinkStack and store its value in e
 *	@param		 : LinkStack *s, ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
Status clearLStack(LinkStack *s){
    if(isdestroyed==1){
        printf("栈已被清空！\n");
        return ERROR;
    }
    else{
            if(isinited==0){
            printf("未进行初始化！\n");
            return ERROR;
        }
        if(isinited==1&&isempty==1){
            printf("已为空栈，无需删除\n");
            return ERROR;
        }
        else{
            LinkStackPtr p;
            p = s->top->next;
            while (p)
            {
                free(s->top);
                s->top = p;
                s->count--;
                p = p->next;
            }//循环结束后还剩一个栈结点
            free(s->top);//删掉最后一个结点
            s->top = NULL;
            s->count = 0;
            isempty = 1;
            isdestroyed = 0;
            return SUCCESS;
        }
    }
}

/**
 *  @name        : Status destroyLStack(LinkStack *s)
 *	@description : destroy the LinkStack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status destroyLStack(LinkStack *s){
    if(isinited==0){
        printf("未进行初始化！\n");
        return ERROR;
    }
    else{
        if(isempty==1){//那么只需销毁掉结构体
            free(s);
            s = NULL;
            isempty = 0;
            isdestroyed = 1;
            isinited = 0;
            return SUCCESS;
        }
        else{//要把链栈销毁，并把结构体销毁
            LinkStackPtr p;
            p = s->top->next;
            while (p){
                free(s->top);
                s->top = p;
                s->count--;
                p = p->next;
            }//循环结束后还剩一个栈结点
            free(s->top);
            free(s);//把整个结构体都给销毁掉
            s = NULL;
            isempty = 0;
            isdestroyed = 1;
            isinited = 0;
            return SUCCESS;
        }
    }
}

/**
 *  @name        : Status LStackLength(LinkStack *s,int *length)
 *	@description : get the length of the LinkStack
 *	@param		 : LinkStack *s,int *length
 *	@return		 : Status
 *  @notice      : None
 */
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

/**
 *  @name        : Status pushLStack(LinkStack *s,ElemType data)
 *	@description : push the data into the LinkStack
 *	@param		 : LinkStack *s,ElemType data
 *	@return		 : Status
 *  @notice      : None
 */
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

/**
 *  @name        : Status popLStack(LinkStack *s,ElemType *data)
 *	@description : pop out the top element in the LinkStack
 *	@param		 : LinkStack *s,ElemType *data
 *	@return		 : Status
 *  @notice      : None
 */
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

/**
 *  @name        : Status pushNodes(LinkStack *s,int n)
 *	@description : push many datas into the LinkStack
 *	@param		 : LinkStack *s,int n
 *	@return		 : Status
 *  @notice      : None
 */
Status pushNodes(LinkStack *s,int n){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    else{
        if(n<=0){
        printf("请输入正确范围内的数字！（自然数）\n");
        return ERROR;
        }
        else{
            for (int i = 1; i <= n; i++)
            {
                ElemType value; 
                scanf("%d",&value);
                getchar();//吃scanf输入的回车
                LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
                p->data = value;
                p->next = s->top;
                s->top = p;
                s->count++;
            }
            isempty = 0;
            return SUCCESS;
        }
    }
}

/**
 *  @name        : Status TraverseLStack(LinkStack *s)
 *	@description : print the data 
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status TraverseLStack(LinkStack *s){
    if(isinited==0){
        printf("栈未初始化！\n");
        return ERROR;
    }
    LinkStackPtr p;
    p = s->top;
    if(p==NULL){
        printf("空栈无元素！\n");
        return ERROR;
    }
    printf("栈顶到栈底的元素为:");
    while (p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    return SUCCESS;
}

/**
 *  @name        : void showmenu()
 *	@description : show menu on dos
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */
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
    printf("*     i.插入多个元素     *\n");
    printf("*         j.遍历         *\n");
    printf("*         k.清屏         *\n");
    printf("**************************\n");
    printf("你的选择是:");
}