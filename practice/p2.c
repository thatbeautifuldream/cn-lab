#include<stdio.h>
#include<stdlib.h>
struct node
{
int dist[15];
int from[15];
};

int main()
{
int a[15][15],i,j,k,n=0,count=0;
struct node s[10];
printf("enter the number of nodes:");
scanf("%d",&n);
printf("enter matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
s[i].dist[j]=a[i][j];
s[i].from[j]=j;
}
}
do
{
for(i=1;i<=n;i++)
{
for(k=1;k<=n;k++)
{
for(j=1;j<=n;j++)
{
if(s[i].dist[j]>a[i][k]+s[k].dist[j])
{
s[i].dist[j]=a[i][k]+s[k].dist[j];
s[i].from[j]=k;
count++;
}
}
}
}
}
while(count!=0);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("src:%d->dest:%d Nextnode:%d distange:%d\n",i,j,s[i].from[j],s[i].dist[j]);
}
printf("\n");
}
}

