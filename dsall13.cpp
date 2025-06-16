// display singly circular linked list //
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *create(struct node *head)
{
	int i,n;
	struct node *newnode,*temp;
	printf("enter limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter value=");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=temp=newnode;
			newnode->next=head;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
			temp->next=head;
		}
	}
	return head;
}
void display(struct node *head)
{
	struct node *temp=head;
	do{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
int main()
{
	struct node *head=NULL;
	head=create(head);
	display(head);
	return 0;
}
