/*
5. Write a program that implement Queue (its operations) using
	i) Arrays 
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5

int que[SIZE];
int front,rear;
void enqueue(int);
int dequeue();
void display();

int main()
{
int element;
int ch;

front=0;
rear=-1;


while(1)
{

printf("\nMENU\n");
printf("1.insert\n2.delete\n3.display\n4.exit\n");
printf("Enter your choice :");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter element :");
scanf("%d",&element);
enqueue(element);
break;
case 2:
element=dequeue();
printf("Deleted element : %d",element);
getch();
break;
case 3:
display();
break;
case 4:
exit(0);
}
}
return 0;
}
void enqueue(int element)
{
if(rear==SIZE-1)
{
printf("Overflow");
getch();
}
else
{
rear=rear+1;
que[rear]=element;
}
}
int dequeue()
{
if(front>rear)
{
printf("underflow");
return 0;
}
front=front+1;
return que[front-1];
}

void display()
{
int i;
for(i=front;i<=rear;i++)
printf("%d ",que[i]);

getch();
}



