/* 
2. Write a program that uses functions to perform the following operations on doubly linked
list.:
i) Creation ii) Insertion iii) Deletion iv) Traversal
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
struct list *previous;
int data;
struct list *next;
};
typedef struct list node;
node *start;

void add();
void display();
void count();
void deletenode();
void add_beg();
void insert();
void displayrev();

int main()
{
int ch;

while(1)
{

printf("\n1.Adding\n2.display\n3.count\n4.add beg\n5.add after\n6.display reverse\n7.delete\n8.Exit\n");
printf("\nEnter your choice :");
scanf("%d",&ch);
switch(ch)
{
case 1:
add();
break;
case 2:
display();
break;
case 3:
count();
break;
case 4:
add_beg();
break;
case 5:
insert();
break;
case 6:
displayrev();
break;
case 7:
deletenode();
break;
case 8:
exit(0);
}
}
return 0;
}

void add()
{
node *cur;
node *pre;
int n;
printf("Enter element :");
scanf("%d",&n);

if(start==NULL)
{
cur=(node*)malloc(sizeof(node));
cur->previous=NULL;
cur->data=n;
cur->next=NULL;
start=cur;
}
else
{
cur=start;
while(cur->next!=NULL)
cur=cur->next;

pre=(node*)malloc(sizeof(node));
pre->data=n;
pre->next=NULL;
cur->next=pre;
pre->previous=cur;
}
}
void display()
{
node *cur;
cur=start;
while(cur!=NULL)
{
printf("%d  ",cur->data);
cur=cur->next;
}
printf("---->NULL");
getch();
}

void count()
{
node *cur;
int c=0;
cur=start;

while(cur!=NULL)
{
cur=cur->next;
c++;
}
printf("No of nodes are  %d ",c);
getch();
}

void add_beg()
{
node *cur;
int n;
cur=(node*)malloc(sizeof(node));
printf("Enter element to add at the Begining :");
scanf("%d",&n);
cur->data=n;
cur->next=start;
cur->previous=NULL;
start->previous=cur;
start=cur;
}

void insert()
{
node *temp,*cur;
int n,loc,i;
cur=(node*)malloc(sizeof(node));
cur=start;
printf("Enter the element and location :");
scanf("%d%d",&n,&loc);
for(i=1;i<loc;i++)
{
cur=cur->next;
if(cur==NULL)
{
printf("Location not found");
getch();
return;
}
}
temp=(node*)malloc(sizeof(node));
temp->data=n;
temp->next=cur->next;
temp->previous=cur;
temp->next->previous=temp;
cur->next=temp;
}

void displayrev()
{
node *cur;
cur=start;
while(cur->next!=NULL)
{
cur=cur->next;
}
while(cur!=NULL)
{
printf("%d  ",cur->data);
cur=cur->previous;
}
getch();
}
void deletenode()
{
int n;
node *cur;
cur=start;
printf("Enter element to delete :");
scanf("%d",&n);
while(cur!=NULL)
{
if(cur->data==n)
{
if(cur==start)
{
cur->next->previous=NULL;
start=cur->next;
free(cur);
}
else
if(cur->next==NULL)
{
cur->previous->next=NULL;
free(cur);
}
else
{
cur->previous->next=cur->next;
cur->next->previous=cur->previous;
free(cur);
}
}
cur=cur->next;
}
}
