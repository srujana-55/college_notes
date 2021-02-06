/*
7. Write a program that use both recursive and non recursive functions to perform the
following searching operations for a Key value in a given list of integers:
	i) Linear search 
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
int *a,i,key,n,flag=0;


printf("Enter size of Array:");
scanf("%d",&n);

a=(int*)malloc(sizeof(int)*n);

printf("Enter elements :");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

printf("Enter element to Search :");
scanf("%d",&key);

for(i=0;i<n;i++)
if(a[i]==key)
{
printf("element found\n");
printf("index is :%d",i);
flag=1;
break;
}

if(!flag)
printf("element not found");

return 0;
}
