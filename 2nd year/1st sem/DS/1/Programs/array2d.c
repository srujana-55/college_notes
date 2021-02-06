#include<stdio.h>
#include<malloc.h>
int main(){
	int **p;
	int r,c,i,j;
	printf("Enter No.of Rows & Cols\n");
	scanf("%d%d",&r,&c);
	p=(int**)malloc(r*sizeof(int *));
	for(i=0;i<r;i++)
		p[i]=(int*)malloc(c*sizeof(int));
	printf("Enter Array Values\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			scanf("%d",&p[i][j]);
	}
	printf("Entered Matrix\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%d\t",p[i][j]);
		printf("\n");
	}
	for(i=0;i<r;i++)
		free(p[i]);
	free(p);
}
