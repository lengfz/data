#include <stdio.h>
#include <stdlib.h>
#define Max 40

bool b = false;
typedef int Elem;
typedef struct
{
	Elem data[Max];
	int length;
}SqlList;

void Create(SqlList * &L,int a[],int n)
{
	L = (SqlList *)malloc(sizeof(SqlList));
	for (int i = 0;i < n;i ++)
	{
		L -> data[i] = a[i];
		L -> length ++;
	}
}
void bo(SqlList * &L,int s,int m)
{
	for (int i = m - 1;i >= 0;i --)
	{
		int all = 0;
		for (int j = i;j >= 0;j --)
		{
			if (all + L -> data[j] <= s) all += L -> data[j];
			if (all == s) b = true;
		}
	}	
}
int main()
{
	int a[40];
	SqlList * L;
	void Create(SqlList * &L,int a[],int n);
	void bo(SqlList * &L,int s,int m);
	int s;
	int m;
	scanf("%d%d",&s,&m);
	for (int i = 0;i < m;i ++)
	{
		scanf("%d",&a[i]);
	}
	Create(L,a,m);
	bo(L,s,m);
	if (b) printf("yes!");
	else printf("no!");
	return 0;
}
