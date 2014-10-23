#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
struct node* function(struct node** h,int d)
{
struct node* t=NULL;
struct node* t1=NULL;

t=malloc(sizeof(struct node));
t1=malloc(sizeof(struct node));
t1->data



t->next=(*h);
t->data=d;
t->next=(*h);
(*h)=t;
//printf("%d",t->data)
return(*h);

}

main()
{
struct node* new;
new=malloc(sizeof(struct node));
new=function(&new,40);
//new->next=&new;
new=function(&new,21);
printf("%d",new->data);
}

