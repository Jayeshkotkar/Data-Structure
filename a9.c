// read data from city.txt file and search city using linear search.
#include<stdio.h>
#include<string.h>
int main()
{
	int f=0,code;
	char cname[20],s1[20];
	FILE *f1;
	f1=fopen("city.txt","r");
	if(f1==NULL)
	{
		printf("file not found");
		exit(0);
	}
	printf("enter city name to search=");
	scanf("%s",&s1);
	while(!feof(f1))
	{
		fscanf(f1,"%s%d",&cname,&code);
		if(strcmp(cname,s1)==0)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	printf("city found");
	else
	printf("city not found");
}
