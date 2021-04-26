//
// Created by Horace on 2021/4/23.
//

#include "binary_sort_tree.h"


/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr T){
    //建立二叉树
    T->root = (Node*)malloc(sizeof(Node));
    T->root->left = NULL;
    T->root->right = NULL;
    printf("请设置二叉树根节点的初始值:");
    int num;
    while(scanf("%d", &num) == 0 || getchar() != '\n')
    {
        printf("输入不规范，请重新输入:");
        while(getchar() != '\n'); // 清空缓冲区
    }
    T->root->value = num;
    return succeed;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(NodePtr *T, ElemType key){
    NodePtr p,s;
    if(!BST_search(*T, key, NULL, &p)){//查找不成功
        //当T指向根节点时，f的初值为NULL
        s = (NodePtr)malloc(sizeof(Node));
        s->value = key;
        s->left = NULL;
        s->right = NULL;
        if(!p){
            *T = s;//插入s为新的根节点
        }
        else if(key < p->value){
            p->left = s;
        }
        else{
            p->right = s;
        }
        return succeed;
    }
    else
        return failed;//树中已有关键字相同的结点
}

//排序二叉树删除的的辅助函数
Status Delete(struct Node **p){
    NodePtr q,s;
    if( (*p)->right==NULL ){//右子树为空则只需重接它的左子树
        q = *p;
        *p = (*p)->left;
        free(q);
    }
    else if( (*p)->left==NULL ){//左子树为空只需接它的右子树
        q = *p;
        *p = (*p)->right;
        free(q);
    }
    else{//左右子树均不为空
        q = *p;
        s = (*p)->left;
        while(s->right){
            q = s;
            s = s->right;
        }//找左子树的的最右叶结点
        (*p)->value = s->value;
        if(q != *p){
            q->right = s->left;
        }//重接q的右子树
        else{
            q->left = s->left;
        }//重接q的左子树
        free(s);
    }
    return succeed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(NodePtr *T, ElemType data){
    if(!T)
        return failed;//找不到
    else{
        if((*T)->value == data)
            return Delete(T);
        else if(data < (*T)->value)
            return BST_delete(&( (*T)->left ), data);
        else if(data > (*T)->value)
            return BST_delete(&( (*T)->right ), data);
    }
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr T, ElemType key, NodePtr f, NodePtr *p){
    //第三个参数f是T的双亲
    if(!T){//查找不成功
        *p = f;
        return failed;
    }
    else if(key == T->value){//查找成功
        *p = T;
        return succeed;
    }
    else if(key < T->value)
        return BST_search(T->left, key, T, p);
    else
        return BST_search(T->right, key, T, p);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_preorderI(Node *root, void (*visit)(NodePtr)){
    LinkStack s;
    s.count = 0;
    s.top = NULL;
    if(root == NULL){
        return;
    }
    while(!isEmptyLStack(&s) || root != NULL){
        while(root != NULL){
            visit(root);
            pushLStack(&s, root);
            root = root->left;
        }
        root = &(getTopLStack(&s)->data);
        popLStack(&s);
        root = root->right;
    }
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_preorderR(Node *root, void (*visit)(NodePtr)){
    if(root == NULL){
        return;
    }
    visit(root);
    BST_preorderR(root->left, visit);
    BST_preorderR(root->right, visit);
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_inorderI(Node *root, void (*visit)(NodePtr)){
    NodePtr predecessor = NULL;
    while(root != NULL){
        if(root->left != NULL){
            //
            predecessor = root->left;
            while(predecessor->right != NULL && predecessor->right != root){
                predecessor = predecessor->right;
            }

            if(predecessor->right == NULL){
                predecessor->right = root;
                root = root->left;
            }

            else{
                visit(root);
                predecessor->right = NULL;
                root = root->right;
            }
        }

        else{
            visit(root);
            root = root->right;
        }
    }
//    while(root != NULL || s.top != NULL){
//        while(root != NULL){
//            pushLStack(&s, root);
//            root = root->left;
//        }
//        popLStack(&s);
//        root = &(s.top->data);
//        visit(root);
//        root = root->right;
//    }
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_inorderR(Node *root, void (*visit)(NodePtr)){
    if(root == NULL){
        return;
    }
    BST_preorderR(root->left, visit);
    visit(root);
    BST_preorderR(root->right, visit);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_postorderI(Node *root, void (*visit)(NodePtr)){
//    LinkStack s;
//    s.count = 0;
//    s.top = NULL;
//    if(root == NULL)
//        return;
//    NodePtr v[50000];
//    int i = 0;
//    while (isEmptyLStack(&s) || root != NULL){
//        while( root != NULL){
//            pushLStack(&s, root);
//            if(root->left != NULL)
//                root = root->left;
//            if(root->right != NULL)
//                root = root->right;
//        }
//        root = &(s.top->data);
//        popLStack(&s);
//        visit(root);
//
//        if(!isEmptyLStack(&s) && s.top->data.left == root){
//            root = s.top->data.right;
//        }
//        else{
//            root = NULL;
//        }
//    }

}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_postorderR(Node *root, void (*visit)(NodePtr)){
    if(root == NULL){
        return;
    }
    BST_preorderR(root->left, visit);
    BST_preorderR(root->right, visit);
    visit(root);
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_levelOrder(Node *root, void (*visit)(NodePtr)){
    //初始化队列
//    AQueue Q;
//    Q.front = 0;
//    Q.rear = 0;
//    Q.length = 10000;
//    if(root == NULL)
//        return;
//    EnAQueue(&Q, *root);
//    while(Q.front < Q.rear){
//        Node p = Q.data[Q.front];
//        DeAQueue(&Q);
//        visit(&p);
//        //将队头结点的左右孩子依此入队
//        if(p.left != NULL){
//            EnAQueue(&Q, *(p.left));
//        }
//        if(p.right != NULL){
//            EnAQueue(&Q, *(p.right));
//        }
//    }
}

void Nodeprint(Node* node){
    printf("%d->", node->value);
}

void showmenu(){
    printf("**************************\n");
    printf("*       1.插入数字     *\n");
    printf("*       2.查找数字       *\n");
    printf("*       3.删除数字       *\n");
    printf("*       4.递归前序遍历       *\n");
    printf("*       5.递归中序遍历       *\n");
    printf("*       6.递归后序遍历       *\n");
    printf("*     7.迭代前序遍历     *\n");
    printf("*       8.迭代中序遍历       *\n");
    printf("*         9.迭代后序遍历         *\n");
    printf("*         10.层序遍历         *\n");
    printf("*         11.退出程序         *\n");
    printf("**************************\n");
    printf("请输入数字进行对应操作:");
}

//栈函数部分
int initLStack(LinkStack *s){
    s = (StackNodePtr)malloc(sizeof(LinkStack));
    s->count = 0;
    s->top = NULL;
    return succeed;
}

int isEmptyLStack(LinkStack *s){
    if(s->count == 0){
        return succeed;
    }
    else
        return failed;
}

StackNodePtr getTopLStack(LinkStack *s){
    return s->top;
}

int pushLStack(LinkStack *s, NodePtr ts){
    StackNodePtr r = (StackNodePtr)malloc(sizeof(StackNode));
    //新增结点
    r->next = s->top;
    s->top = r;
    s->count++;
    //给他赋值，跟原来栈不同的就是这个地方
    r->data.right = ts->right;
    r->data.left = ts->left;
    r->data.value = ts->value;

    return succeed;
}

int popLStack(LinkStack *s){
    StackNodePtr p;
    p = s->top;
    s->top = p->next;
    s->count--;
    free(p);
    return succeed;
}

//int IsEmptyAQueue(AQueue *Q){
//    if (LengthAQueue(Q) == 0)
//        return succeed;
//    else
//        return failed;
//}
//
//int LengthAQueue(AQueue *Q){
//    int length = (Q->rear-Q->front+Q->length)%Q->length;
//    return length;
//}
//
//int EnAQueue(AQueue *Q, Node ts){
//    if (IsEmptyAQueue(Q))
//    {
//        //如果是空队，则入队到队前
//        //复制数据过程
//        Q->data[Q->front] = ts;
//        Q->rear = (Q->rear + 1) % Q->length;
//        return succeed;
//    }
//    //如果不是空队，则入到队尾
//    Q->data[Q->rear] = ts;
//    Q->rear = (Q->rear + 1) % Q->length;
//    return succeed;
//}
//
//int DeAQueue(AQueue *Q){
//    if (IsEmptyAQueue(Q))
//    {
//        return failed;
//    }
//    Q->front = (Q->front+1)%Q->length;
//    // %号是队尾rear已到数组末尾，让其回到数组开头，不用%号会越界
//    return succeed;
//}

