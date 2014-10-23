#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
};

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
void reverse(struct node **headref)
{
	struct node* newone=NULL;
	struct node* newtwo=NULL;
	struct node* newthree=NULL;
	newone=*headref;
	while(newone!=NULL)
	{
		newtwo=newone->next;
		newone->next=newthree;
		newthree=newone;
		newone=newtwo;
	}
	*headref=newthree;
}


main()
{
        struct node* head=NULL;
        push(&head,5);
        push(&head,4);
        push(&head,3);
        push(&head,2);
        printf("*before reverse*\n");
        play(head);
	reverse(&head);
	printf("*after reverse*\n");
        play(head);

}

