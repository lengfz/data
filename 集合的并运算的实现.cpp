#include <stdio.h>
#include <stdlib.h>
#define M 40

typedef int Elem;

typedef struct
{
	Elem data[M];
	int length;
}Node;

void Create(Node * &L,int a[],int n)
{
	L = (Node *)malloc(sizeof(Node));
	for (int i = 0;i < n;i ++)
	{
		L -> data[i] = a[i];
		L -> length ++;
	}
}
void p(Node * &L1,Node * &L2,int x,int y)
{
	for (int i = 0;i < y;i ++)
	{
		int mark = 0;
		for (int j = 0;j < x;j ++)
		{
			if (L2 -> data[i] == L1 -> data[j])
			mark++;
		}
		if (!mark) L1 -> data[x++] = L2 -> data[i]; 
	}
	for (int i = 0;i < x;i ++)
	{
		printf("%d ",L1 -> data[i]);
	}
}

int main()
{
	Node *L1,*L2;
	int m1,m2;
	int s1[40],s2[40];
	scanf("%d",&m1);
	for (int i = 0;i < m1;i ++)
	{
		scanf("%d",&s1[i]);
	}
	scanf("%d",&m2);
	for (int i = 0;i < m2;i ++)
	{
		scanf("%d",&s2[i]);
	}
	Create(L1,s1,m1);
	Create(L2,s2,m2);
	p(L1,L2,m1,m2);
	return 0;
}
