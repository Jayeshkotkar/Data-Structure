// singly and circular menu driven all insert an delete //
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *creates(struct node *head)
{
	int i,n;
	struct node *newnode,*temp;
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
struct node *createc(struct node *head)
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
void displays(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d \t",temp->data);
		temp=temp->next;
	}
}
void displayc(struct node *head)
{
	struct node *temp=head;
	do{
		printf("%d \t",temp->data);
		temp=temp->next;
	  }while(temp!=head);
}
struct node *insert_begs(struct node *head,int num)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=head;
	head=newnode;
	return head;
}
struct node *insert_ends(struct node *head,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	newnode->next=NULL;
	return head;
}
struct node *insert_mids(struct node *head,int num,int pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=head;i<(pos-1) && temp->next!=NULL;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}
struct node *delete_begs(struct node *head)
{
	struct node *p;
	p=head;
	head=head->next;
	free(p);
	return head;
}
struct node *delete_ends(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next->next!=NULL;temp=temp->next);
	p=temp->next;
	temp->next=NULL;
	free(p);
	return head;
}
struct node *delete_mids(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	for(i=1,temp=head;i<(pos-1) && temp->next->next!=NULL;i++,temp=temp->next);
     p=temp->next;
     temp->next=p->next;
     free(p);
     return head;
}
struct node *insert_begc(struct node *head,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(temp=head;temp->next!=head;temp=temp->next);
	temp->next=newnode;
	newnode->next=head;
	head=newnode;
	return head;
}
struct node *insert_endc(struct node *head,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(temp=head;temp->next!=head;temp=temp->next);
	temp->next=newnode;
	newnode->next=head;
	return head;
}
struct node *insert_midc(struct node *head,int num,int pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=head;i<(pos-1) && temp->next->next!=head;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}
struct node *delete_begc(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next!=head;temp=temp->next);
	p=head;
	head=head->next;
	temp->next=head;
	free(p);
	return head;
}
struct node *delete_endc(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next->next!=head;temp=temp->next);
	p=temp->next;
	temp->next=head;
	free(p);
	return head;
}
struct node *delete_midc(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	for(i=1,temp=head;i<(pos-1) && temp->next->next!=head;temp=temp->next);
	p=temp->next;
	temp->next=p->next;
	free(p);
	return head;
}
int main()
{
	struct node *head=NULL;
	int ch,num,pos;
	do{
		printf("\n singly \n");
		printf("\n 1:create \n 2:insert_beg \n 3:insert_end \n 4:insert_mid");
		printf("\n 5:delete_beg \n 6:delete_end \n 7:delete_mid \n");
		printf("\n circular \n");
		printf("\n 8:create \n 9:insert_beg \n 10:insert_end \n 11:insert_mid");
		printf("\n 12:delete_beg \n 13:delete_end \n 14:delete_mid \n");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head=creates(head);
			       displays(head);
			       break;
			case 2:printf("enter value=");
			       scanf("%d",&num);
			       head=insert_begs(head,num);
			       displays(head);
			       break;
			case 3:printf("enter value=");
			       scanf("%d",&num);
			       head=insert_ends(head,num);
			       displays(head);
			       break;
			case 4:printf("enter value=");
			       scanf("%d",&num);
			       printf("\n enter position=");
			       scanf("%d",&pos);
			       head=insert_mids(head,num,pos);
			       displays(head);
			       break;
			case 5:head=delete_begs(head);
			       displays(head);
			       break;
			case 6:head=delete_ends(head);
			       displays(head);
			       break;
			case 7:printf("enter position=");
			       scanf("%d",&pos);
			       head=delete_mids(head,pos);
			       displays(head);
			       break;
			case 8:head=createc(head);
			       displayc(head);
			       break;
			case 9:printf("enter value=");
			       scanf("%d",&num);
			       head=insert_begc(head,num);
			       displayc(head);
			       break;
		   case 10:printf("enter value=");
		           scanf("%d",&num);
		           head=insert_endc(head,num);
		           displayc(head);
		           break;
		   case 11:printf("enter value=");
		           scanf("%d",&num);
		           printf("\n enter position=");
		           scanf("%d",&pos);
		           head=insert_midc(head,num,pos);
		           displayc(head);
		           break;
		   case 12:head=delete_begc(head);
		           displayc(head);
		           break;
		   case 13:head=delete_endc(head);
		           displayc(head);
		           break;
		   case 14:printf("enter position=");
		           scanf("%d",&pos);
		           head=delete_midc(head,pos);
		           displayc(head);
		           break;
		           
		   default:printf("invalid choice.....");
		}
		
      }while(ch<15);
      return 0;
}

