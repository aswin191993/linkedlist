#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;
};

void push(struct node **head,int f)
{
	struct node *gen;
	gen = malloc(sizeof(struct node));
	gen->data=f;
	gen->next=*head;
	*head=gen;

}
struct node* makenew(struct node** a)
{

	struct node* mka=NULL;
	struct node* mk=NULL;
	mka=*a;
	int h;
	h=mka->data;
	mka->data=(h+2);
	return(mka);
}

void display(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}
int main()
{
	struct node *head=NULL;
	push(&head,6);
	display(head);
	head=makenew(&head);
	display(head);
	return(0);
}
