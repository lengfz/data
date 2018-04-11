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
		L -> length ++;
	}
}

void ban(Sqlist * &L1,Sqlist * &L2,int n)
{
	if (L1 -> length > L2 -> length)
	{
		for (int i = L2 -> length,k = 0;i < 2 * L2 -> length;i ++,k ++)
		{
			L2 -> data[i] = L2 -> data[k];
		}
	}
	if (L2 -> length > L1 -> length)
	{
		for (int i = L1 -> length,k = 0;i < 2 * L1 -> length;i ++,k ++)
		{
			L1 -> data[i] = L1 -> data[k];
		}
	}
	printf("%c %c",L1 -> data[n - 1],L2 -> data[n - 1]);
} 

int main()
{
	int q1,q2,m;
	Sqlist * L1,*L2;
	int w1[40],w2[40];
	scanf("%d",&q1);
	for (int i = 0;i < q1;i ++)
	{
		scanf("%s",&w1[i]);
	}
	//printf("%c %c %c",w1[0],w1[1],w1[2]);
	scanf("%d",&q2);
	for (int i = 0;i < q2;i ++)
	{
		scanf("%s",&w2[i]);
	}
	scanf("%d",&m); 
	Create(L1,w1,q1);
	Create(L2,w2,q2);
	ban(L1,L2,m);
	return 0;
}
