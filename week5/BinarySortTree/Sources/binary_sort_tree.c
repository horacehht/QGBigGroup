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
    //����������
    T->root = (Node*)malloc(sizeof(Node));
    T->root->left = NULL;
    T->root->right = NULL;
    printf("�����ö��������ڵ�ĳ�ʼֵ:");
    int num;
    while(scanf("%d", &num) == 0 || getchar() != '\n')
    {
        printf("���벻�淶������������:");
        while(getchar() != '\n'); // ��ջ�����
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
    if(!BST_search(*T, key, NULL, &p)){//���Ҳ��ɹ�
        //��Tָ����ڵ�ʱ��f�ĳ�ֵΪNULL
        s = (NodePtr)malloc(sizeof(Node));
        s->value = key;
        s->left = NULL;
        s->right = NULL;
        if(!p){
            *T = s;//����sΪ�µĸ��ڵ�
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
        return failed;//�������йؼ�����ͬ�Ľ��
}

//���������ɾ���ĵĸ�������
Status Delete(struct Node **p){
    NodePtr q,s;
    if( (*p)->right==NULL ){//������Ϊ����ֻ���ؽ�����������
        q = *p;
        *p = (*p)->left;
        free(q);
    }
    else if( (*p)->left==NULL ){//������Ϊ��ֻ�������������
        q = *p;
        *p = (*p)->right;
        free(q);
    }
    else{//������������Ϊ��
        q = *p;
        s = (*p)->left;
        while(s->right){
            q = s;
            s = s->right;
        }//���������ĵ�����Ҷ���
        (*p)->value = s->value;
        if(q != *p){
            q->right = s->left;
        }//�ؽ�q��������
        else{
            q->left = s->left;
        }//�ؽ�q��������
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
        return failed;//�Ҳ���
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
    //����������f��T��˫��
    if(!T){//���Ҳ��ɹ�
        *p = f;
        return failed;
    }
    else if(key == T->value){//���ҳɹ�
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
    //��ʼ������
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
//        //����ͷ�������Һ����������
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
    printf("*       1.��������     *\n");
    printf("*       2.��������       *\n");
    printf("*       3.ɾ������       *\n");
    printf("*       4.�ݹ�ǰ�����       *\n");
    printf("*       5.�ݹ��������       *\n");
    printf("*       6.�ݹ�������       *\n");
    printf("*     7.����ǰ�����     *\n");
    printf("*       8.�����������       *\n");
    printf("*         9.�����������         *\n");
    printf("*         10.�������         *\n");
    printf("*         11.�˳�����         *\n");
    printf("**************************\n");
    printf("���������ֽ��ж�Ӧ����:");
}

//ջ��������
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
    //�������
    r->next = s->top;
    s->top = r;
    s->count++;
    //������ֵ����ԭ��ջ��ͬ�ľ�������ط�
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
//        //����ǿնӣ�����ӵ���ǰ
//        //�������ݹ���
//        Q->data[Q->front] = ts;
//        Q->rear = (Q->rear + 1) % Q->length;
//        return succeed;
//    }
//    //������ǿնӣ����뵽��β
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
//    // %���Ƕ�βrear�ѵ�����ĩβ������ص����鿪ͷ������%�Ż�Խ��
//    return succeed;
//}

