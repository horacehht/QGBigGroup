#include "duLinkedList.h"
#include<stdlib.h>
#include<stdio.h>
/**
 *  @name        : int GetListLength(DuLinkedList L)
 *	@description : Get the length of list
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
int GetListLength(DuLinkedList L){
    int cnt=0;
    DuLinkedList p=L->next;
    while (p!=L)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

/**
 *  @name        : LNode* Get_ith_Node(LinkedList L,int i);
 *	@description : get the address of the i-th node
 *	@param		 : L(the head node),i
 *	@return		 : LNode*
 *  @notice      : I wrote this function because it's commonly used.
 */
DuLNode* Get_ith_Node(DuLinkedList L,int i){
    DuLinkedList p;
    int j = 1;
    p = L->next;
    while (p!=L && j<i)
    {
        p = p->next;
        ++j;
    }//找到第i个或回到头结点
    if ( p==L || j>i )//回到头结点，或者用户输了个负数
        return L;
    else{
        return p;
    }
}

/**
 *  @name        : void CreateDuList(LinkedList *L,int n)
 *	@description : create linklist with n nodes
 *	@param		 : L(the head node),n
 *	@return		 : None
 *  @notice      : None
 */
void CreateDuList(DuLinkedList *L,int n){
    DuLinkedList p,r;
    int i;
    r = *L;
    for ( i = 1; i <= n; i++)
    {
        p = (DuLinkedList)malloc(sizeof(DuLNode));
        p->data = i;
        p->prior = r;
        p->next = (*L);
        r->next = p;
        r = p;
    }
}

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList head;//声明头s结点
    head = (DuLinkedList)malloc(sizeof(DuLNode));//给头结点申请空间
    if(head==NULL){//内存没分配成功
        *L = NULL;
        return ERROR;
    }
    *L = head;//L指向头指针
    head->next = head;//以防万一
    head->prior = head;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p,q;//p是后移工作指针,q是工具人
    p = (*L);//获得头结点
    int len = GetListLength(*L);
    int i = 0;
    //这里有个对头结点free两次的智障操作
    while (p && i<(len+1) ){
        q = p->next;//先把p的下一个结点存起来
        free(p);//把该结点free掉
        p = q;//把下个结点赋给q
        i++;
    }//跟单向链表不一样的是，双向尾结点next指向头结点，所以会把头结点也一起free掉
    //所以不用在外面进行额外的操作
    printf("整表删除成功！\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    q->prior = p->prior;
    q->next = p;
    p->prior->next = q;
    p->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    q->prior = p;
    q->next = p->next;
    p->next ->prior = q;
    p->next = q;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return SUCCESS;
}

/**
 *  @name        : void print (ElemType e)
 *	@description : print the data
 *	@param		 : ElemType e
 *	@return		 : None
 *  @notice      : None
 */
void print(ElemType e){
    printf("%d ",e);
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    visit = print;
    DuLinkedList p = L->next;
    while (p!=L)
    {
        visit(p->data);
        p = p->next;
    }
}
