// 4) circular dynamic queue.
#include<stdio.h>
#include<Stdlib.h>
typedef struct node 
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

void insertq(int num)
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
		rear->next=front;
		free(temp);
	}
}

int peek()
{
	return (front->data);
}

display()
{
	NODE *temp=front;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=front);
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
				   
			case 3:printf("topmost element=%d",peek());
				   break;
				   
			case 4:display();
				   break;	
		}
	}while(ch<5);
}
