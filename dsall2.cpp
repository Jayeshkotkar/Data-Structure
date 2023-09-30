// singly linked list insert at beginning //
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
	struct node *temp,*newnode;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
		
	}
}

struct node *insert_beg(struct node *head,int num)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=head;
	head=newnode;
	return head;
}
int main()
{
	struct node *head=NULL;
	int num;
	head=create(head);
	printf("\n display before insert=");
	display(head);
	printf("\n enter value=");
	scanf("%d",&num);
	 head=insert_beg(head,num);
	 printf("\n display after insert=");
	 display(head);
	 return 0;
}
