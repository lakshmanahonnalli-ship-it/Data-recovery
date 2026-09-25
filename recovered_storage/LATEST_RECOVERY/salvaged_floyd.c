#include<stdio.h>
#define MAX 20
#define INF 999

void floyd(int graph[MAX][MAX],int n)
	int dist[MAX][MAX];
	int i,j,k;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dist[i][j]=graph[i][j];
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(dist[i][k]!=INF&&dist[k][j]!=INF&&dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
	printf("shortest distance matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("%d",dist[i][j]);
		
		printf("\n");

int main()
	int graph[MAX][MAX];
	int i,j,n;
	printf("neter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix(use 999 for no edges and o for diagonal):\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
	floyd(graph,n);
	return 0;