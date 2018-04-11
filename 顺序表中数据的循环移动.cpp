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

int main()
{
	int m,s[40],k;
	Sqlist * L;
	int mark;									//用于标记每个数组的第一个元素 
	scanf("%d",&m);
	for (int i = 0;i < m;i ++)
	{
		scanf("%d",&s[i]);
	}
	scanf("%d",&k);
	if (k > m) printf("error!");
	else
	{
		for (int i = 0;i < k;i ++)
		{
			int j;
			mark = s[0];
			for (j = 1;j < m;j ++)
			{
				s[j - 1] = s[j];
			}
			s[j  - 1] = mark;
		} 
		Create(L,s,m);
		for (int i = 0;i < m;i ++)
		{
			printf("%d ",L -> data[i]);
		}
	}
	
	return 0;
}
