#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void push(struct node **hdr,int n)
{
	struct node* temp=NULL;
	temp=malloc(sizeof(struct node));
	temp->data = n;
	temp->next=*hdr;
	*hdr=temp;
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
struct node* head=NULL;
push(&head,2);
push(&head,4);
display(head);
return(0);
}

	
