#include<stdio.h>
#include<stdlib.h>

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
void removeduplicates(struct node **htr)
{
        struct node* dle=NULL;
        struct node* dup=NULL;
        dup=malloc(sizeof(struct node));
        dle=malloc(sizeof(struct node));
        dle=*htr;
	int vertu;
	while(dle->next!=NULL)
	{
        	if((dle->data)==(dle->next->data))
		{
			dup=dle->next->next;
        	        free(dle->next);
        	        dle->next=dup;
		}
		else
		{
			dle=dle->next;
		}
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
        struct node* head=NULL;
        push(&head,5);
        push(&head,5);
        push(&head,3);
        push(&head,2);
	push(&head,1);
        printf("*before the sort*\n");
        play(head);
        printf("*after removed duplicate*\n");
	removeduplicates(&head);
	play(head);
}
