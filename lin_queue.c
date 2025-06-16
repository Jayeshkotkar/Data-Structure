#include<stdio.h>
#define MAX 5

struct queue
{
	int a[MAX];
	int front,rear;
}q;

void init()
{
	q.front=-1;
	q.rear=-1;
}

int isempty()
{
	if(q.front==-1 || q.front > q.rear)
	return 1;
	else
	return 0;
}

int isfull()
{
	if(q.rear==MAX-1)
	return 1;
	else
	return 0;
}

void insert(int num)
{
	if(q.front==-1)
		q.front=0;
		
	if(isfull())
		{
			printf("queue is full");
		}
	else
	{
		q.rear++;
		q.a[q.rear]=num;
		
	}
}

void delete()
{
	int val;
	if(isempty())
	{
		printf("queue is empty");
	}
	else
	{
		val=q.a[q.front];
		q.front++;
	}
}

void reverse()
{
	int i;
	for(i=q.rear;i>=0;i--)
	{
		printf("%d\t",q.a[i]);
	}
}

int peek()
{
	return (q.a[q.front]);
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
	init();
	int ch,num;
	do
	{
		printf("\n 1:insert \n 2:display \n 3:delete \n 4:reverse \n 5:peek");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter num=");
				   scanf("%d",&num);
				   insert(num);
				   break;
			
			case 2:display(num);
				   break;
				   
			case 3:delete();
				   break;
				   
			case 4:reverse();
				   break;
				   
			case 5:printf("top most element=%d",peek());
				   break;
		}
	}while(ch<6);
}
