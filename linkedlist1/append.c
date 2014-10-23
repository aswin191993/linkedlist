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

void play(struct node* head)
{
        while(head!=NULL)
        {
                printf("%d\n",head->data);
                head=head->next;
        }
}
void append(struct node **head,struct node **hdf)
{
	struct node* temp=NULL;
	temp=*head;
	if(*head==NULL)
	{
		*head=*hdf;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=*hdf;
	*hdf=NULL;
}

main()
{
        struct node* head=NULL;
        struct node* hdf=NULL;
        push(&head,1);
        push(&head,2);
        push(&hdf,3);
        push(&hdf,4);
        printf("*HEAD*\n");
        play(head);
	printf("*REF*\n");
	play(hdf);
        append(&head,&hdf);
        printf("*append*\n");
        play(head);
}
