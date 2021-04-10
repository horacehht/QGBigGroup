#include <stdio.h>
#include<stdlib.h>
#include "LQueue.h"
LQueue Q;
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
            InitLQueue(&Q);
            printf("���г�ʼ���ɹ���\n");
            break;
        }

        case 'b':{//�ݻٶ���
            result = DestroyLQueue(&Q);
            if(result==FALSE){
                printf("������ѡ��\n");
            }
            else{
                printf("���ٳɹ���\n");
            }
            break;
        }

        case 'c':{//���п��ж�
            result = IsEmptyLQueue(&Q);
            if(result==FALSE){
                printf("������ѡ��\n");
            }
            else{
                printf("����Ϊ�գ�\n");
            }
            break;
        }

        case 'd':{//��ö�ͷԪ��
            result = GetHeadLQueue(&Q);
            if(result == FALSE){
                printf("������ѡ��\n");
            }
            break;
        }

        case 'e':{//���еĳ���
            int length = LengthLQueue(&Q);
            if(length == -1){
                printf("����δ��ʼ����\n");
                break;
            }
            printf("�������ڵĳ���Ϊ:%d\n", length);
            break;
        }

        case 'f':{//���
            inputdata(&Q);
            break;
        }

        case 'g':{//����
            result = DeLQueue(&Q);
            if(result == TRUE){
                printf("���ӳɹ���\n");
            }
            else{
                printf("������ѡ��\n");
            }
            break;
        }

        case 'h':{//��ն���
            result = ClearLQueue(&Q);
            if(result == TRUE)
                printf("��ն��гɹ���\n");
            else
                printf("������ѡ��\n");
            break;
        }

        case 'i':{//��������Ԫ��
            result = TraverseLQueue(&Q, LPrint);
            if(result == TRUE){
                printf("\n������ϣ�\n");
            }
            else {
                printf("������ѡ��\n");
            }
            break;
        }

        case 'j':{//����
            system("cls");
            break;
        }

        default:{
            printf("�������a��j����ĸ��\n");
            break;
        }
    }
}