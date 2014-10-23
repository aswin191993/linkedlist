#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *next;
	};


int count(struct node* head)
{
	int cnt;
	while(head!=NULL)
	{
		cnt=cnt+1;
		head=head->next;
	}
	return(cnt);
}

void push(struct node **htr, int n)
{
	struct node* temp=NULL;
	temp=malloc(sizeof(struct node));
	temp->next = *htr;
	temp->data=n;
	*htr=temp;
}

int main()
{
	int val;
	struct node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	val=count(head);
	printf("count value:%d\n",val);
}
