// singly circular insert middle //
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
	printf("emter limit=");
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
			newnode->next=head;
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
struct node *insert_mid(struct node *head,int num,int pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=head;i<(pos-1) && temp->next!=head;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
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
	printf("\n display after insert=");
	display(head);
	return 0;
}
