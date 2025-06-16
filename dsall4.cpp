// singly linked list insert at middle //
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *create(struct node *head)
{
	struct node *temp,*newnode;
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
struct node *insert_mid(struct node *head,int pos,int num)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	for(i=1,temp=head;i<(pos-1) && temp!=NULL;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;

	return head;
}
int main()
{
	struct node *head;
	head=NULL;
	int num,pos;
	head=create(head);
	printf("\n display before insert=");
	display(head);
	printf("\n enter position=");
	scanf("%d",&pos);
	printf("\n enter value=");
	scanf("%d",&num);
	insert_mid(head,pos,num);
	printf("\n display after insert=");
	display(head);
	return 0;
}
