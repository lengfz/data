#include <stdio.h>
#include <stdlib.h>

char ch;
void T();
void F();

void E()					//+-
{
	char tmp;
	T();
	while (ch == '+' || ch == '-')		//
	{
		tmp = ch;
		ch = getchar();
		T();
		printf("%c",tmp);
	}
} 

void T()					//*/
{
	char tmp;
	F();
	while (ch == '*' || ch == '/')
	{
		tmp = ch;
		ch = getchar();
		F();
		printf("%c",tmp); 
	}
}

void F()					//()
{
	if (ch == '(')
	{
		ch = getchar();
		E();
		if (ch != ')')	{
			exit(0);
		}
		else ch = getchar();
	}
	else
	{
		printf("%c",ch);
		ch = getchar();
	}
}
int main()
{
	ch = getchar();
	E();
	return 0;
}
