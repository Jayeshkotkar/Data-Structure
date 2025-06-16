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
			newnode->next=head;
		}
		else
		{
			temp->next=newnode;
			newnode->next=head;
			temp=newnode;
		}
	}
	return head;
}
void display(struct node *head)
{
	struct node *temp;
	temp=head;
	do{
		printf("%d\t",temp->data);
		temp=temp->next;
	  }while(temp!=head);
}
struct node *insert_common(struct node *head,int num,int pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	if(pos==1)
	{
		for(temp=head;temp->next!=head;temp=temp->next);
		temp->next=newnode;
		newnode->next=head;
		head=newnode;
	}
	else
	{
		for(i=1,temp=head;i<(pos-1) && temp->next!=head;i++,temp=temp->next);
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return head;
}
struct node *delete_common(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	if(pos==1)
	{
		p=head;
		head=head->next;
		free(p);
	}
	else
	{
		for(i=1,temp=head;i<(pos-1) && temp->next!=NULL;i++,temp=temp->next);
		p=temp->next;
		temp->next=p->next;
		free(p);
	}
	return head;
}
int main()
{
	struct node *head=NULL;
	int ch,num,pos;
	do{
	    printf("\n 1:create \n 2:insert_common \n 3:delete_common");
	    printf("\n enter choice=");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		  case 1:head=create(head);
		         display(head);
		         break;
		  case 2:printf("enter value=");
		         scanf("%d",&num);
		         printf("\n enter position=");
		         scanf("%d",&pos);
		         head=insert_common(head,num,pos);
		         display(head);
		         break;
		  case 3:printf("enter position=");
		         scanf("%d",&pos);
		         head=delete_common(head,pos);
		         display(head);
		         break;
	     default:printf("invalid choice.....");
	    }
	}while(ch<4);
	return 0;
}

