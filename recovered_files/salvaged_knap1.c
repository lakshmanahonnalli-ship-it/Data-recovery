#include<stdio.h>
int max(int a,int b)
	return(a>b)?a:b;

int main()
	int n,w;
	printf("Enter the number of items:");
	scanf("%d",&n);
	int wt[n+1],val[n+1];
	
	printf("Enter weights:\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&wt[i]);
	printf("Enter profits:\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	printf("Enter knapsack capacity:");
	scanf("%d",&w);
	int v[n+1][w+1];
	for(int i=0;i<=n;i++)
		v[i][0]=0;
	for(int j=0;j<=w;j++)
		v[0][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=w;j++)
			if(wt[i]<=j)
				v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
			else
				v[i][j]=v[i-1][j];
	printf("maximum profit %d\n",v[n][w]);
	
	int i=n,j=w;
	printf("selected items:");
	
	while(i>0)
		if(v[i][j]!=v[i-1][j])
			printf("%d",i);
			j=j-wt[i];
		i--;
	printf("\n");
	return 0;