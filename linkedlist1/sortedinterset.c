#include<stdlib.h>
#include<stdio.h>

struct node
{
        int data;
        struct node *next;
};

void push(struct node **htr, int n)
{
        struct node* temp=NULL;
        temp=malloc(sizeof(struct node));
        temp->next = *htr;
        temp->data=n;
        *htr=temp;
}

void play(struct node* head)
{
        while(head!=NULL)
        {
                printf("%d\n",head->data);
                head=head->next;
        }
}

struct node sortedintersect(struct node* a,struct node* b)
{
	struct node* aref=NULL;
	struct node* bref=NULL;
	aref=a;
	bref=b;
	while(aref!=NULL&&bref!=NULL)
	





main()
{
        struct node *a=NULL;
        struct node *b=NULL;
        push(&a,1);
        push(&a,2);
        push(&a,3);
        push(&a,4);
        push(&b,5);
        push(&b,6);
        push(&b,7);
        push(&b,8);
        printf("*a values*\n");
        play(a);
        printf("*b values*\n");
        play(b);
        sortedintersect(b,a);
}

