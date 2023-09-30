#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *create(struct node *head)
{
	struct node *newnode,*temp;
	int i,n;
	printf("enter limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter value=");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return head;
}
void display(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
void sum(struct node *head)
{
	struct node *temp;
	int s=0;
	for(temp=head;temp!=NULL;temp->next)
	{
		s=s+temp->data;
	}
	printf("sum=%d",s);
}
int main()
{
	struct node *head=NULL;
	int s;
	head=create(head);
	display(head);
	sum(head);
	display(head);
	return 0;
}
