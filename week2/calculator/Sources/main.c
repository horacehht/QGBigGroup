#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include "..\Headers\calculator.h"

//��ʼ������ջ
charStack Stack1;
numStack Stack2;
charStack *operator = &Stack1;//operator����������ջ
numStack *operand =  &Stack2;//operand����������ջ

int main()
{
    //��ջ�ͷ�ջ�ĳ�ʼ��
    operand->count = 0;
    operand->top = NULL;
    operator->count = 0;
    operator->top = NULL;
    while(1)//��ͨ������
    {
        char str[1010];//��һ���㹻�������
        char mode;
        printf("��ѡ��һ��ģʽ(��������)\n");
        printf("1.��ͨ������(֧�ִ���������͸�������)\n");
        printf("2.����������(Ŀǰֻ֧�ּӷ�����Ϊcoder̫����)\n");
        scanf("%c",&mode);
        if(mode == '1')
        {
            printf("��ӭʹ����ͨ������(֧�ִ���������͸�������)\n");
            printf("������һ������ʽ���ԵȺ�=��β\n");
            scanf("%s",str);//¼�����ʽ
            getchar();
            int priority_top, priority_cur;
            LL number;
            int i = 0, len = strlen(str)-1;

            //��׺ת��׺
            while (i < len)
            {
                if(isdigit(str[i]))
                {//���������
                    number = 0;
                    while (i < len && isdigit(str[i]))
                    {//��ȫ����
                        number = number*10 + (str[i]-'0');
                        i++;
                    }
                    num_push(operand, number);
                }

                else
                {//��������Ĳ�������
                    if(char_length(operator) == 0)
                    {
                        if(str[i]=='(')
                        {
                            if(str[i+1]=='-' && isdigit(str[i+2]))
                            {//��һ�����Ǹ���
                                char_push(operator, str[i+1]);//ѹ�����
                                num_push(operand, 0);//��0ѹ����ջ���һ��0-��Ч��������ʵ�ָ���
                                number = 0;
                                int p = i+2;
                                while (p < len && isdigit(str[p]))
                                {//�Ѹ��ź�����ֶ�ȫ
                                    number = number*10 + (str[p]-'0');
                                    p++;
                                }//����ʱp�������������Ŵ�
                                i = p+1;//����������
                                num_push(operand, number);
                                number = calc(operand, operator);
                                num_push(operand, number);
                                continue;
                            }//������ѭ��
                            else
                            {//������Ǹ���������ѹ�뼴��
                                char_push(operator, str[i]);
                                i++;
                                continue;
                            }
                        }
                        else//������Ų���������
                        {
                            char_push(operator, str[i]);
                            i++;
                            continue;
                        }
                    }
                    //�������۵������ַ�

                    //�������۵��Ƿ����ַ�
                    priority_top = get_priority(char_top(operator));
                    priority_cur = get_priority(str[i]);
                    if(priority_cur == 0)
                    {//�����������
                        /*��Ҫ���������
                        1.���������Ǹ���
                        2.����������һ�������ı���ʽ*/
                        if(str[i+1]=='-' && isdigit(str[i+2]) )
                        {//�Ǹ���������55-67����һ����
                            char_push(operator, str[i+1]);//��ѹ�����
                            num_push(operand,0);
                            number = 0;
                            int p = i+2;
                            while (p < len && isdigit(str[p]))
                            {
                                // ��ȫ����
                                number = number * 10 + (str[p] - '0');
                                p++;
                            }//����ʱp�������������Ŵ�
                            i = p+1;//ֱ������������
                            num_push(operand, number);
                            continue;
                        }
                        //2.���������Ǹ������ı���ʽ
                        char_push(operator, str[i]);//�ǾͰ�������ѹ��ȥ�ͺ���
                        i++;
                    }

                    else if(priority_cur == 3)
                    {//��������������ţ����㵽��һ�������ţ��ڵı���ʽ��ֵ
                        while( char_top(operator) != '(' )
                        {
                            number = calc(operand, operator);
                            num_push(operand, number);
                        }
                        char_pop(operator);
                        i++;
                    }

                    else
                    {//�����Ӽ��˳�
                        while (char_length(operator)!= 0 && priority_cur <= priority_top)
                        {// ������в�����������ջ�����������ȼ���
                            // ��ô�����ȼ���ջ�����
                            number=calc(operand, operator);
                            num_push(operand, number);
                            //����һ��֮��������в����������ȡ�����ȼ�
                            if( char_length(operator)!= 0 )
                            {
                                priority_top = get_priority( char_top(operator) );
                            }
                        }
                        char_push(operator, str[i]);
                        i++;
                    }
                }
            }
            //��׺����ʽ��ת��Ϊ��׺����ʽ

            //�����׺����ʽ
            while ( char_length(operator)!= 0)
            {
                number = calc(operand, operator);
                num_push(operand, number);
            }

            LL result = num_top(operand);
            printf("%lld\n\n", result);
        }
        else if(mode=='2')
        {
            printf("�������������֣����������Կո����\n");
            int i,len_str1,len_str2,len_max,k,num=1;//����ͨ�����������Ƴ��京��
            char str1[1000];
            char str2[1000];
            //a�����ŵ�һ������b�����ŵڶ�������c���������ǵĺ�
            int a[1000]={0},b[1000]={0},c[1001]={0};
            //¼����������˳��¼��
            scanf("%s",str1);
            scanf("%s",str2);
            getchar();
            /*�洢���ַ�����Ӧ���������أ�����Ӧ�ú������뵽����λ+��λ��ʮλ+ʮλ����10����һλ��1
            �������˳��¼���ַ����飬������˵��������λ����ͬ����������ô�ҵ��������ĸ�λ��������أ�
            �����Ҿ�������¼������������Ͷ����˸�λ��ͬʱΪ��������������Ӧ��Ҫ���洢����������Ԫ�س�
            ʼֵ��ʼ��Ϊ��\0�������Զ���Ϊȫ�֣�����ʼ����ȫ�������Զ�ȫ0��*/
            len_str1=strlen(str1);
            for( i=0;i<=len_str1-1;++i)//������������ÿλ
                a[i]=str1[len_str1-1-i]-'0';//���ַ�ת��Ϊ����

            len_str2=strlen(str2);
            for( i=0;i<=len_str2-1;++i)
                b[i]=str2[len_str2-1-i]-'0';

            if(len_str1>len_str2)
                len_max=len_str1;
            else
                len_max=len_str2;
            //���߿���д�� len_max=len_str1>len_str2?len_str1:len_str2;��Ԫ�����

            k=0;
            for( i=0;i<len_max;++i)
            {//��ؼ��ĵط�
                c[i]=(a[i]+b[i]+k)%10;
                k=(a[i]+b[i]+k)/10;
            }
            if(k != 0)//���������������Ҫ��λ
                c[len_max]=1;
            if(c[len_max] == 1)
                printf("1");//�Ǿ���ǰ����һ��1
            for( i=len_max-1;i>=0;--i)//�������
                printf("%d",c[i]);
            printf("\n\n");
        }
        else
        {
            printf("���벻�淶������������\n");
            continue;
        }
    }
    return 0;
}
