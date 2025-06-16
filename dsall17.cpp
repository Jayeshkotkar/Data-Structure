// singly circular linked list delete beginning //
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
struct node *delete_beg(struct node *head)
{ 
	struct node *temp,*p;
   for(temp=head;temp->next!=head;temp=temp->next);
    p=head;
    head=p->next;
    temp->next=head;
    free(p);
    return head;
}
int main()
{
	struct node *head=NULL;
	head=create(head);
	printf("\n display before delete=");
	display(head);
	head=delete_beg(head);
	printf("\n display after delete=");
	display(head);
	return 0;
}
