#include<stdio.h>
#include<stdlib.h>

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

void insertnth(struct node **headref,int index,int data)
{
	struct node* temp=NULL;
	temp=malloc(sizeof(struct node));
	struct node* ref=NULL;
	int val;
	//temp=*headref;
	//val=temp->data;
	if(index==0)
	{
		push(headref,data);
	}
	else
	{
		temp->next=*headref;
		temp=temp->next;
		push(&(temp->next),data);

	}
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
	struct node* head=NULL;
	head=malloc(sizeof(struct node));
	insertnth(&head,0,32);
	insertnth(&head,1,74);
	insertnth(&head,1,55);
	play(head);
}
