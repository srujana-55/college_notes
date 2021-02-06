/*
3. Write a program that uses functions to perform the following operations on circular linked
list.:
i) Creation ii) Insertion iii) Deletion iv) Traversal
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct list
{
	int data;
	struct list *link;
};
typedef struct list node;
node *start;
void append();
void display();
void count();
void add_beg();
void insert();
void deletenode();

int main()
{
	int ch;
	while(1)
	{
		
		printf("1.Append\n2.count\n3.display\n4.insert\n5.add after\n6.delete\n7.exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				append();
				break;
			case 2:
				count();
				break;
			case 3:
				display();
				break;
			case 4:
				add_beg();
				break;
			case 5:
				insert();
				break;
			case 6:
				deletenode();
				break;
			case 7:
				exit(0);
		}
	}
	return 0;
}

void append()
{
	int n;
	node *cur;
	printf("Enter number :");
	scanf("%d",&n);
	if(start==NULL)
	{
		cur=(node*)malloc(sizeof(node));
		cur->data=n;
		cur->link=cur;
		start=cur;
	}
	else
	{
		cur=start;
		while(cur->link!=start)
			cur=cur->link;

		cur->link=(node*)malloc(sizeof(node));
		cur->link->data=n;
		cur->link->link=start;
	}
}
void display()
{
	node *cur;
	cur=start;
	do{
		printf("%d  ",cur->data);
		cur=cur->link;
	}while(cur!=start);
	getch();

}
void count()
{
	int c=0;
	node *cur;
	cur=start;
	do{
		cur=cur->link;
		c++;
	}while(cur!=start);
	printf("\nThe no of nodes are %d",c);
	getch();
}
void add_beg()
{
	node *cur;
	node *pre;
	int n;
	printf("Enter element ;");
	scanf("%d",&n);
	cur=(node*)malloc(sizeof(node));
	cur->data=n;
	cur->link=start;
	pre=start;

	while(pre->link!=start)
		pre=pre->link;

	pre->link=cur;
	start=cur;
}

void insert()
{
	node *cur,*temp;
	int i,loc,n,flag=0;
	cur=start;
	printf("Enter element and location :");
	scanf("%d%d",&n,&loc);
	for(i=1;i<loc;i++)
	{
		cur=cur->link;
		if(cur==start)
		{
			printf("Location not found ");
			flag=1;
			getch();
		}
	}
	if(flag==0)
	{
		temp=(node*)malloc(sizeof(node));
		temp->link=cur->link;
		temp->data=n;
		cur->link=temp;
	}
}
void deletenode()
{
	int n,flag=0;
	node *cur,*temp,*pre;
	cur=pre=start;
	temp=cur;
	printf("Enter element to delete :");
	scanf("%d",&n);
	do{
		if(temp->data==n)
		{
			flag=1;
			if(temp==start)
			{
				while(pre->link!=start)
				pre=pre->link;
				start=temp->link;
				free(temp);
				pre->link=start;
				break;
			}
			else
			{
				cur->link=temp->link;
				free(temp);
				break;
			}

		}
		else
		{
			cur=temp;
			temp=temp->link;
		}
	}while(temp!=start);
	if(!flag)
	{
		printf("Element %d is not found ",n);
		getch();
	}
}
