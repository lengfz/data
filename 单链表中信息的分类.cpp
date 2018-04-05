#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elem;
typedef struct LNode
{
	Elem data;
	struct LNode * next;
}LinkNode;

void Creat(LinkNode * &L,char a[],int n)
{
	L = (LinkNode *)malloc(sizeof(LinkNode));
	LinkNode *q,*r;
	r = L;
	for (int i = 0;i <= n;i ++)
	{
		q = (LinkNode *)malloc(sizeof(LinkNode));
		q -> data = a[i];
		r -> next = q;
		r = q;
	}
	r -> next =NULL; 	
}

void Display(LinkNode * &L)
{
	LinkNode *q;
	q = L -> next;
	while(q -> next != NULL)
	{
		printf("%c",q -> data);
		q = q->next;
	}
	printf("\n"); 
}

int main()
{
	char s[30];
	LinkNode * L1,*L2,*L3;
	char p1[30],p2[30],p3[30];
	int j = 0,k = 0,l = 0;
	int len;
	scanf("%s",s);
	len = strlen(s);
	for (int i = 0;i < len;i ++)
	{
		if (s[i] >= '0' and s[i] <= '9')
		p1[j++] = s[i];
		else if (s[i] >= 'a' and s[i] <= 'z') 
		p2[k++] = s[i];
		else
		p3[l++] = s[i];
	}
	Creat(L1,p1,j);
	Creat(L2,p2,k);
	Creat(L3,p3,l); 
	Display(L1);
	Display(L2);
	Display(L3);
	return 0;
}
