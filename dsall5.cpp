// singly linked list insert menu driven //
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
struct node *insert_beg(struct node *head,int num)
{
	struct node *temp,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	newnode->next=head;
	head=newnode;
	return head;
}
struct node *insert_end(struct node *head,int num)
{
	struct node *temp,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	temp=newnode;
	return head;
}
struct node *insert_mid(struct node *head,int num,int pos)
{
	struct node *temp,*newnode;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=head;1<(pos-1) && temp!=NULL;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}
int main()
{
	int ch,num,pos;
	struct node *head=NULL;
	do{
		printf("\n 1:create \n 2:display \n 3:insert_beg");
		printf("\n 4:insert_end \n 5:insert_mid");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
	       case 1:head=create(head);
	              break;
	       case 2:display(head);
		          break;      
	       case 3:printf("enter value=");
	              scanf("%d",&num);
		          head=insert_beg(head,num);
		          break;       
	       case 4:printf("enter value=");
	              scanf("%d",&num);
		          head=insert_end(head,num);
			      break; 
		   case 5:printf("enter value=");
		          scanf("%d",&num);
				  printf("enter position=");
				  scanf("%d",&pos);
				  head=insert_mid(head,num,pos);
				  break;
		   default:printf("invalid choice.....");
		}     
	}while(ch<6);
}

