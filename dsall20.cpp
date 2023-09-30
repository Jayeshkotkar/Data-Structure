// singly circular linked list menu driven insert and delete //
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
		printf("%d \t",temp->data);
		temp=temp->next;
	  }while(temp!=head);
}
struct node *insert_beg(struct node *head,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(temp=head;temp->next!=head;temp=temp->next);
	newnode->next=head;
	head=newnode;
	temp->next=head;
	return head;
}
struct node *insert_end(struct node *head,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	for(temp=head;temp->next!=head;temp=temp->next);
	temp->next=newnode;
	temp=newnode;
	temp->next=head;
	return head;
}
struct node *insert_mid(struct node *head,int num,int pos)
{
    struct node *newnode,*temp;
    int i;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    for(i=1,temp=head;i<(pos-1) && temp->next!=head;i++,temp=temp->next);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node *delete_beg(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next!=head;temp=temp->next);
	p=head;
	head=head->next;
	temp->next=head;
	free(p);
	return head;
}
struct node *delete_end(struct node *head)
{
	struct node *p,*temp;
	for(temp=head;temp->next->next!=head;temp=temp->next);
	p=temp->next;
	temp->next=head;
	free(p);
	return head;
}
struct node *delete_mid(struct node *head,int pos)
{
	struct node *p,*temp;
	int i;
	for(i=1,temp=head;i<(pos-1) && temp->next!=head;i++,temp=temp->next);
	temp->next=p->next;
	free(p);
	return head;
}
int main()
{
	struct node *head=NULL;
		int num,pos,ch;
		do{
			printf("\n 1:create \n 2:insert_beg \n 3:insert_end \n 4:insert_mid");
			printf("\n 5:delete_beg \n 6:delete_end \n 7:delete_mid");
			printf("\n enter choice=");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:head=create(head);
				       display(head);
					   break;
			    case 2:printf("enter value=");
				       scanf("%de",&num);
					   head=insert_beg(head,num);
					   display(head);
					   break;
				case 3:printf("enter value=");
				       scanf("%d",&num);
					   head=insert_end(head,num);
					   display(head);
					   break;
				case 4:printf("enter value=");
				       scanf("%d",&num);
					   printf("\n enter position=");
					   scanf("%d",&pos);
					   head=insert_mid(head,num,pos);
					   display(head);
					   break;
				case 5:head=delete_beg(head);
				       display(head);
					   break;
				case 6:head=delete_end(head);
				       display(head);
					   break;
                case 7:printf("\n enter position=");
					   scanf("%d",&pos);
					   head=delete_mid(head,pos);
					   display(head);
					   break;
			   default:printf("invalid choice....."); 
			}
		}while(ch<8);
		return 0;
}
