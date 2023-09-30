// singly linked list delete beginning //
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
	scanf("%D",&n);
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
struct node *delete_beg(struct node *head)
{
	struct node *p;
	p=head;
	head=p->next;
	free(p);
	return head;
}
int main()
{
	struct node *head=NULL;
	head=create(head);
	printf("\n display linked list before delete=");
	display(head);
	head=delete_beg(head);
	printf("\n display linked list after delete=");
	display(head);
	return 0;
}
