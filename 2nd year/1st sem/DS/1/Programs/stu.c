#include<stdio.h>
#include<malloc.h>
int main(){
	struct student{
		int rno;
		char name[20];
		float fee;
	};
	typedef struct student stu;
	
	stu *s;
	s=(stu*)malloc(sizeof(stu));
	printf("Enter student details\n");
	scanf("%d%s%f",&s->rno,s->name,&s->fee);
	printf("Student data\n");
	printf("Roll No : %d\n",s->rno);
	printf("Name    : %s\n",s->name);
	printf("Fee     : %.2f\n",s->fee);
	
	free(s);
}
