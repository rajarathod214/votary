#include<stdio.h>
#include<stdlib.h>
#include "header.h"

struct dll
{
	struct dll *prev;
	int info;
	struct dll *next;
}*head;


void create_list(int number)
{
	struct dll *temp, *q;

	temp=(struct dll*)malloc(sizeof(struct dll));

	temp->info=number;
	temp->next=NULL;

	if(head==NULL)
	{
		temp->prev=NULL;
		head=temp;
	}

	else
	{	
		q=head;
		while(q->next != NULL)
		{
			q=q->next;
		}

		q->next=temp;
		temp->prev=q;
	}

}

void display()
{
	struct dll *temp;
	
	temp=head;	

	if(head==NULL)
	{
		printf("\n List is empty \n");
		return;
	}

	else
	{
		while(temp)
		{
			printf("|%p|%d|%p|<-->",temp->prev,temp->info,temp->next);
			temp=temp->next;
		}
	}

}



void add_at_begining(int number)
{
	struct dll *temp;

	temp=(struct dll*)malloc(sizeof(struct dll));

		 
	temp->info=number;
	temp->prev=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
}


void add_after(int number, int position)
{
	struct dll *temp, *q;
	int i;

	q=head;

	for(i=0;i<position-1;i++)
	{
		q=q->next;
		
		if(q==NULL)
		{
			printf("\n There are less than %d elements \n",position);
			return;
		}
	}


	temp=(struct dll*)malloc(sizeof(struct dll));
	
	temp->info=number;

	q->next->prev=temp;
	temp->next=q->next;
	temp->prev=q;
	q->next=temp;
}


void Delete(int num)
{
	struct dll *temp,*q;
	
	if(head->info==num)
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		return;
	}

	q=head;

	while(q->next->next !=NULL )
	{
		if(q->next->info==num)
		{
			temp=q->next;
			q->next=temp->next;
			temp->next->prev=q;
			free(temp);
			return;
		}

		q=q->next;
	}


	if(q->next->info==num)
	{
		temp=q->next;
		free(temp);
		q->next=NULL;
		return;
	}

	printf("\n %d element not found \n",num);
	
}


int main()
{
	int choice, number,i,position,count;
while(1)
{
	printf("\n\t***** Doubly Link List *****\n");
	printf("\t 1. Create List\n");
	printf("\t 2. Insert Node at beginng\n");
	printf("\t 3. Insert node after position \n");
	printf("\t 4. Delete node\n");
	printf("\t 5. Display \n");
	
	printf("\t 6. Exit\n");
	printf("\t*********************************\n");


	printf("\n Enter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{
	
	case 1: printf("\n How many node you want:");
		scanf("%d",&count);

		for(i=0;i<count;i++)
		{
			printf("\n Enter %d node = ",i+1);
			scanf("%d",&number);
			create_list(number);
		}
	
		break;

	case 2: if(head==NULL)
			printf("\n list is empty\n");
		else
		{
			printf("\n Enter number to insert:");
			scanf("%d",&number);
			add_at_begining(number);
		}
		break;


	case 3:if(head==NULL)
			printf("\n List is empty \n");
		else
		{
			printf("\n Enter number to insert:");
			scanf("%d",&number);
			printf("\n Enter the position:");
			scanf("%d",&position);
			add_after(number,position);
		}
		break;
	
	case 4: printf("\n Enter the information to delete:");
		scanf("%d",&number);
		Delete(number);
		break;

	case 5: display();
		break; 

	default: exit(0);

	}

}
}
