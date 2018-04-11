#include <stdlib.h>
#include <stdio.h>
#define M 100

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
		L -> length ++;
	}
	
}

void Delect(Sqlist * &L,int n,int m)
{
	int i;
	for (i = 0;i < L -> length;i ++)
	{
		if (L -> data[i] <= m && L -> data[i] >= n)
		{
			for (int j = i;j < L -> length - 1;j ++)
			{
				L -> data[j] = L->data[j + 1];
			}
			L -> length --;
			i --;										//在对i位置进行判断，避免两个都符合要求的数据，因为第一个数据删除而遗漏。 
		}
			
	}
	for (int i = 0;i < L -> length;i ++)
	{
		printf("%d ",L -> data[i]);
	}
}

int main()
{
	int b,m,n;
	int s[100];
	Sqlist * L;
	scanf("%d",&b);
	for (int i = 0;i < b;i ++)
	{
		scanf("%d",&s[i]);
	}
	scanf("%d %d",&n,&m);
	Create(L,s,b);
	Delect(L,n,m);
	return 0;
}
