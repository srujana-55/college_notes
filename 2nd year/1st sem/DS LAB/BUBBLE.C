/* 
6. Write a program that implements the following sorting methods to sort a given list of
integers in ascending order
	i) Bubble sort 
*/
#include<stdio.h>
#include<stdlib.h>
void bubblesort(int*, int);
int main()
{
	int a[50],n,i,j,temp;

	printf("Enter size of array:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	bubblesort(a,n);
	printf("\nSorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d\t ",a[i]);
	return 0;
}

void bubblesort(int *a,int n){
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
