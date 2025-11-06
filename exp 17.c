#include<stdio.h>
int main()
{
	int i,j, a[10],max[10],all,need[10],tot=0;
	for(i=0;i<5;i++)
	{   printf("enter the allocation p%d:\n",i);
		scanf("%d",&a[i]);
	}
	for(i=0 ;i<5;i++)
	{	printf("enter the max p%d:\n",i);
		scanf("%d",&max[i]);
	}
	printf("enter the available:");
	scanf("%d",&all);
		for(i=0;i<5;i++)
	{
		need[i]=max[i]-a[i];
	}
	for(i=0;i<5;i++)
	{if(need[i]<=all)
		{
		    printf("p%d,",i);
			tot+=all+a[i];
		}
	}
			for(i=0;i<5;i++)
	{
	if(all<need[i])
		{
		printf("p%d,",i);
		}
	}
	}
