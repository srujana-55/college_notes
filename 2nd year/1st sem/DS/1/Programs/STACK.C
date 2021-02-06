/* 
4. Write a program that implement stack (its operations) using
	ii) Pointers
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define SIZE 10
void push(int[],int*,int);
int pop(int[],int*);
void display(int[],int*);

int main()
{
int stack[SIZE];
int top=-1;
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
push(stack,&top,element);
break;
case 2:
display(stack,&top);
break;
case 3:
printf("\nPoped element :%d",pop(stack,&top));
getch();
break;
case 4:
exit(0);
}
}
return 0;
}
void push(int stack[],int *top,int element)
{
if(*top>=SIZE-1)
{
printf("Stack overflow");
getch();
}
else
{
*top+=1;
stack[*top]=element;
}
}

int pop(int stack[],int *top)
{
if(*top==-1)
printf("Stack underflow");
else
{
*top-=1;
return stack[*top+1];
}
return 0;
}

void display(int stack[],int *top)
{
int i;
printf("Elements in Stack:\n");
for(i=0;i<=*top;i++)
printf("%d  ",stack[i]);
getch();
}
