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
void alternatingsplit(struct node* source,struct node **aref,struct node **bref)
{
	struct node *tempso=NULL;
	struct node *tempare=NULL;
	struct node *tempbre=NULL;
	tempare=malloc(sizeof(struct node));
	tempbre=malloc(sizeof(struct node));
	tempso=source;
	tempare=*aref;
	tempbre=*bref;
	int aval,dval;
	while(tempso!=NULL)
	{
		aval=tempso->data;
		dval=aval%2;
		if(dval==0)
		{
			push(&tempare,aval);
		}
		else
		{
			push(&tempbre,aval);
		}
		tempso=tempso->next;
	}
	*aref=tempare;
	*bref=tempbre;
}

void play(struct node* head)
{
        while(head!=NULL)
        {
                printf("%d\n",head->data);
                head=head->next;
        }
}
main()
{
        struct node *head=NULL;
        struct node *aref=NULL;
	struct node *bref=NULL;
	push(&head,4);
        push(&head,3);
        push(&head,2);
        push(&head,1);
        printf("*head values*\n");
        play(head);
	alternatingsplit(head,&aref,&bref);
	printf("*even numbers*\n");
	play(aref);
	printf("*odd numbers*\n");
	play(bref);
}
