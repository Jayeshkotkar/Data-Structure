// singly linked list all insert and delete oparation //
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
struct node *insert_beg(struct node *head,int num)
{
	   struct node *newnode;
	   newnode=(struct node*)malloc(sizeof(struct node));
	   newnode->data=num;
	   newnode->next=head;
	   head=newnode;
	   return head;
}
struct node *insert_mid(struct node *head,int num,int pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=head;i<(pos-1) && temp->next->next!=NULL;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}
struct  node *insert_end(struct node *head,int num)
{
	struct node *temp,*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(temp=head;temp->next;temp=temp->next);
    temp->next=newnode;
	newnode->next=NULL;
	return head;	
}
struct node *delete_beg(struct node *head)
{
	struct node *temp,*p;
	p=head;
	head=p->next;
	free(p);
	return head;
}
struct node *delete_mid(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	for(i=1,temp=head;i<(pos-1) && temp->next->next!=NULL;i++,temp=temp->next);
	p=temp->next;
	temp->next=p->next;
	free(p);
	return head;	
}
struct node *delete_end(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next->next;temp=temp->next);
	p=temp->next;
	temp->next=NULL;
	free(p);
	return head;
}
int main()
{
	struct node *head=NULL;
	int num,pos,ch;
	do{
	    printf("\n 1:create \n 2:insert_beg \n 3:insert_mid \n 4:insert_end");
		printf("\n 5:delete_beg \n 6:delete_mid \n 7:delete_end");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
		   case 1:head=create(head);
		          display(head);
		          break;
		   case 2:printf("enter value=");
		          scanf("%d",&num);
		          head=insert_beg(head,num);
		          display(head);
		          break;
		   case 3:printf("enter value=");
		          scanf("%d",&num);
		          printf("\n enter position=");
		          scanf("%d",&pos);
		          head=insert_mid(head,num,pos);
		          display(head);
		          break;
		   case 4:printf("enter value=");
		          scanf("%d",&num);
		          head=insert_end(head,num);
		          display(head);
		          break;
		   case 5:head=delete_beg(head);
		          display(head);
		          break;
		   case 6:printf("enter position=");
		          scanf("%d",&pos);
		          head=delete_mid(head,pos);
		          display(head);
		          break;
		   case 7:head=delete_end(head);
		          display(head);
		          break;
		  default:printf("invalid choice.....");
		}	
	  }while(ch<8);
}
