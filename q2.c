// 2) circular queue.
#include<stdio.h>
#define MAX 5
struct queue
{
	int a[MAX];
	int front,rear;
}q;

void init()
{
	q.front=q.rear=-1;
}

int isfull()
{
	if((q.front==0 && q.rear==MAX-1) || (q.front==q.rear+1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isempty()
{
	if(q.front==-1)
	return 1;
	else
	return 0;
}

void add(int num)
{
	if(isfull())
	{
		printf("queue is overflow");
	}
	else
	{
		if(q.front==-1)
		{
			q.front=0;
		}
		q.rear=(q.rear+1)%MAX;
		q.a[q.rear]=num;
	}
}

void delete()
{
	int val;
	if(isempty())
	{
		printf("queue is underflow");
	}
	else
	{
		val=q.a[q.front];
		if(q.front==q.rear)
		{
			q.front=q.rear=-1;
		}
		q.front=(q.front+1)%MAX;
	}
}

void display()
{
	int i;
	if(q.front==-1)
	{
		printf("queue is underflow");
	}
	i=q.front-1;
	do
	{
		i=(i+1)%MAX;
		printf("%d\t",q.a[i]);
		
	}while(i!=q.rear);
}

int main()
{
	int ch,num;
	init();
	do
	{
		printf("\n 1:add \n 2:delete \n 3:display");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter num=");
				   scanf("%d",&num);
				   add(num);
				   break;
				   
			case 2:delete();
			 	   break;
			 	   
			case 3:display();
				   break;
		}
	}while(ch<4);
}
