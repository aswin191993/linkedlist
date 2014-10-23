#include<stdlib.h>
#include<stdio.h>

struct node
{
        int data;
        struct node *next;
};

void push(struct node **htr, int n)
{
        struct node* temp=NULL;
        temp=malloc(sizeof(struct node));
        temp->next = *htr;
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

void sortedmerge(struct node *a,struct node *b)
{
        struct node* anode=NULL;
        struct node* bnode=NULL;
        struct node* newone=NULL;
        anode=a;
        bnode=b;
        if((bnode->data)>(anode->data))
        {
                while(bnode!=NULL)
                {
                        push(&newone,bnode->data);
                        bnode=bnode->next;
                }
                while(anode!=NULL)
                {
                        push(&newone,anode->data);
                        anode=anode->next;
                }
        }
        else
        {
                while(anode!=NULL)
                {
                        push(&newone,anode->data);
                        anode=anode->next;
                }
                while(bnode!=NULL)
                {
                        push(&newone,bnode->data);
                        bnode=bnode->next;
                }
        }
        printf("*sorted list*\n");
        play(newone);
}

void frontbacksplit(struct node* source,struct node **fr,struct node **br)
{
	struct node *sr=NULL;
	struct node *fre=NULL;
	struct node *bre=NULL;
	fre=malloc(sizeof(struct node));
	bre=malloc(sizeof(struct node));
	if(source==NULL) ;
	int cnt,val,odev;
	cnt=count(source);
	odev=cnt%2;
	sr=source;
	val=cnt/2;
	if(odev==1)
	{
		fre=*fr;
		while(val>0)
		{
    			push(&(fre),sr->data);
        		sr=sr->next;
			val=val-1;
		}
		*fr=fre;
		bre=*br;
		while(sr!=NULL)
		{
			push(&(bre),sr->data);
                        sr=sr->next;
		}
		*br=bre;
	}
	else if(odev==0)
        {
                fre=*fr;
                while((val)>0)
                {
                        push(&(fre),sr->data);
                        sr=sr->next;
                        val=val-1;
                }
                *fr=fre;
                bre=*br;
                while(sr!=NULL)
                {
                        push(&(bre),sr->data);
                        sr=sr->next;
                }
                *br=bre;
        }
}

void mergesort(struct node** headref)
{
	struct node* temp=NULL;
	struct node* frd=NULL;
	struct node* bkd=NULL;
	struct node* frda=NULL;
        struct node* bkda=NULL;
	temp=*headref;
	if(temp==NULL||temp->next==NULL) 
	{
		return;
	}
	frontbacksplit(temp,&frd,&bkd);
	printf("*afer the split*\n");
        play(frd);
        printf("*B*\n");
        play(bkd);
	mergesort(&frd);
	mergesort(&bkd);
	sortedmerge(frd,bkd);
}
main()
{
	struct node* head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
//	push(&head,5);
//	push(&head,6);
	printf("*source values*\n");
	play(head);
//	printf("*front values*\n");
	mergesort(&head);
}


