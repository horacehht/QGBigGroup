//
// Created by Horace on 2021/4/23.
//

#ifndef BINARY_SORT_TREE_H
#define BINARY_SORT_TREE_H
#include <stdio.h>
#include <stdlib.h>
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

typedef  struct StackNode
{
    Node data;
    struct StackNode *next;
}StackNode, *StackNodePtr;

typedef  struct  LinkStack
{
    StackNodePtr top;
    int	count;
}LinkStack;

//typedef struct Aqueue
//{
//    Node data[10000];
//    int front;
//    int rear;
//    int length;        //队列长度
//} AQueue;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr T);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(NodePtr *T, ElemType key);


/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(NodePtr *T, ElemType data);
//BST_delete的辅助函数
Status Delete(NodePtr *p);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr T, ElemType key, NodePtr f, NodePtr *p);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_preorderI(Node *, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_preorderR(Node *, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_inorderI(Node *, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_inorderR(Node *, void (*visit)(NodePtr));

/**
 * BST postorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_postorderI(Node *, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_postorderR(Node *root, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
void BST_levelOrder(Node *, void (*visit)(NodePtr));

void Nodeprint(Node *);

//栈函数
int initLStack(LinkStack *s);

int isEmptyLStack(LinkStack *s);

StackNodePtr getTopLStack(LinkStack *s);

int pushLStack(LinkStack *s, NodePtr ts);

int popLStack(LinkStack *s);

//队列函数
//int IsEmptyAQueue(AQueue *Q);
//
//int LengthAQueue(AQueue *Q);
//
//int EnAQueue(AQueue *Q, Node ts);
//
//int DeAQueue(AQueue *Q);

void showmenu();

#endif //BINARY_SORT_TREE_H
