#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	char data;
	struct BiTree * lchild,* rchild;
}Tree;

Tree * Create()
{
	char ch;
	Tree * T;
	scanf("%c",&ch);
	if(ch == '#') T = NULL;
	else 
	{
		T = (Tree *)malloc(sizeof(Tree));
		T -> data = ch;
		T -> lchild = Create();
		T -> rchild = Create();
	}
	return T;
}

void InOrder(Tree * T)
{
	if (T != NULL)
	{
		InOrder(T -> lchild);
		printf("%c",T -> data);
		InOrder(T -> rchild);
	}
}
int main()
{
	Tree * T;
	T = Create();
	InOrder(T);
	return 0;
}
