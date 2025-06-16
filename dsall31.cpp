// merge two linked list.
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
	struct node *temp,*newnode;
	printf("\n Enter limit of first linked list=");
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
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
void display2(struct node *head2)
{
	struct node *temp;
	for(temp=head2;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
struct node *create2(struct node *head2)
{
	int i,n;
	struct node *temp,*newnode;
	printf("\n Enter limit of second linked list=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter value=");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head2==NULL)
		{
			head2=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return head2;
}
struct node *merge(struct node *head,struct node *head2)
{
	struct node *temp;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=head2;
	return head;
}
int main()
{
	struct node *head=NULL;
	struct node *head2=NULL;;
	head=create(head);
	printf("\n first linked list=");
	display(head);
	head2=create(head2);
	printf("\n second linked list=");
	display2(head2);
	printf("\n merge linked list=");
	head=merge(head,head2);
	display(head);
}
