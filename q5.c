// 5) priority queue.
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
	int i;
	if(isfull())
	{
		printf("queue is underflow");
	}
	else
	{
		if(q.front==-1)
		{
			q.front=0;
		}
		for(i=q.rear;i>=q.front;i--)
		{
			if(num > q.a[i])
			{
				q.a[i+1]=q.a[i];
			}
			else
			{
				break;
			}
		}
		q.a[i+1]=num;
		q.rear++;
	}
}

void deleteq()
{
	int val;
	if(isempty())
	{
		printf("queue is underflow");
	}
	else
	{
		val=q.a[q.front];
		q.front++;
	}
}

void display()
{
	int i;
	for(i=q.front;i<=q.rear;i++)
	{
		printf("%d\t",q.a[i]);
	}
}

int main()
{
	int ch,num;
	init();
	do
	{
		printf("\n 1:insert \n 2:delete \n 3:display");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter num=");
				   scanf("%d",&num);
				   insertq(num);
				   break;
				   
			case 2:deleteq();
				   break;
				
			case 3:display();
				   break;
		}
	}while(ch<4);
}
