// 2) accept string and display reverse.
#include<stdio.h>
#define MAX 5
#include<process.h>

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
	s.a[s.top]=c;
	}
}

void display()
{
	int i;
	for(i=s.top;i>=0;i--)
	{
		printf("%c \n",s.a[i]);
	}
}	

int main()
{
	int i;
	char s1[20];
	init();
	printf("enter string=");
	gets(s1);
	display();
	for(i=0;s1[i]!='\0';i++)
	{
		push(s1[i]);
	}
	printf("reverse string=");
	display();
}
