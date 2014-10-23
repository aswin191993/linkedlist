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

void insertsort(struct node **headref)
{
	struct node *temp=NULL;
	struct node *newone=NULL;
	struct node *ver=NULL;
	temp=*headref;
	int cnt,i;
	cnt=count(*headref);
	printf("count val:%d\n",cnt);
	for(i=1;i<=cnt;i++)
	{
		ver=temp->next;
			while(temp!=NULL)
			{
				sortedinsert(&newone,temp);
				temp=temp->next;
			}
		temp=ver;
	}
	*headref=newone;
}

main()
{
        struct node* head=NULL;
        push(&head,5);
        push(&head,3);
        push(&head,6);
        push(&head,4);
	push(&head,2);
        printf("*before the sort*\n");
        play(head);
        insertsort(&head);
        printf("*after the sort*\n");
	removeduplicates(&head);
        play(head);
}
