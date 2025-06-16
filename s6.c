// 6) dynamic stack.
#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *top;

void init()
{
	top=NULL;
}

int isempty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}

void push(int num)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->data=num;
	newnode->next=top;
	top=newnode;
}

void pop()
{
	int val;
	NODE *temp;
	if(isempty())
	{
		printf("stack is empty");
	}
	else
	{
		temp=top;
		val=temp->data;
		top=top->next;
		free(temp);
	}
}

int peek()
{
	return (top->data);
}

void display()
{
	NODE *temp;
	for(temp=top;temp!=NULL;temp=temp->next)
	{
		printf("%d\n",temp->data);
	}
}

int main()
{
	int ch,num;
	init();
	do
	{
		printf("\n 1:push \n 2:pop \n 3:peek \n 4:display");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter num=");
				   scanf("%d",&num);
				   push(num);
				   break;
				   
			case 2:pop();
				   break;
				   
			case 3:printf("topmost element=%d",peek());
				   break;
				   
			case 4:display();
				   break;
		}
	}while(ch<5);
}
