#include<stdio.h>
#include<stdlib.h>

struct node
{
	int dist[15];
	int from[15];
};

int main()
{
	int a[15][15],n=0,i,j,k,count;
	struct node s[10];
	printf("enter number of nodes\n");
	scanf("%d",&n);
	printf("enter matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			s[i].dist[j]=a[i][j];//read it as from i to j distance is a[i][j]
			s[i].from[j]=j; // read it as from i to j next node is j
		}
	}
	//remember floyd's algorithm? all pairs shortest path, apply the same logic!
	do
	{
		count=0;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(s[i].dist[j] > a[i][k] + s[k].dist[j])
					{
						s[i].dist[j] = a[i][k] + s[k].dist[j];
						s[i].from[j]=k;
						count++;
					}
				}
			}
		}
	}while(count!=0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Src : %d -> Dest : %d Next node : %d Distance : %d\n",i,j,s[i].from[j],s[i].dist[j]);
		}
		printf("\n");
	}
}

