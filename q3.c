// 3) linear dynamic queue.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE* front=NULL;
NODE* rear=NULL;

int isempty()
{
	if(front==NULL)
	return 1;
	else
	return 0;
}

void insertq(int num)
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

void deleteq()
{
	NODE *temp;
	if(isempty())
	{
		printf("queue is underflow");
	}
	else
	{
		temp=front;
		front=front->next;
		free(temp);
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
		printf("\n 1:insert \n 2:delete \n 3:peek \n 4:display");
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
				   
			case 3:printf("top most element=%d",peek());
				   break;
				   
			case 4:display();
				   break;
		}
	}while(ch<5);
}
