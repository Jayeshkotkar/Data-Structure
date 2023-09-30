// singly linked list delete middle //
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
struct node *delete_mid(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	for(i=1,temp=head;i<(pos-1) && temp!=NULL;i++,temp=temp->next);
	p=temp->next;
	temp->next=p->next;
	free(p);
	return head;
}
int main()
{
	struct node *head=NULL;
	int pos;
	head=create(head);
	printf("\n display before delete=");
	display(head);
	printf("\n enter position=");
	scanf("%d",&pos);
	head=delete_mid(head,pos);
	printf("\n display after delete=");
	display(head);
	return 0;
}
