#include<stdio.h>
#include<stdlib.h>


struct node{
        int data;
        struct node* next;
};

void display(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}
struct node* count()
{
	int cnt=0;
	struct node vk;
	struct node *countval=&vk;
	//countval=malloc(sizeof(struct node));
	//countval=head;
	vk.next=NULL;
	while(countval!=NULL)
	{
		cnt=cnt+1;
		countval=countval->next;
	}
	if(countval==NULL)
	{
		printf("nbr of cnt:%d\n",cnt);
	}
return(vk.next);
}

void delet(struct node **head, int d)
{
	struct node *del;
	del=malloc(sizeof(struct node));
	int tmp;
	tmp=d;
	//del->next=*head;
	if(d==5)
	{
		//det->data=(del->data->data);
		//*head=del;
		del->data=9;
		del->next=*head;
		*head=del;
	}
	else
	{

		del->data=d;
		del->next=*head;
		*head=del;
	}
}

void rearng(struct node **head,int p)
{
	struct node* tep;
	//struct node* tt;
	//tep=malloc(sizeof(struct node));
	//tt=malloc(sizeof(struct node));
	//tt=h;
	while((*head)!=NULL)
	{
		if(p==9)
		{

			tep->data=1;
			tep->next=*head;
			*head=tep;
		}
		else
		{
			tep=*head;
			tep->next=*head;
			*head=tep;
		}
	}
	*head=NULL;
}



int main()
{
	struct node* head;
	int i;
	head=NULL;
	for(i=1;i<=12;i++)
	{
		delet(&head,i);
	}
	delet(&(head->next->next),5);
	//rearng(&head,9);
	display(head);
        count(head);
	return(0);
}

