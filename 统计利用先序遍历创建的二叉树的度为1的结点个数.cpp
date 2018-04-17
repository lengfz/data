#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	char data;
	struct BiTree *lchild,*rchild;
}Tree;

BiTree * Create()
{
	char ch;
	Tree * T;
	scanf("%c",&ch);
	if (ch == '#')	T = NULL;
	else 
	{
		T = (Tree *)malloc(sizeof(Tree));
		T -> data = ch;
		T -> lchild = Create();
		T -> rchild = Create();
	}
	return T; 
}
int s = 0;
int num(BiTree * T)
{
	if (T != NULL)
	{
		if ((T -> lchild != NULL && T -> rchild == NULL) ||(T -> rchild != NULL && T -> lchild == NULL))
			{
				s ++;
			}
		num(T->lchild);
		num(T->rchild);
		return s;
	}
}

int main()
{
	Tree * T;
	T = Create();
	int t;
	t = num(T);
	printf("%d",t);
	return 0;
}
