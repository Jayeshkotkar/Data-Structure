// 4) accept expression and check is fully parenthesis or not.
#include<stdio.h>
#include<process.h>
# define MAX 5

struct stack
{
	char a[MAX];
	int top;
}s;

void init()
{
	s.top=-1;
}

int isfull()
{
	if(s.top==MAX-1)
	return 1;
	else
	return 0;
}

int isempty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}

void push(char c)
{
	if(isfull())
	{
		printf("stack is full");
	}
	else
	{
		s.top++;
		s.a[s.top]=c;
	}
}

char pop()
{
	char val;
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

int main()
{
	int i;
	char s1[100];
	printf("entre expression=");
	gets(s1);
	init();
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]=='(')
		push(s1[i]);
		
		if(s1[i]==')')
		{
			if(isempty())
			{
				printf("not parenthesis");
				exit(0);
			}
			else
			{
				pop();
			}
		}
	}	
	if(isempty())
	printf("fully parenthesis");
	else
	printf("not fully parenthesis");
}
