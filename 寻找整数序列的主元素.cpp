#include <stdio.h>
#include <stdlib.h>
bool b = true;
/*#define M 40

typedef int Elem;
typedef struct
{
	Elem data[M];
	int length;
}Node;

void Create(Node * &L,int a[],int n)
{
	
}*/
int main()
{
	int m;
	int *s;
	scanf("%d",&m);
	s = (int *)malloc(sizeof(int)*m);
	for (int i = 0;i < m;i ++)
	scanf("%d",&s[i]);
	for (int i = 0;i < m/2;i ++)
	{
		int l = 0;
		for (int j = 0;j < m;j ++)
		{
			if (s[i] == s[j]) l ++;
			if (l > m / 2) 
			{
				printf("%d",s[i]);
				b = false;
				break;
			}
			if (!b) break;
		}
	}
	if (b) printf("-1");
	return 0;
}
