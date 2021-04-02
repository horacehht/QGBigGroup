#include "linkedList.h"
#include<stdlib.h>
#include<stdio.h>
/**
 *  @name        : LNode* Get_ith_Node(LinkedList L,int i);
 *	@description : get the address of the i-th node
 *	@param		 : L(the head node),i
 *	@return		 : LNode*
 *  @notice      : I wrote this function because it's commonly used.
 */
LNode* Get_ith_Node(LinkedList L,int i){
    LinkedList p;
    int j = 1;
    p = L;
    while (p && j<i)
    {
        p = p->next;
        ++j;
    }
    if ( !p || j>i )
        return NULL;
    else{
        return p;
    }
}
/**
 *  @name        : void CreateList(LinkedList *L,int n)
 *	@description : create linklist with n nodes
 *	@param		 : L(the head node),n
 *	@return		 : None
 *  @notice      : None
 */
void CreateList(LinkedList *L,int n){
    LinkedList p,r;
    int i;
    r = *L;
    for ( i = 1; i <= n; i++)
    {
        p = (LinkedList)malloc(sizeof(LNode));
        p->data = i;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    LinkedList head;//声明头s结点
    head = (LinkedList)malloc(sizeof(LNode));//给头结点申请空间
    if(head==NULL){//内存没分配成功
        *L = NULL;
        return ERROR;
    }
    *L = head;//L指向头指针
    head->next = NULL;//以防万一
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    //所有节点删除（包括头结点），令L指空
    LinkedList p,q;//p是后移工作指针,q是工具人
    p = (*L);//获得头结点
    while (p){
        q = p->next;//先把p的下一个结点存起来
        free(p);//把该结点free掉
        p = q;//把下个结点赋给q
    }//循环往复，直到遇到NULL跳出循环，此时整表只剩一个L
    *L = NULL;//L指空，防止L外面乱搞
    printf("整表删除成功！\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    //即使p是表尾也没问题的！
    if(p==NULL){//debug出来加上的条件判断
        return ERROR;
    }
    LinkedList r = p->next;
    p->next = q;
    q->next = r;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList q,r;
    q = p->next;//q指向p的下一个结点
    if(q==NULL){//即p是表尾或空表
        return ERROR;
    }
    r = q->next;
    p->next = r;
    free(q);  
    *e = q->data;
    return SUCCESS;
}

/**
 *  @name        : void visit (ElemType e)
 *	@description : just for print
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : None
 */
void print(ElemType e){
    printf("%d ",e);
}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e){
    LinkedList p;
    p = L->next;//p指向第一个结点
    int cnt = 1;//表示是第几个结点
    if(p==NULL){
        printf("空表！终止查找\n");
        return ERROR;
    }
    else{
        while (p){
            if(p->data==e){//找到了
                printf("查找成功，在第%d个结点有元素值%d\n",cnt,e);
                return SUCCESS;
            }
            else{
                p = p->next;//后移到下一个结点
                cnt++;
            }//没找到就一直往后找
        }//如果跳出了循环，说明到了表尾还没找到
        printf("查找不到值为%d的结点\n",e);
        return ERROR;
    }
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LinkedList pre = NULL;//当前结点的前一个，初值为NULL
    LinkedList cur = (*L)->next;//指当前结点，初值为第一个结点
    if(cur==NULL){//空表
        return ERROR;
    }
    while (cur!=NULL){//推演后发现，只有一个结点时（不包括头结点），也不会出错。
        LinkedList t = cur->next;
        cur->next = pre;
        pre = cur;
        cur = t;
    }//循环结束pre是第一个结点，cur指向NULL
    (*L)->next = pre;//将头结点指向逆转后的第一个结点
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    //如果是个带头结点的空循环链表，即头结点next指向自己
    if(L->next==L){
        return SUCCESS;//是成环链表
    }
    LinkedList p = L,q = L;//快慢指针法
    //设p为慢指针，q为快指针
    while (q)
    {
        p = p->next;//p走一步
        q = q->next;
        if(q!=NULL){//如果第一步就已经走到表尾，那就不能再往下走了 
            q = q->next;//q走两步
        }
        if(p==q){//相遇了
            return SUCCESS;//是成环链表
        }
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    if((*L)->next==NULL){//空表
        return *L;
    }
    if((*L)->next->next==NULL){//只有一个结点
        return *L;
    }
    //下面写的行不通
    LinkedList pre,p;//pre指向前一个，p视为当前结点
    pre = (*L)->next;//初值是第一个结点
    p = pre->next;//p初值是第二个结点
    while (p)
    {
        //假设是1-2-3-4
        LinkedList r = p->next;//r存着3
        pre->next = p->next;//让1指向3，同时断了1到2的路
        //如今1，2都指着3
        p->next = pre;//让2指向1，现在变为2-1-3-4
        pre = r;//pre移到3的位置
        p = pre->next;//p移到4的位置
    }
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    if((*L)->next==NULL){//空表
        return *L;//返回头结点
    }
    if((*L)->next->next==NULL){//只有一个结点
        return (*L)->next;//返回第一个结点
    }
    LinkedList p,q;//p为慢，q为快
    p = (*L)->next;
    q = (*L)->next;
    while (q->next)
    {
        q = q->next;
        if(q){
            q = q->next;
        }
        p = p->next;
    }//q为表尾
    return p;
}

