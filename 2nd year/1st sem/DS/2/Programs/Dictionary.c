#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dic{
	int key;
	char value[20];
	struct Dic *link;
};
typedef struct Dic DicNode;
DicNode *start;

void insert(int,char*);
void removekey(int);
void display();
char* search(int);

int main(){
	char ch;
	int key;
	char value[20];
	start=NULL;
	while(1){
		printf("\nMENU\n1.insert\n2.search\n3.delete\n4.display\n5.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter Key and value:");
				scanf("%d%s",&key,value);
				insert(key,value);
				break;
			case 2:
				printf("Enter Key for Search:");
				scanf("%d",&key);
				printf("Value : %s",search(key));
				break;
			case 3:
				printf("Enter key to delete:");
				scanf("%d",&key);
				removekey(key);
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}

void insert(int key, char *value){
	DicNode *c;
	int flag=0;
	c=start;
	if(start==NULL){
		start=(DicNode*)malloc(sizeof(DicNode));
		start->key=key;
		strcpy(start->value,value);
		start->link=NULL;
	}
	else{
		while(c->link != NULL){
			if(c->key == key){
			 	strcpy(c->value,value);
				 flag=1;
				 break;
			}
			c=c->link;
		}
		if(flag==0){
			c->link=(DicNode*)malloc(sizeof(DicNode));
			c->link->key=key;
			strcpy(c->link->value,value);
			c->link->link=NULL;
		}
	}
}

void removekey(int key){
	DicNode *c,*pre;
	c=start;
	while(c != NULL){
		if(c->key == key){
			if(c == start){
				start=start->link;
				free(c);
				break;
			}
			else{
				pre->link = c->link;
				free(c);
				break;
			}
		}
		pre=c;
		c=c->link;
	}
}
char* search(int key){
	DicNode *c;
	int flag=0;
	c=start;
	
	while(c != NULL){
		if(c->key == key){
			 return c->value;
			 break;
		}
		c=c->link;
	}
	return NULL;
}

void display(){
	DicNode *c;
	c=start;
	while(c!=NULL){
		printf("{%d : %s},",c->key,c->value);
		c=c->link;
	}
}
