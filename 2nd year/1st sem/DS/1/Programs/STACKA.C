/* 
4. Write a program that implement stack (its operations) using
i) Arrays
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define SIZE 10
int stack[SIZE];
int top=-1;
void push(int);
int pop();
void display();

int main()
{

char c;
int ch;
int element;
while(1)
{

printf("\nMENU\n");
printf("1.Push\n2.Display\n3.Pop\n4.Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter element :");
scanf("%d",&element);
push(element);
break;
case 2:
display();
break;
case 3:
printf("\nPoped element :%d",pop());
getch();
break;
case 4:
exit(0);
}
}
return 0;
}
void push(int element)
{
if(top>=SIZE-1)
{
printf("Stack overflow");
getch();
}
else
{
top+=1;
stack[top]=element;
}
}

int pop()
{
if(top==-1)
printf("Stack underflow");
else
{
top-=1;
return stack[top+1];
}
return 0;
}

void display()
{
int i;
printf("Elements in Stack:\n");
for(i=0;i<=top;i++)
printf("%d  ",stack[i]);
getch();
}
