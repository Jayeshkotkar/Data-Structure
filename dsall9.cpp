// singly linked list delete menu driven //
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
	head=head->next;
	p->next=NULL;
	free(p);
	return head;
}
struct node *delete_end(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next->next!=NULL;temp=temp->next);
	p=temp->next;
	temp->next=NULL;
	free(p);
	return head;
}
struct node *delete_mid(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
	p=temp->next;
	temp->next=p->next;
	free(p);
	return head;
}
int main()
{
	struct node *head=NULL;
	int pos,ch;
	do{
	    printf("\n 1:create \n 2:delete_beg");
		printf("\n 3:delete_end \n 4:delete_mid");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
		  case 1:head=create(head);
		         display(head);	
		         break;
		  case 2:head=delete_beg(head);
		        display(head);
		        break;
		  case 3:head=delete_end(head);
		         display(head);
		         break;
		  case 4:printf("enter position=");
		         scanf("%d",&pos);
				 head=delete_mid(head,pos);
				 display(head);
				 break;
		 default:printf("invalid choice.....");       
		}	
      }while(ch<5);
      return 0;
}
