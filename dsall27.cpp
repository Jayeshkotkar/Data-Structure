// doubly linked list delete end //
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next,*prev;
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
		newnode->next=NULL;
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
	}
	return head;
}
void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d \t",temp->data);
		temp=temp->next;
	}
}
struct node *delete_end(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next->next!=NULL;temp=temp->next);
	p=temp->next;
	temp->next=NULL;
	free(p);
	return head;
}
int main()
{
	struct node *head=NULL;
	head=create(head);
	printf("\n display before delete=");
	display(head);
	head=delete_end(head);
	printf("\n display after delete=");
	display(head);
	return 0;
}
