// 2) binary search.
#include<stdio.h>
int main()
{
	int a[100],n,i,f=0,top,mid,bottom,x;
	printf("enter limit=");
	scanf("%d",&n);
	printf("enter n no in sorted order=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter no to search=");
	scanf("%d",&x);
	top=0;
	bottom=n-1;
	while(top <= bottom)
	{
		mid=(top+bottom)/2;
		
		if(a[mid]==x)
		{
			f=1;
			break;
		}
		
		if(x > a[mid])
		{
			top=mid+1;
		}
		
		if(x < a[mid])
		{
			bottom=mid-1;
		}
	}
	
	if(f==1)
	printf("num found at position=%d",mid);
	else
	printf("num not found");
}
