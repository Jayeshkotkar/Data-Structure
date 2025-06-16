//3) create tree and delete node.
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

struct node *deletebst(struct node *root,int val)
{
	struct node *temp;
	if(root==NULL)
	return root;
	
	if(val < root->data)
	{
		root->left=deletebst(root->left,val);
	}
	else if(val > root->data)
	{
		root->right=deletebst(root->right,val);
	}
	else if(val==root->data)
	{
		if(root->left==NULL)   // for one child
		{
			temp=root->right;
			free(root);
			return temp;
		}
		
		else if(root->right==NULL)  // for one child
		{
			temp=root->left;
			free(root);
			return(temp);
		}
		else                       // for two child
		{
			temp=root->right;
			
			while(temp!=NULL && temp->left!=NULL)
			{
				temp=temp->left;                      // inorder sucessor
			}
			root->data=temp->data;                    // replace
			root->right=deletebst(root->right,temp->data);
		}
	}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

int main()
{
	int ch,val;
	struct node *root=NULL,*temp;
	do
	{
		printf("\n 1:create \n 2:display \n 3:delete");
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
				   temp=deletebst(root,val);
				   break;
		}
	}while(ch<4);
}
