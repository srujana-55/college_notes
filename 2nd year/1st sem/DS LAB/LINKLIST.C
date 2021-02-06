/*
1. Write a program that uses functions to perform the following operations on singly linked
list.:
i) Creation ii) Insertion iii) Deletion iv) Traversal
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *next;
};
typedef struct list node;
node *head;
void append();
void display();
void add_beg();
void insert();
void deletenode();

int main()
{
	int ch;
	head=NULL;
	while(1)
	{
		
		printf("\n1.append\n2.display\n3.Add beg\n4.insert\n5.delete\n6.exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				append();
				break;
			case 2:
				display();
				break;
			case 3:
				add_beg();
				break;
			case 4:
				insert();
				break;
			case 5:
				deletenode();
				break;
			case 6:
				exit(0);
		}
	}
	return 0;
}

void append()
{
int n;
node *cur;
node *temp;
temp=head;
printf("Enter number :");
scanf("%d",&n);
if(head==NULL)
{
cur=(node*)malloc(sizeof(node));
cur->data=n;
cur->next=NULL;
head=cur;
}
else
{
while(temp->next!=NULL)
    temp=temp->next;
cur=(node*)malloc(sizeof(node));
cur->data=n;
cur->next=NULL;
temp->next=cur;
}
}
void display()
{
node *temp;
temp=head;
while(temp!=NULL)
{
printf("%d  ",temp->data);
temp=temp->next;
}
getch();

}

void add_beg()
{
node *cur;
int n;
printf("Enter element ;");
scanf("%d",&n);
cur=(node*)malloc(sizeof(node));
cur->data=n;
cur->next=head;
head=cur;
}

void insert()
{
node *cur,*temp;
int i,loc,n;
temp=head;
int flag=0;
printf("Enter element and location :");
scanf("%d%d",&n,&loc);
for(i=1;i<loc;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("Location not found ");
getch();
flag=1;
}
}
if(flag==0){
cur=(node*)malloc(sizeof(node));
cur->next=temp->next;
cur->data=n;
temp->next=cur;
}
}
void deletenode()
{
int n,flage=0;
node *cur,*temp;
cur=head;
temp=cur;
printf("Enter element to delete :");
scanf("%d",&n);
while(temp!=NULL)
{
if(temp->data==n)
{
if(temp==head)
{
head=temp->next;
free(temp);
}
else
{
cur->next=temp->next;
free(temp);
}
flage=1;
break;
}
else
{
cur=temp;
temp=temp->next;
}
}
if(!flage)
{
printf("Element %d is not found ",n);
getch();
}
}

