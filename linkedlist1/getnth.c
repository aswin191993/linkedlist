#include<stdlib.h>
#include<stdio.h>

struct node{
        int data;
        struct node *next;
        };


int getnth(struct node* head,int n)
{
        int cnt=0;
        while(head!=NULL)
        {
                cnt=cnt+1;
		if((cnt-1)==n)
		{
			return(head->data);
		}
                head=head->next;
        }
       // return(cnt);
}
void push(struct node **htr,int d)
{
	struct node* temp=NULL;
	temp=malloc(sizeof(struct node));
	temp->next=*htr;
	temp->data=d;
	*htr=temp;
}
main()
{
	int val,f;
	printf("enter the possion:");
	scanf("%d",&f);
	struct node* head=NULL;
	int i;
        for(i=1;i<=6;i++)
        {
                push(&head,i);
        }

	val=getnth(head,f);
	printf("%dth possion value:%d\n",f,val);
}
