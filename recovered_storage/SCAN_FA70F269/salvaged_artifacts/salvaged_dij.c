#include<stdio.h>
#define MAX 100
#define INF 999

void dijkstras(int cost[MAX][MAX],int n,int source,int dist[MAX])
	int visited[MAX],i,j,min,u;
	for(i=1;i<=n;i++)
		dist[i]=cost[source][i];
		visited[i]=0;
	dist[source]=0;
	visited[source]=1;
	
	for(i=1;i<n;i++)
		min=INF;
		u=-1;
		for(j=1;j<=n;j++)
			if(!visited[j]&&dist[j]<min)
				min=dist[j];
				u=j;
		if(u==-1)
			break;
		visited[u]=1;
		
		for(j=1;j<=n;j++)
			if(!visited[j]&&cost[u][j]!=INF&&dist[u]+cost[u][j]<dist[j])
				dist[j]=dist[u]+cost[u][j];

int main()
	int cost[MAX][MAX],dist[MAX];
	int i,j,n,source;
	
	printf("enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the code adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	printf("enter the source node:");
	scanf("%d",&source);
	dijkstras(cost,n,source,dist);
	printf("\n");
	
	for(i=1;i<=n;i++)
		if(dist[i]==INF)
			printf("shortest distance from %d to %d is INF\n",source,i);
		else
			printf("shortest distance from %d TO %d is %d\n",source,i,dist[i]);
	return 0;
