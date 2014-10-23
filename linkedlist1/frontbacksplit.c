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
void frontbacksplit(struct node* source,struct node **fr,struct node **br)
{
	struct node *sr=NULL;
	struct node *fre=NULL;
	struct node *bre=NULL;
	fre=malloc(sizeof(struct node));
	bre=malloc(sizeof(struct node));

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
		bre->next=*br;
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

main()
{
	struct node* head=NULL;
	struct node* fr=NULL;
	struct node* br=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	printf("*source values*\n");
	play(head);
	frontbacksplit(head,&fr,&br);
	printf("*front values*\n");
	play(fr);
	printf("*back values*\n");
	play(br);
}


