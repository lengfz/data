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
	printf("进栈%c\n",s -> data[s -> top]);
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
	SqStack * Optr;							//定义运算符栈指针 
	InitStack(Optr);						//初始化运算符栈 
	int i = 0;								//i作为postexp的下标 
	while (*exp != '\0')					//exp表达式未扫描完时循环 
	{
		switch(*exp) 
		{
			case'(':						//判定为左括号 
				//printf("(\n");				
				Push(Optr,'('); 			//左括号进栈   
				exp ++;						//继续扫描其他字符
				break;
			case')':
				//printf("top:%d\n",Optr -> top);
				Pop(Optr,e);				//出栈e元素 
				while(e != '(')				//不为'('时循环 
				{
					//printf("站控");
					postexp[i ++] = e;		//将e放到postexp中 
					Pop(Optr,e);			//继续出栈
					//printf("Optr:%c \n",e);
					//printf("O:%d",Optr -> top);
				}
				exp ++;						//继续扫描其他字符 
				break;
			case'+':
			case'-':
				while(!StackEmpty(Optr))	//栈不空循环 
				{
					//printf("+-");
					GetTop(Optr,e);			//取栈顶元素e 
					if (e!='(')				//e不是'(' 
					{
						postexp[i ++] = e;	//将e放入postexp 
						Pop(Optr,e);		//出栈元素e 
						//printf("+-法%c",e);
					}
					else					//e是'('时循环 
						break;
				}
				Push(Optr,*exp);			//将+或-号进栈 
				exp++;
				break;
			case'*':
			case'/':
				while (!StackEmpty(Optr))	//栈不为空进行循环 
				{
					GetTop(Optr,e);			//取栈顶元素 
					if (e == '*' || e == '/')//将栈顶*或/取出栈并存放到postexp中 
					{
						postexp[i ++] = e;	//将e存放到postexp中 
						Pop(Optr,e);		//出栈元素e 
					}
					else
						break;
				} 
				Push(Optr, * exp);			//将元素*或/进栈 
				exp ++;						//继续扫描后续元素 
				break;
			default:						//处理数字字符 
				while ( * exp >= '0' && * exp <= '9')	//判定为数字字符 
				{
					printf("shu\n");				
					postexp[i ++] = *exp; 
					exp ++;			
				}
				postexp[i ++] = '#';					//用#标识一个数字串的结束 
		}
	}
	printf("站控");
	while (!StackEmpty(Optr))							//此时exp扫描完毕，栈不空时循环 
	{
		
		Pop(Optr,e);									//出栈元素e 
		postexp[i ++] = e;								//将e存放到postexp中 
	}
	postexp[i] = '\0';									//给postexp表达式添加结束标识 
	DestroyStack(Optr);									//销毁栈 
}
int main()
{
	char exp[] = "(56-20)/(4+2)";
	//char exp[] = "()";
	char postexp[MaxSize];
	//scanf("%s",exp);
	trans(exp,postexp);
	printf("后缀表达式：%s\n",postexp);
	return 0;
}
