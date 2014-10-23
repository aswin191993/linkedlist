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

void movenode(struct node **head,struct node **newone)
{
        struct node *temph=NULL;
	struct node *tempn=NULL;
	struct node *temp=NULL;
	tempn=malloc(sizeof(struct node));
	temph=malloc(sizeof(struct node));
	temp=malloc(sizeof(struct node));
	temph=*head;
	tempn=*newone;
	temp=*head;
	int p;
	while((temph->next)!=NULL)
        {
                p=temph->next->data;
                push(&(tempn),p);
                temph=temph->next;
        }
        *newone=tempn;
	push(&(temp),temp->data);
	*head=temp;
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
	struct node *newone=NULL;
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printf("*head values*\n");
	play(head);
	movenode(&head,&newone);
	printf("*newone values*\n");
	play(newone);
	printf("*new head values*\n");
        play(head);

}

