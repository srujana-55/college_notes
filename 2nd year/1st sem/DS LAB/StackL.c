#include<stdio.h>
#include<stdlib.h>

struct StackNode{
	int data;
	struct StackNode *link;
};
typedef struct StackNode node;
node *top;

void push(int);
int pop();
void display();

int main(){
	int ch,n;
	top=NULL;
	while(1){
		printf("\nMENU\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("Enter your Choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element: ");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				printf("Removed element: %d",pop());
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

void push(int n){
	node *c;
	c=(node*)malloc(sizeof(node));
	c->data=n;
	c->link=top;
	top = c;
}

int pop(){
	int n;
	node *c;
	if(top!=NULL){
		c=top;
		top=top->link;
		n=c->data;
		free(c);
		return n;
	}
	return 0;
}
void display(){
	node *c;
	c=top;
	while(c!=NULL){
		printf("%d\t",c->data);
		c=c->link;
	}
}
