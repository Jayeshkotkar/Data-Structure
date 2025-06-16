// singly circular delete middle //
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
			newnode->next=head;
		}
	}
	return head;
}
void display(struct node *head)
{
	struct node *temp=head;
	do{
		printf("%d \t",temp->data);
		temp=temp->next;
	  }while(temp!=head);
}
struct node *delete_mid(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	for(i=1,temp=head;i<(pos-1) && temp->next!=head;i++,temp=temp->next);
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
