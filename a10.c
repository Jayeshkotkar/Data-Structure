// accept n city names and search unsing binary search.
#include<stdio.h>
#include<string.h>
int main()
{
	int f=0,i,n,top,mid,bottom;
	char s1[100][100],s2[10];
	printf("enter limit=");
	scanf("%d",&n);
	printf("enter city names in ascending order=");
	for(i=0;i<n;i++)
	{
		scanf("%s",&s1[i]);
	}
	printf("enter city name to search=");
	scanf("%s",&s2);
	top=0;
	bottom=n-1;
	
	while(top <= bottom)
	{
		mid=(top+bottom)/2;
		
		if(strcmp(s1[mid],s2)==0)
		{
			f=1;
			break;
		}
		
		if(strcmp(s2,s1[mid])>0)
		top=mid+1;
		
		if(strcmp(s2,s1[mid])<0)
		bottom=mid-1;
	}
	if(f==1)
	printf("city found");
	else
	printf("city not found");
}
