#include<stdio.h>
#include<stdlib.h>



struct node{
	int data;
	struct node* next;
};

void build(struct node **head,int i)
{
	struct node* h=NULL;
	h=malloc(sizeof(struct node));
	//h->data=i;
	h->next=*head;
	h->data=i;
	*head=h;
}

/*void pussh(struct node** head)
{
	struct node* temp=NULL;
	temp=malloc(sizeof(struct node));
	temp->next=*head;
	int i;

	for(i=1;i<=5;i++)
	{
		temp->data=i;
		temp->next=temp;
		
	}
	*head=temp;
}*/
void display(struct node* head)
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
	head=malloc(sizeof(struct node));
	build(&head,3);
	build(&head,5);

//	display(head);
//	return(0);
}
