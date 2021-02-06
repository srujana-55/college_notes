/*
6. Write a program that implements the following sorting methods to sort a given list of
integers in ascending order
	 iii) Insertion sort
*/
#include<stdio.h>
int main()
{
int i,j,c,n,a[50];
clrscr();
printf("insertion Sort:\n");
printf("Enter elements(0 to exit):");
scanf("%d",&n);
c=0;
while(n!=0)
{
j=c-1;
while(n<a[j]&&j>=0)
{
a[j+1]=a[j];
--j;
}
a[j+1]=n;
printf("\n After Insertion element %d\n",n);
for(i=0;i<=c;i++)
printf("%d  ",a[i]);
printf("\n");
printf("Enter element (0 to exit):");
scanf("%d",&n);
++c;
}
printf("\n Final Sorted Array:\n");
for(i=0;i<c;i++)
printf("%d  ",a[i]);

return 0;
}
