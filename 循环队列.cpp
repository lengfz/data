#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20
int m;

typedef struct
{
	int data[M];
	int front,rear;
}sq;

void init(sq * &q)
{
	q = (sq * )malloc(sizeof(sq));
	q -> front = 0;
	q -> rear = 0;
	//printf("%d %d ",q->rear,q->front);
}

int enter(sq * &q,int x)
{
	//printf("%d %d\n",(q->rear+1)%m,q->front); 
	if (((q -> rear + 1) % m) == q -> front)
	{
	
		return 0;
	}
	else
	{
		q -> rear = (q -> rear+1)%m;					//rear+1的操作 
		q -> data[q -> rear] = x;						//赋值 
		//printf("x=%d\n",x);
		return 0; 
	}
}

int delect(sq * &q)
{
	if (q -> front == q ->rear)							//尾指向头 
		return 0;
	else
	{
		q -> front = (q -> front + 1) % m;
	}
	return 0;
}
void print(sq * &q)
{  
	//q -> rear = (q -> rear + 1)%m;
	while (q -> front != q -> rear)
	{
		q -> front = (q -> front + 1) % m;
		printf("%d\n",q -> data[q->front]);
		
	}
}
int main()
{
	sq * q;
	char s[4];
	int n,x;
	init(q);
	scanf("%d%d",&m,&n);
	for (int i = 0;i < n;i ++)
	{
		scanf("%s",s);
		if (strcmp(s,"in") == 0)
		{
			scanf("%d",&x);
			enter(q,x); 
		}
		else
		{
			delect(q);
		}
	}
	print(q);
	return 0;
} 
