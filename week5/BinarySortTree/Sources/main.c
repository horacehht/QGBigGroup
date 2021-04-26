#include<stdio.h>
#include<stdlib.h>
#include "binary_sort_tree.h"
BinarySortTree T;
int main(){
    BST_init(&T);
    int num;
    while(1)
    {
        //��ʾ�˵�
        showmenu();
        while(scanf("%d", &num) == 0 || getchar() != '\n')
        {
            printf("���벻�淶������������:");
            while(getchar() != '\n'); // ��ջ�����
        }
        Status result;//���ڼ�¼���
        switch (num)
        {
            case 1:{//��������
                int e;
                printf("��������Ҫ���������:");
                while(scanf("%d", &e) == 0 || getchar() != '\n')
                {
                    printf("���벻�淶������������:");
                    while(getchar() != '\n'); // ��ջ�����
                }
                result = BST_insert(&T.root, e);
                if(result == succeed){
                    printf("����ɹ���\n");
                }
                else{
                    printf("�Ѵ��ڸý�㣡����ʧ�ܣ�\n");
                }
                break;
            }

            case 2:{//��������
                int e;
                printf("��������Ҫ���ҵ�����:");
                while(scanf("%d", &e) == 0 || getchar() != '\n')
                {
                    printf("���벻�淶������������:");
                    while(getchar() != '\n'); // ��ջ�����
                }
                NodePtr p;
                result = BST_search(T.root, e, NULL, &p);
                if(result==succeed){
                    printf("�����иý�㣡\n");
                }
                else{
                    printf("�����޸ý�㣡\n");
                }
                break;
            }

            case 3:{//ɾ������
                int e;
                printf("��������Ҫɾ���Ľ��:");
                while(scanf("%d", &e) == 0 || getchar() != '\n')
                {
                    printf("���벻�淶������������:");
                    while(getchar() != '\n'); // ��ջ�����
                }
                result = BST_delete(&T.root, e);
                if(result == succeed){
                    printf("ɾ���ɹ���\n");
                }
                else{
                    printf("ɾ��ʧ�ܣ�\n");
                }
                break;
            }

            case 4:{//�ݹ�ǰ�����
                printf("�ݹ�ǰ�����:");
                BST_preorderR(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 5:{//�ݹ��������
                printf("�ݹ��������:");
                BST_inorderR(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 6:{//�ݹ�������
                printf("�ݹ�������:");
                BST_postorderR(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 7:{//����ǰ�����
                printf("����ǰ�����:");
                BST_preorderI(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 8:{//�����������
                printf("�����������");
                BST_inorderI(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 9:{//�����������
                printf("�����������");
                BST_postorderI(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 10:{//�������
                printf("�������");
                BST_levelOrder(T.root, Nodeprint);
                printf("\n");
                break;
            }

            case 11:{//�˳�����
                system("pause");
                break;
            }

            default:{
                printf("������1��11�����֣�\n");
                break;
            }
        }
    }
    return 0;
}