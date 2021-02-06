#include<stdio.h>
#include<stdlib.h>

struct qnode{
	int data;
	struct qnode *link;
};
typedef struct qnode node;
node *front, *rear;

void enqueue(int n);
int dequeue();
void display();

int main(){
	int n,ch;
	front=rear=NULL;
	while(1){
		printf("\nMENU\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element:");
				scanf("%d",&n);
				enqueue(n);
				break;
			case 2:
				printf("Deleted element : %d",dequeue());
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

void enqueue(int n){
	node *c;
	c=(node*)malloc(sizeof(node));
	c->data=n;
	c->link=NULL;
	if(rear == NULL){
		front=rear=c;
	}
	else{
		rear->link=c;
		rear=c;
	}
}

int dequeue(){
	node *c;
	int temp;
	if(front==NULL)
		return 0;
	c=front;
	front=front->link;
	temp=c->data;
	free(c);
	return temp;
}

void display(){
	node *c;
	c=front;
	if(c==NULL){
		printf("Queue is empty");
	}
	else{
		while(c!=NULL){
			printf("%d  ",c->data);
			c=c->link;
		}
	}
}


