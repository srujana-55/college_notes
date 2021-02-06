/*
7. Write a program that use both recursive and non recursive functions to perform the
following searching operations for a Key value in a given list of integers:
	 ii) Binary search
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
int *a,n,i,key,min,max,mid;
int flag=0;

printf("Enter size of array:");
scanf("%d",&n);

a=(int*)malloc(sizeof(int)*n);

printf("Enter elements :");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

printf("Enter element to Search :");
scanf("%d",&key);

min=0;
max=n-1;
while(min<=max)
{
mid=(min+max)/2;
if(a[mid]==key)
{
printf("Element found in index %d",mid);
flag=1;
break;
}
if(key<a[mid])
max=mid-1;
else
if(key>a[mid])
min=mid+1;
}
if(!flag)
printf("Element not found");

return 0;
}
