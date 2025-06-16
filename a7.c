// 7) quick sort.
#include<stdio.h>

int partition(int a[100],int lb,int ub)
{
	int i,j,t,pivot;
	pivot=a[ub];
	i=lb-1;
	for(j=lb;j<ub;j++)
	{
		if(a[j] < pivot)
		{
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[ub];
	a[ub]=t;
	return i+1;
}

void quicksort(int a[100],int lb,int ub)
{
	int k;
	if(lb < ub)
	{
		k=partition(a,lb,ub);
		quicksort(a,lb,k-1);
		quicksort(a,k+1,ub);
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
	
	quicksort(a,0,n-1);
	
	printf("sorted array=");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
