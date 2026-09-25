#include<stdio.h>
#define MAX 20

void warshall(int graph[MAX][MAX],int n)
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
					graph[i][j]=graph[i][j]||(graph[i][k]&&graph[k][j]);
	printf("Transitive closure matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("%d",graph[i][j]);
		
		printf("\n");

int main()
	int graph[MAX][MAX];
	int i,j,n;
	printf("enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix(use 999 for no edges and o for diagonal):\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);
	warshall(graph,n);
	return 0;

