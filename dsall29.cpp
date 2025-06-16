#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *next,*prev;
	int data;
};
struct node *create(struct node *head)
{
	struct node *temp,*newnode;
	int i,n;
	printf("enter limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter data=");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=temp=newnode;
			newnode->next=head;
			head->prev=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
			temp->next=head;
			head->prev=temp;
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
struct node* insert_common(struct node *head,int num,int pos)
{
	struct node *temp,*newnode;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	if(pos==1)
	{
      for(temp=head;temp!=head;temp=temp->next);
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
      temp->next=head;
      head->prev=temp;	
	}
	else
	{
		for(i=1,temp=head;i<(pos-1) && temp!=head;i++,temp=temp->next);
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
	}
    return head;
}
struct node* delete_common(struct node *head,int pos)
{
	struct node *temp,*p;
	int i;
	if(pos==1)
	{
		for(temp=head;temp->next!=head;temp=temp->next);
		p=head;
		head=p->next;
		temp->next=head;
		head->prev=temp;
		free(p);
	}
	else
	{
		for(i=1,temp=head;i<(pos-1) && temp!=head;i++,temp=temp->next);
		p=temp->next;
		temp->next=p->next;
		p->next->prev=temp;
		free(p);
	}
	return head;
}
int main()
{
	struct node *head=NULL;
	int ch,num,pos;
	do{
		printf("\n 1:create \n 2:insert \n 3:delete");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
	     case 1:head=create(head);
	            display(head);
	            break;
	     
		 case 2:printf("enter num=");
		        scanf("%d",&num);
		        printf("enter position=");
		        scanf("%d",&pos);
		        insert_common(head,num,pos);
                display(head);
	            break;
		 case 3:printf("enter posotion=");
		         scanf("%d",&pos);
		         delete_common(head,pos);
		         display(head);
		         break;
	    }
    }while(ch<4);
}
