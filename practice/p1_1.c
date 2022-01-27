#include<stdio.h>
#include<string.h>
int main()
{
char data[20],stuff[30];
int length,count=0,i,j=0;
printf("enter the data:");
scanf("%s",data);
length=strlen(data);
for(i=1;i<=length;i++)
{
if(data[i]=='1')
{
count++;
}
else
{
count=0;
}
stuff[j]=data[i];
j++;
if(count==5 && data[i+1]=='1')
{
stuff[j]='0';
j++;
count=0;
}
}
stuff[j]='\0';
printf("stuffed data at intermediate site is  \n 01111110 %s 01111110\n",stuff);
}


