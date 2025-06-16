// singly circular insert end //
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
		printf("%d\t",temp->data);
		temp=temp->next;
	  }while(temp!=head);
}
struct node *insert_end(struct node *head,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(temp=head;temp->next!=head;temp=temp->next);
	temp->next=newnode;
	newnode->next=head;
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
	head=insert_end(head,num);
	printf("\n display after insert=");
	display(head);
	return 0;
}
