#include<stdio.h>
#define MAX 5

struct stack
{
	int top;
	int a[MAX-1];
}*s;

void init()
{
  s->top=-1;	
}

int isempty()
{
	if(s->top==-1)
	return 1;
	else
	return 0;
}

int isfull()
{
	if(s->top==MAX-1)
	return 1;
	else
	return 0;
}

void push(int num)
{
	if(isfull())
	{
		printf("stack is full");
	}
	else
	{
		if(s->top==-1)
		{
			s->top=0;
		}
		s->a[s->top]=num;
		s->top++;
	}
}

void pop()
{
	int val;
	if(isempty())
	{
		printf("stack is empty");
	}
	else
	{
		val=s->a[s->top];
		s->top--;
	}
}	

void display()
{
	int i;
	for(i=s->top;i>=0;i--)
	{
		printf("%d\n",s->a[s->top]);
	}
}

int main()
{
	int ch,num;
	do
	{
		printf("\n 1:push \n 2:pop \n 3:display");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter number=");
				   scanf("%d",&num);
				   push(num);
				   break;
				   
			case 2:pop();
				   break;
			
			case 3:display();
				   break;
		}
	}while(ch<4);
}
