#include<stdio.h>
#include<stdlib.h>
#include "header.h"
struct cll
{
	int info;
	struct cll *link;
}*last;


void create(int number)
{
	struct cll *temp,*q;
	
	temp=(struct cll*)malloc(sizeof(struct cll));

	temp->info=number;

	if(last==NULL)
	{
		last=temp;
		last->link=temp;
	}


	else
	{
		temp->link=last->link;
		last->link=temp;
		last=temp;
	}
}


void add_at_begining(int number)
{
	struct cll *temp;

	temp=(struct cll*)malloc(sizeof(struct cll));

	temp->info=number;
	temp->link=last->link;
	last->link=temp;
}

void add_after(int number, int position)
{
	struct cll *temp, *q;
	int i;

	q=last->link;

	for(i=0;i<position-1;i++)
	{
		q=q->link;

		if(q==last->link)
		{
			printf("\n There are less than %d element \n",position);
			return;
		}
	}
		

	temp=(struct cll*)malloc(sizeof(struct cll));
	temp->info=number;
	temp->link=q->link;
	q->link=temp;

	if(q==last) /* Element inserted at the end */
	last=temp;
}


void delete(int number)
{
	struct cll *temp,*q;

	if(last->link==last && last->info==number)  /* Only one element */
	{
		temp=last;
		last=NULL;
		free(temp);
		return;
	}

	q=last->link;

	if(q->info==number)
	{
		temp=q;
		last->link=q->link;
		free(temp);
		return;
	}

	while(q->link != last)
	{
		if(q->link->info==number) /* Element deleted inbetween*/
		{
			temp=q->link;
			q->link=temp->link;
			free(temp);
			printf("\n %d deleted \n",number);
			return;
		}

		q=q->link;
	}

	if(q->link->info==number)
	{
		temp=q->link;
		q->link=last->link;
		free(temp);
		last=q;
		
		return;
	}

	printf("\n Element %d not found \n",number);
}

void display()
{
	struct cll *temp;
	
	temp=last;

	if(last==NULL)
	{
		printf("\n List is empty\n");
		return;
	}

	temp=last->link;
	printf("\n The data in the list is:\n");

	while(temp != last)
	{
		printf("|%d(%p)|%p|-->",temp->info,temp,temp->link);
		temp=temp->link;
	}

		printf("|%d(%p)|%p|-->",last->info,last,last->link);

}

int main()
{
	int i, choice, number,count,position;

	
while(1)
{
	printf("\n\t*******circular linked list **********\n");
	printf("\n\t 1] create list \n\t 2] Add at begining \n\t 3] Add after \n\t 4] Delete \n\t 5] Display \n\t 6] Exit\n");
	printf("\t**********************************************\n");

	printf("\n Enter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{
	
	case 1: printf("\n How many node you want to create:");
		scanf("%d",&count);

		for(i=0;i<count;i++)
		{
			printf("\n Enter %d data:",i+1);
			scanf("%d",&number);
			create(number);
		}

		break;

	case 2: if(last==NULL)
		{
			printf("\n List is empty \n");
		}

		else
		{
			printf("\n Enter the informaton:");
			scanf("%d",&number);
			add_at_begining(number);
		}

		break;

	case 3: if(last==NULL)
		{
			printf("\n List is empty \n");
		}

		else
		{
			printf("\n Enter the information:");
			scanf("%d",&number);
			printf("\n Enter the position:");
			scanf("%d",&position);
			add_after(number,position);
		}

		break;

	case 4: if(last==NULL)
		{
			printf("\n List is empty \n");
		}
		else
		{
			printf("\n Enter the data to delete:");
			scanf("%d",&number);
			delete(number);
		}

		break;

	case 5: display();
		break;

	case 6: exit(0);
	}
	
	
}
}
