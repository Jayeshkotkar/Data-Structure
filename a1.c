// 1) linear search.
#include<stdio.h>
int main()
{
	int a[100],i,n,x,f=0;
	printf("enter limit=");
	scanf("%d",&n);
	printf("\n enter n no=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n enter no to search=");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	printf("found");
	else
	printf("not found");
}
