// doubly linked list insert moddle //
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
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
struct node *insert_mid(struct node *head,int num,int pos)
{
	int i;
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=head;i<(pos-1) && temp->next!=NULL;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;
	return head;
}
int main()
{
	struct node *head=NULL;
	int num,pos;
	head=create(head);
	printf("\n display before insert=");
	display(head);
	printf("\n enter value=");
	scanf("%d",&num);
	printf("\n enter position=");
	scanf("%d",&pos);
	head=insert_mid(head,num,pos);
	printf("\n display after display=");
	display(head);
	return 0;
}
