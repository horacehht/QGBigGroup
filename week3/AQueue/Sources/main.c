#include <stdio.h>
#include<stdlib.h>
#include "AQueue.h"
AQueue Q;
int main(){
    char str;
    while(1)
    {
        showmenu();
        scanf("%c",&str);
        getchar();
        choice(str);
    }
    return 0;
}

void choice(char str){
    Status result;//���ڼ�¼���
    switch (str)
    {
        case 'a':{//��ʼ������
            InitAQueue(&Q);
            printf("���г�ʼ���ɹ���\n");
            break;
        }

        case 'b':{//�ݻٶ���
            result = DestroyAQueue(&Q);
            if(result==FALSE){
                printf("������ѡ��\n");
            }
            else{
                printf("���ٳɹ���\n");
            }
            break;
        }

        case 'c':{//�������ж�
            result = IsFullAQueue(&Q);
            if(result==FALSE){
                printf("������ѡ��\n");
            }
            else{
                printf("����������\n");
            }
            break;
        }

        case 'd':{//���п��ж�
            result = IsEmptyAQueue(&Q);
            if(result==FALSE){
                printf("������ѡ��\n");
            }
            else{
                printf("����Ϊ�գ�\n");
            }
            break;
        }

        case 'e':{//��ö�ͷԪ��
            void* e = malloc(20);
            result = GetHeadAQueue(&Q, e);
            if(result == FALSE){
                printf("������ѡ��\n");
            }
            else{
                printf("��ͷԪ��Ϊ:");
                APrint(e, Q.type[Q.front+1]);
                printf("\n");
            }
            break;
        }

        case 'f':{//���еĳ���
            int length = LengthAQueue(&Q);
            if(length == -1){
                printf("����δ��ʼ����\n");
                break;
            }
            printf("�������ڵĳ���Ϊ:%d\n", length);
            break;
        }

        case 'g':{//���
            inputdata(&Q);
            break;
        }

        case 'h':{//����
            result = DeAQueue(&Q);
            if(result == TRUE){
                printf("���ӳɹ���\n");
            }
            else{
                printf("������ѡ��\n");
            }
            break;
        }

        case 'i':{//��ն���
            ClearAQueue(&Q);
            printf("��ն��гɹ���\n");
            break;
        }

        case 'j':{//��������Ԫ��
            result = TraverseAQueue(&Q, APrint);
            if(result == TRUE){
                printf("\n������ϣ�\n");
            }
            else {
                printf("������ѡ��\n");x
            }
            break;
        }

        case 'k':{//����
            system("cls");
            break;
        }

        default:{
            printf("�������a��k����ĸ��\n");
            break;
        }
    }
}