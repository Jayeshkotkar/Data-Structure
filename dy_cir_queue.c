#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int data;
	struct queue *next;
}NODE;

	NODE *front=NULL;
	NODE *rear=NULL;

int isempty()
{
	if(front==NULL || front >= rear)
	return 1;
	else
	return 0;
}

void insert(int num)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=num;
	if(front==NULL)
	{
		front=rear=newnode;
		rear->next=front;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=front;
	}
}

void delete()
{
	if(isempty())
	{
		printf("queue is empty");
	}
	else
	{
		NODE *temp;
	temp=front;
	front=front->next;
	rear->next=front;
	free(temp);
	}
}

int peek()
{
	return (front->data);
}

void display()
{
	NODE *temp=front;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=rear->next);
	
	
}

int main()
{
	int num,ch;
	do
	{
		printf("\n 1:insert \n 2:delete \n 3:display \n 4:peek");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter num=");
				   scanf("%d",&num);
				   insert(num);
				   break;
				   
			case 2:delete();
				   break;
				   
			case 3:display();
				   break;
				   
			case 4:printf("top most element=%d",peek());
				   break;
		}
	}while(ch<5);
}
