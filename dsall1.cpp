// accept n no & display singly linked list //
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;	
};
 
 struct node* create(struct node *head)
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
 	struct node *temp=head;
 	while(temp!=NULL)
 	{
 		printf("%d \t",temp->data);
 		temp=temp->next;
	 }
 }
 int main()
 {
 	struct node *head=NULL;
 	head=create(head);
 	printf("\n display linklist=");
 	display(head);
 	return 0;
 }
