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

void sortedinsert(struct node **headref,struct node *newnode)
{
	struct node* temp=NULL;
	struct node* ref=NULL;
	int tval,aval;
	temp=*headref;
	if(*headref==NULL)
	{
		push(headref,newnode->data);
	}
	while(temp!=NULL)
	{
		if((newnode->data)>(temp->data))
		{
			tval=(temp->data);
			aval=(tval+1);
			if(aval==(newnode->data))
			{
			push((&temp->next),newnode->data);
			}
		}
		temp=temp->next;
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
	struct node* hdf=NULL;
//	hdf=malloc(sizeof(struct node));
	push(&hdf,4);
//	head=malloc(sizeof(struct node));
	push(&head,6);
	push(&head,5);
	push(&head,3);
	push(&head,2);
	printf("*before the insert*\n");
	play(head);
	sortedinsert(&head,hdf);
	printf("*after the insert*\n");
	play(head);
}

