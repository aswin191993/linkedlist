#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* next;
};

void push(struct node **htr,int n)
{
	struct node *temp=NULL;
	temp=malloc(sizeof(struct node));
	temp->next=*htr;
	temp->data=n;
	*htr=temp;
}
int pop(struct node **head)
{
	struct node* temp=NULL;
	int val;
	temp=*head;
	val=temp->data;
	*head=temp->next;
	free(temp);
	return(val);

}


main()
{
	

	int k,l;
	struct node* head=NULL;
	head=malloc(sizeof(struct node));
	push(&head,4);
	push(&head,3);
	push(&head,2);
	k=pop(&head);
	l=pop(&head);
	printf("val:%d,%d\n",k,l);
}


