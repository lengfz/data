#include <stdio.h>
#include <malloc.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree()
{
	char ch;
	BiTree T;
	scanf("%c",&ch);
	if (ch == '#') T = NULL;
	else 
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T -> data = ch;
		T -> lchild = CreateBiTree();
		T -> rchild = CreateBiTree();
	}
	return T;
}
int count = 0;
void Leaf(BiTree T)
{
	if (T != NULL)
	{
		if (T -> lchild == NULL && T -> rchild == NULL)
		{
			count ++;
		}
		Leaf(T -> lchild);
		Leaf(T -> rchild);
	}
}
int main()
{
	BiTree T;
	T = CreateBiTree();
	Leaf(T);
	int t;
	t = count;
	printf("%d",t);
	return 0; 
}
