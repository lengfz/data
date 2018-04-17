#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	char data;
	struct BiTree * lchild,* rchild;
}Tree;

Tree * Create()
{
	Tree * T;
	char ch;
	scanf("%c",&ch);
	if (ch == '#') T = NULL;
	else
	{
		T = (Tree *)malloc(sizeof(Tree));
		T -> data = ch;
		T -> lchild = Create();
		T -> rchild = Create(); 
	}
	return T;
}

void PostOrder(Tree * &T)
{
	if (T != NULL)
	{
		PostOrder(T -> lchild);
		PostOrder(T -> rchild);
		printf("%c",T -> data);
	}
}

int main()
{
	Tree * T;
	T = Create();
	PostOrder(T);
	return 0;
}
