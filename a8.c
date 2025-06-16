// 8) count sort.
#include<stdio.h>
void countsort(int a[100],int k,int n)
{
	int i,j=0,b[100],count[100];
	for(i=0;i<k;i++)
	{
		count[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		count[a[i]]=count[a[i]]+1;
	}
	
	for(i=0;i<=k;i++)
	{
		while(count[i]>0)
		{
			b[j++]=i;
			count[i]=count[i]-1;
		}
	}
	
	printf("sorted array=");
	for(i=0;i<n;i++)
	{
		printf("%d\t",b[i]);
	}
}

int main()
{
	int a[100],n,k,i;
	printf("enter limit=");
	scanf("%d",&n);
	printf("\n enter range=");
	scanf("%d",&k);
	printf("\n enter n no=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	countsort(a,k,n);
}
