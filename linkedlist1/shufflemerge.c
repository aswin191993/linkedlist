#include<stdlib.h>
#include<stdio.h>

struct node{
        int data;
        struct node *next;
        };

void push(struct node **htr,int n)
{
        struct node *temp=NULL;
        temp=malloc(sizeof(struct node));
        temp->next=*htr;
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

void shufflemerge(struct node *a,struct node *b)
{
	struct node* anode=NULL;
	struct node* bnode=NULL;
	struct node* newone=NULL;
	anode=a;
	bnode=b;
	while(anode!=NULL&&bnode!=NULL)
	{
		push(&newone,anode->data);
		push(&(newone->next),bnode->data);
		anode=anode->next;
		bnode=bnode->next;
	}
	printf("*shufflemerge*\n");
	play(newone);
}

main()
{
        struct node *a=NULL;
        struct node *b=NULL;
        push(&a,4);
        push(&a,3);
        push(&a,2);
        push(&a,1);
	push(&b,5);
	push(&b,6);
	push(&b,7);
	push(&b,8);
        printf("*a values*\n");
        play(a);
	printf("*b values*\n");
	play(b);
	shufflemerge(a,b);
}
