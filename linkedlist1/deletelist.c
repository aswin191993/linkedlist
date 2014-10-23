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

void deletelist(struct node **htr)
{
	struct node* dle=NULL;
	struct node* dup=NULL;
	dup=malloc(sizeof(struct node));
	dle=malloc(sizeof(struct node));
	dle=*htr;
	while(dle!=NULL)
	{
		dup=dle->next;
		free(dle);
		dle=dup;
	}

}
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


main()
{
	struct node *head=NULL;
	int i;
	long rin;
	for(i=0;i<=10;i++)
	{
		push(&head,i);
	}
	play(head);
	deletelist(&head);
	printf("after the deletelist\n");
	play(head);
}
