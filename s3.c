// 3) accept string and check pallindrome or not.
#include<stdio.h>
#define MAX 5

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
		return val;
	}
}

int main()
{
	int i;
	char s1[20];
	printf("enter string=");
	gets(s1);
	init();
	for(i=0;s1[i]!='\0';i++)
	{
		push(s1[i]);
	}
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]!=pop())
		break;
	}
	
	if(isempty())
	printf("string is pallindrome");
	else
	printf("string is not pallindrome");
}
