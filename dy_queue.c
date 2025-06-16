#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
	int data;
	struct node *next;
}NODE;

NODE *front=NULL;
NODE *rear=NULL;

int isempty()
{
	if(front==NULL)
	return 1;
	else
	return 0;
}

void insert(int num)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=num;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
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
		val=front->data;
		front=front->next;
	}
}

int peek()
{
	return (front->data);
}

void display()
{
	NODE *temp;
	for(temp=front;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}

int main()
{
	int ch,num;
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
