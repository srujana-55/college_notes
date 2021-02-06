#include<stdio.h>
#include<stdlib.h>
#define SIZE 80
int stk[80];
int top=-1;

void push(double x){
	if(top == SIZE-1){
		printf("Stack is full");
	}
	else{
		top = top+1;
		stk[top]=x;
	}
}
int pop(){
	if(top == -1){
		return 0;
	}
	return stk[top--];
}
double calculate(char c, double val1, double val2){
	switch(c){
		case '+':
			return val1+val2;
		case '-':
			return val1-val2;
		case '*':
			return val1*val2;
		case '/':
			return val1/val2;
		defaule:
			printf("Unknow operator");
			return 0;
	}
}
int main(){
	char post[80];
	int i=0;
	char c;
	double val1,val2,res;
	printf("Enter postfix string\n");
	scanf("%s",post);
	for(i=0; post[i]!='\0' ; i++){
		c=post[i];
		if(isdigit(c)){
			push((double)c-'0');
		}
		else{
			val2=pop();
			val1=pop();
			res=calculate(c,val1,val2);
			
			push(res);
		}
	}
	res=pop();
	printf("Result =%lf",res);
}
