// 5) evaluate the expression using stack
#include<stdio.h>
#define MAX 50
struct stack                  // expression: A*B$C+D*E/F.
{
	int a[MAX];
	int top;
}s1;
void init()
{
	s1.top=-1;
}
int isempty()
{
	if(s1.top==-1)
	return 1;
	else 
	return 0;
}
int isfull()
{
	if(s1.top==MAX-1)
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
		s1.top++;
		s1.a[s1.top]=num;
	}
}
int pop()
{
	int v;
	if(isempty())
	{
		printf("stack is empty");
	}
	else
	{
    	v=s1.a[s1.top];
	    s1.top--;
     	return v;
   }
}
int main()
{
	char postfix[20];
	int a,b,c,d,val1,val2,result,i;
	printf("enter expression=");
	gets(postfix);
	printf("enter value of a,b,c,d=");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=0;postfix[i]!='\0';i++)
	{
		if(postfix[i]=='a')
		   push(a);
		else if(postfix[i]=='b')
		   push(b);
		   else if(postfix[i]=='c') 
		   push(c);
		   else if(postfix[i]=='d')
		   push(d);
		   else
		   {
		   	val1=pop();
		   	val2=pop();
		   	if(postfix[i]=='+')
		   	result=val2+val1;
		   	if(postfix[i]=='-')
		   	result=val2-val1;
		   	if(postfix[i]=='*')
		   	result=val2*val1;
		   	if(postfix[i]=='/')
		   	result=val2/val1;
		   	push(result);
		   }
	}
	printf("result=%d",pop());
}
