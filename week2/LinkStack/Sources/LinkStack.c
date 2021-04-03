#include<stdio.h>
#include<stdlib.h>
#include"..\Headers\LinkStack.h"//引用不同文件夹的头文件
//每前进一个目录加一个点

/**
 *  @name        : Status initLStack(LinkStack *s)
 *	@description : initialize the LinkStack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status initLStack(LinkStack *s){
    s->count = 0;
    s->top = NULL;
    isempty = 1;
    isdestoyed = 0;
    isinited = 1;
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
        if(isdestoyed==1){
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
    if(isdestoyed==1){
        printf("栈已被摧毁！\n");
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
            LinkStackPtr p,q;
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
            isdestoyed = 0;
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
            isdestoyed = 1;
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
        if(isdestoyed==1){
            printf("栈已被摧毁！\n");
            return ERROR;
        }
        else{
            LinkStackPtr r = (LinkStackPtr)malloc(sizeof(LinkStack));
            r->data = data;
            r->next = s->top;
            s->top = r;
            s->count++;
            if(s->count>0){
                isempty = 0;
            }
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
        if(isdestoyed==1){
            printf("栈已被摧毁！\n");
            return ERROR;
        }
        else{
            if(isempty==0){
                printf("空栈无法删除！\n");
                return ERROR;
            }
            else{
                LinkStackPtr p;
                p = s->top;
                *data = p->data;
                s->top = p->next;
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
                scanf("%d",value);
                getchar();//吃scanf输入的回车
                LinkStackPtr p = (LinkStackPtr)malloc(sizeof(LinkStack));
                p->data = value;
                p->next = s->top;
                s->top = p;
            }
            return SUCCESS;
        }
    }
}

/**
 *  @name        : void showmenu()
 *	@description : show menu on dos
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */
void showmenu(){
    printf("********************\n");
    printf("*       a.初始化栈       *\n");
    printf("*       b.销毁整栈       *\n");
    printf("*       c.是否空栈       *\n");
    printf("*       d.栈顶元素       *\n");
    printf("*       e.清空整栈       *\n");
    printf("*       f.元素个数       *\n");
    printf("*       g.插入元素       *\n");
    printf("*     h.删除栈顶元素       *\n");
    printf("*     i.插入多个元素     *\n");
    printf("你的选择是:");
}

/**
 *  @name        : void choice(char str)
 *	@description : user choose in dos
 *	@param		 : char str
 *	@return		 : None
 *  @notice      : None
 */
void choice(char str,LinkStack *s){
    Status result;//用于记录结果
    switch (str)
    {
        case 'a':{
            result = initLStack(s);
            break;
        }

        case 'b':{
            result = destroyLStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("整栈删除成功！\n");
            }
            break;
        }

        case 'c':{
            result = isEmptyLStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            break;
        }
        
        case 'd':{
            ElemType *e;
            result = getTopLStack(s,e);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("栈顶元素为:%d",*e);
            }
            break;
        }

        case 'e':{
            result = clearLStack(s);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("整栈清空成功！\n");
            }
            break;
        }

        case 'f':{
            int *length;
            result = LStackLength(s,length);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("栈的大小为:%d\n",*length);
            }
            break;
        }

        case 'g':{
            ElemType value;
            printf("请输入int数值范围内的数:");
            scanf("%d",value);
            getchar();//吃回车
            while (value>2147483647 || value<-2147483648)
            {
                printf("请输入int数值范围内的数:");
                scanf("%d",value);
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

        case 'h':{
            ElemType *value;
            result = popLStack(s,value);
            if(result==ERROR){
                printf("请重新选择！\n");
            }
            else{
                printf("删除的元素值为:%d\n",*value);
            }
            break;
        }

        default:{
            printf("请输入从a到h的字母！\n");
            break;
        }
    }   
}