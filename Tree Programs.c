//2) create tree and perform search and insert operations.
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left,*right;
};

struct node *create(struct node *root)
{
	int  i,n;
	struct node *newnode,*temp,*parent;
	printf("enter limit=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter value=");
		scanf("%d",&newnode->data);
		newnode->left=newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			temp=root;
			while(temp!=NULL)      // it is use to find parent node.
			{
				parent=temp;
				if(newnode->data < temp->data)
				{
					temp=temp->left;
				}
				else
				{
					temp=temp->right;
				}
			}
			
			if(newnode->data < parent->data)
			{
				parent->left=newnode;
			}
			else
			{
				parent->right=newnode;
			}
		}
	}
	return root;
}

struct node *search(struct node *root,int val)    // recursive function
{
	struct node *temp=root;
	if(root==NULL)
	return NULL;
	
	if(val==temp->data)
	return temp;
	
	if(val >= temp->data)
	search(temp->right,val);
	else
	search(temp->left,val);
}

struct node *insert(struct node *root,int val)    // recursive function
{
	struct node *newnode,*temp=root;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->left=newnode->right=NULL;
	if(root==NULL)
	{
		return newnode;
	}
	
	if(val < temp->data)
	{
		temp->left=insert(temp->left,val);
	}
	else
	{
		temp->right=insert(temp->right,val);
	}
	
	return root;
}

void inorder(struct node *root)
{
	int c1=0,c2=0;
	struct node *temp=root;
	if(temp!=NULL)
	{
		if((root->data)%2==0)
		{
			c1++;
		}
		else
		{
			c2++;
		}
		inorder(temp->left);
		inorder(temp->right);
	}
	printf("\n even=%d",c1);
	printf("\n odd=%d",c2);
}

int main()
{
	int ch,val;
	struct node *root=NULL,*temp;
	do
	{
		printf("\n 1:create \n 2:display \n 3:search \n 4:insert");
		printf("\n enter choice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
				   break;
				   
			case 2:printf("\n display inorder=");
				   inorder(root);
				   break;
				   
			case 3:printf("enter value=");
				   scanf("%d",&val);
				   temp=search(root,val);
				   if(temp!=NULL)
				   printf("found");
				   else
				   printf("not found");
				   break;
			
			case 4:printf("enter value=");
				   scanf("%d",&val);
				   root=insert(root,val);
				   break;	    
		}
	}while(ch<5);
}
