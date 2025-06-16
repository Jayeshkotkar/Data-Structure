// 6) merge sort.
#include<stdio.h>

void merge(int a[100],int top,int mid,int bottom)
{
	int i,j,k=0,b[100],n;
	i=top;j=mid+1;
	
	while(i<=mid && j<=bottom)
	{
		if(a[i] < a[j])
		b[k++]=a[i++];
		else
		b[k++]=a[j++];
	}
	
	while(i<=mid)
	b[k++]=a[i++];
	
	while(j<=bottom)
	b[k++]=a[j++];
	
	for(i=top,k=0;i<=bottom;i++,k++)
	a[i]=b[k];
}

void mergesort(int a[100],int top,int bottom)
{
	int mid;
	if(top < bottom)
	{
		mid=(top+bottom)/2;
		
		mergesort(a,top,mid);
		mergesort(a,mid+1,bottom);
		merge(a,top,mid,bottom);
	}
}

int main()
{
	int a[100],i,n;
	printf("enter limit=");
	scanf("%d",&n);
	printf("\n enter n no=");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	mergesort(a,0,n-1);
	printf("sorted array=");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		
	}
}
