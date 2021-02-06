/*
8. Write a program to implement the tree traversal methods.
*/

#include<stdio.h>
#include<stdlib.h>

struct nodetype{
struct nodetype *left;
int info;
struct nodetype *right;
};
typedef struct nodetype node;
node *root;
node* maketree(int);
void setleft(node*,int);
void setright(node*,int);
void pretrav(node*);
void intrav(node*);
void posttrav(node*);

int main()
{
node *p,*q;
int num;

printf("Enter element :");
scanf("%d",&num);
root=maketree(num);
while(scanf("%d",&num)!=EOF)
{
p=q=root;
while(num!=p->info && q!=NULL)
{
p=q;
if(num<p->info)
q=p->left;
else
q=p->right;
}
if(num==p->info)
printf("%d is duplicate\n",num);
else if(num<p->info)
setleft(p,num);
else
setright(p,num);
}
printf("\npreorder\n");
pretrav(root);
printf("\npostorder\n");
posttrav(root);
printf("\ninorder\n");
intrav(root);
return 0;
}

node* maketree(int x)
{
node *p;
p=(node*)malloc(sizeof(node));
p->info=x;
p->left=NULL;
p->right=NULL;
return p;
}

void setleft(node *p,int x)
{
if (p==NULL)
printf("void insertion\n");
else if(p->left!=NULL)
printf("invalid insertion");
else
p->left=maketree(x);
}

void setright(node *p,int x)
{
if (p==NULL)
printf("void insertion\n");
else if(p->right!=NULL)
printf("invalid insertion");
else
p->right=maketree(x);
}

void pretrav(node *tree)
{
if(tree!=NULL)
{
printf("%d\t",tree->info);
pretrav(tree->left);
pretrav(tree->right);
}
}
void intrav(node *tree)
{
if(tree!=NULL)
{
intrav(tree->left);
printf("%d\t",tree->info);
intrav(tree->right);
}
}
void posttrav(node *tree)
{
if(tree!=NULL)
{
posttrav(tree->left);
posttrav(tree->right);
printf("%d\t",tree->info);
}
}
