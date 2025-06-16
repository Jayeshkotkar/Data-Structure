// bfs 

#include<stdio.h>
#define MAX 5

struct queue
{
	int a[MAX];
	int front,rear;
}q;

void initq()
{
	q.front=q.rear=-1;
}

int isfull()
{
	if(q.rear==MAX-1)
	return 1;
	else
	return 0;
}

int isempty()
{
	if(q.front==-1 || q.front > q.rear)
	return 1;
	else
	return 0;
}

void insertq(int num)
{
	if(q.front==-1)
	{
		q.front=0;
	}
	
	if(isfull())
	{
		printf("queue is overflow");
	}
	else
	{
		q.rear++;
		q.a[q.rear]=num;
	}	
}

int deleteq()
{
	int val;
	if(isempty())
	printf("queue is underflow");
	else
	{
		val=q.a[q.front];
		q.front++;
	}
	return val;
}

void bfs(int g[20][20],int n)
{
	int i,v;
	int visited[20]={0};     // in visited array insert zero.
	initq();
	v=0;
	insertq(v);
	visited[v]=1;
	
	while(!isempty())
	{
		v=deleteq();
		printf("%d\t",v);
		
		for(i=0;i<n;i++)
		{
			if((g[v][i]==1) && (visited[i]==0))   //   visited nasel tr.
			{
				insertq(i);
				visited[i]=1;
			}
		}
	}
}

int main()
{
	int ch,num,i,j,n,g[20][20];
	initq();
	printf("enter no of vertex=");
	scanf("%d",&n);
	printf("enter matrix elements=");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	bfs(g,n);
}


