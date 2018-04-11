#include <stdio.h>
#include <stdlib.h>
#define M 40
typedef struct
{
	int data[M];
	int length;
}Sqlist;

void Create(Sqlist * &L,int a[],int n)
{
	L = (Sqlist *)malloc(sizeof(Sqlist));
	L -> length = 0;
	for (int i = 0;i < n;i ++)
	{
		L -> data[i] = a[i];
	}
}

void Display(Sqlist * & L,int n)
{
	for (int i = 0;i < n;i ++)
	{
		printf("%d ",L->data[i]);
	}
}
int main()
{
	Sqlist * L;
	int n;
	int s[40];
	int p[40];
	scanf("%d",&n);
	for (int i = 0;i < n;i ++)
	{
		scanf("%d",&s[i]);
	}
	int mark = s[0];
	int j,k;
	for (j = n - 1,k = 0;j >= 0;j --)
	{
		if (s[j] < mark) p[k++] = s[j];
	}
	p[k++] = mark;
	for (j = 1;j < n;j ++)
	{
		if (s[j] > mark ) p[k ++] = s[j];
	}
	Create(L,p,n);
	Display(L,n);
	return 0;
}
