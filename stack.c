#include<stdio.h>
#define MAX 5

struct stack
{
	int top;
	int a[MAX];
}s,s2;                      // here s2 is use in copy function.

void init()
{
  s.top=-1;	
}

int isempty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}

int isfull()
{
	if(s.top==MAX-1)
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
		s.top++;
		s.a[s.top]=num;
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
		val=s.a[s.top];
		s.top--;
	}
}	

void display()
{
	int i;
	for(i=s.top;i>=0;i--)
	{
		printf("%d\n",s.a[i]);
	}
}

void copy()
{
	int i;
	s2.top=-1;
	for(i=0;i<=s.top;i++)
	{
		s2.top++;
		s2.a[s2.top]=s.a[i];
	}
}

void dispcopy()
{
	int i;
	for(i=s2.top;i>=0;i--)
	{
		printf("%d\n",s2.a[i]);
	}
}

void check_identical(struct stack s,struct stack s2)
{
	int f=0,i;
	for(i=0;i<s.top;i++)
	{
		if(s.a[i]!=s2.a[i])
		f=1;
	}
	
	if(f==0)
	printf("identical");
	else
	printf("not identical");
}


void reverse()
{
	int i;
	for(i=0;i<=s.top;i++)
	{
		printf("%d\n",s.a[i]);
	}
}

int main()
{
	init();
	int ch,num;
	do
	{
		printf("\n 1:push \n 2:pop \n 3:display \n 4:disp copy \n 5:check_identical \n 6:reverse");
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
				   
			case 4:printf("display copy stack \n");
				   copy();
				   dispcopy();
				   break;
				   
			case 5:check_identical(s,s2);
				   break;
				   
			case 6:reverse();
				   break;
		}
	}while(ch<7);
}
