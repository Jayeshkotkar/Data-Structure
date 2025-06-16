// reverse singly linked list
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
		printf("enter data=");
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
struct node *reverse(struct node *head)
{
	struct node *p1,*p2,*p3;
	if(head->next==NULL)
	{
		return head;
	}
	p1=head;
	p2=p1->next;
	p3=p2->next;
	
	p1->next=NULL;
	p2->next=p1;
	
	while(p3!=NULL)
	{
		p1=p2;
		p2=p3;
		p3=p3->next;
		p2->next=p1;
	}
	head=p2;
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
int main()
{
	struct node *head=NULL;
	head=create(head);
	printf("\n linked list=");
	display(head);
	reverse(head);
	printf("\n reverse linked list=");
	display(head);
	
}
