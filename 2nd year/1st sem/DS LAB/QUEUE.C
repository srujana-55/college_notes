
/*
5. Write a program that implement Queue (its operations) using
	 ii) Pointers
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 10
void insert(int[],int*,int*,int);
void qdelete(int[],int*,int*);
void display(int[],int,int);

int main()
{
int que[SIZE];
int front,rear,element,ch;
front=0;rear=-1;
while(1)
{

printf("\nMENU");
printf("\n1.Insert\n2.display\n3.delete\n4.Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter element :");
scanf("%d",&element);
insert(que,&front,&rear,element);
break;
case 2:
display(que,front,rear);
break;
case 3:
qdelete(que,&front,&rear);
break;
case 4:
exit(0);
}
}
return 0;
}
void insert(int q[],int *front,int *rear,int element)
{
if(*rear==SIZE-1)
printf("Q overflow");
else
{
*rear+=1;
q[*rear]=element;
}
getch();
}
  void display(int q[],int front,int rear)
{
if(front>rear)
printf("Q underflow");
else
while(front<=rear)
{
printf("%d  ",q[front]);
front++;
}
getch();
}
void qdelete(int q[],int *front,int *rear)
{
if(*front > *rear)
printf("Q underflow");
else
{
printf("deleted element :%d",q[*front]);
*front+=1;
}
getch();
}
