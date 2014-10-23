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
void recursivereverse(struct node **headref)
{

	struct node* newone;
        struct node* newtwo=NULL;
//      struct node* newthree=NULL;
	if(*headref==NULL)
	{
//		*headref=newtwo;
		return;
	}
	newone=*headref;
	newtwo=newone->next;
	//newone->next=newtwo;
	//newthree=newone;
	//newone=newtwo;
	//*headref=newthree;
	if(newtwo==NULL) return;
//	printf("%d\n",newtwo->data);
	recursivereverse(&newtwo);
	newone->next->next=newone;
	newone->next=NULL;
	*headref=newtwo;

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
        recursivereverse(&head);
        printf("*after reverse*\n");
        play(head);

}

