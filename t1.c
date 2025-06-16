//1) create tree and display.
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

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
			postorder(root->left);
			postorder(root->right);
			printf("%d\t",root->data);
	}
}

int main()
{
	struct node *root=NULL;
	root=create(root);
	printf("\n display inorder=");
	inorder(root);
	printf("\n display preorder=");
	preorder(root);
	printf("\n display postorder");
	postorder(root);
}
