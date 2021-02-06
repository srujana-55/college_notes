/* 
6. Write a program that implements the following sorting methods to sort a given list of
integers in ascending order
	 ii) Selection sort 
*/
#include<stdio.h>

void selectionsort(int*, int);
int main()
{
	int a[50],n,i,j,temp;


	printf("Enter size of Array:");
	scanf("%d",&n);

	printf("Enter elements :\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	selectionsort(a,n);

	printf("\nSorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);

	return 0;
}

void selectionsort(int *a,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
}
