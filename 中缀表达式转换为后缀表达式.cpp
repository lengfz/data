#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack * &s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s -> top = -1; 
}
void DestroyStack(SqStack * &s)
{
	free(s);
}
bool StackEmpty(SqStack * s)
{
	return(s->top == -1);
}
bool Push(SqStack * &s,char e)
{
	if (s -> top == MaxSize - 1)
		return false;
	s -> top ++;
	s -> data[s -> top] = e;
	printf("��ջ%c\n",s -> data[s -> top]);
	return true;
}
bool Pop(SqStack * &s,char e)
{
	if (s -> top == -1)
		return false;
	e = s -> data[s -> top];
	//printf("%c %d\n",e,s -> top); 
	s -> top --;
	return true;
}
bool GetTop(SqStack * &s,char e)
{
	if (s -> top == -1)
		return false;
	e = s-> data[s -> top];
	return true;
}
void trans(char * exp,char postexp[])
{
	char e;
	SqStack * Optr;							//���������ջָ�� 
	InitStack(Optr);						//��ʼ�������ջ 
	int i = 0;								//i��Ϊpostexp���±� 
	while (*exp != '\0')					//exp���ʽδɨ����ʱѭ�� 
	{
		switch(*exp) 
		{
			case'(':						//�ж�Ϊ������ 
				//printf("(\n");				
				Push(Optr,'('); 			//�����Ž�ջ   
				exp ++;						//����ɨ�������ַ�
				break;
			case')':
				//printf("top:%d\n",Optr -> top);
				Pop(Optr,e);				//��ջeԪ�� 
				while(e != '(')				//��Ϊ'('ʱѭ�� 
				{
					//printf("վ��");
					postexp[i ++] = e;		//��e�ŵ�postexp�� 
					Pop(Optr,e);			//������ջ
					//printf("Optr:%c \n",e);
					//printf("O:%d",Optr -> top);
				}
				exp ++;						//����ɨ�������ַ� 
				break;
			case'+':
			case'-':
				while(!StackEmpty(Optr))	//ջ����ѭ�� 
				{
					//printf("+-");
					GetTop(Optr,e);			//ȡջ��Ԫ��e 
					if (e!='(')				//e����'(' 
					{
						postexp[i ++] = e;	//��e����postexp 
						Pop(Optr,e);		//��ջԪ��e 
						//printf("+-��%c",e);
					}
					else					//e��'('ʱѭ�� 
						break;
				}
				Push(Optr,*exp);			//��+��-�Ž�ջ 
				exp++;
				break;
			case'*':
			case'/':
				while (!StackEmpty(Optr))	//ջ��Ϊ�ս���ѭ�� 
				{
					GetTop(Optr,e);			//ȡջ��Ԫ�� 
					if (e == '*' || e == '/')//��ջ��*��/ȡ��ջ����ŵ�postexp�� 
					{
						postexp[i ++] = e;	//��e��ŵ�postexp�� 
						Pop(Optr,e);		//��ջԪ��e 
					}
					else
						break;
				} 
				Push(Optr, * exp);			//��Ԫ��*��/��ջ 
				exp ++;						//����ɨ�����Ԫ�� 
				break;
			default:						//���������ַ� 
				while ( * exp >= '0' && * exp <= '9')	//�ж�Ϊ�����ַ� 
				{
					printf("shu\n");				
					postexp[i ++] = *exp; 
					exp ++;			
				}
				postexp[i ++] = '#';					//��#��ʶһ�����ִ��Ľ��� 
		}
	}
	printf("վ��");
	while (!StackEmpty(Optr))							//��ʱexpɨ����ϣ�ջ����ʱѭ�� 
	{
		
		Pop(Optr,e);									//��ջԪ��e 
		postexp[i ++] = e;								//��e��ŵ�postexp�� 
	}
	postexp[i] = '\0';									//��postexp���ʽ��ӽ�����ʶ 
	DestroyStack(Optr);									//����ջ 
}
int main()
{
	char exp[] = "(56-20)/(4+2)";
	//char exp[] = "()";
	char postexp[MaxSize];
	//scanf("%s",exp);
	trans(exp,postexp);
	printf("��׺���ʽ��%s\n",postexp);
	return 0;
}
