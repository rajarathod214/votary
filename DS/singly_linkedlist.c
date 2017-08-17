#include<stdio.h>
#include<stdlib.h>
#include "header.h"

struct emp 
{
	int data;
	struct emp *link;

}*start;


void create()
{
	struct emp *temp,*q;

	temp=(struct emp*)malloc(sizeof(struct emp*));

	printf("\n Enter the emp data:");
	scanf("%d",&temp->data);

	temp->link=NULL;

	if(start==NULL)
		start=temp;
	
	else
	{
		q=start;
		
		while(q->link!=NULL)
		{
			q=q->link;
		}

		q->link=temp;
	}
}


void display()
{
	struct emp *temp;

	temp=start;

	if(temp==NULL)
	{
		printf("\n List is empty \n");
		return;
	}

	else
	{
		while(temp)
		{
			printf("|%d|(%p)|%p|-->",temp->data,temp,temp->link);
			temp=temp->link;
		}
	}

}


struct emp *reverse(struct emp *p)
{
	struct emp *r,*q;

	q=NULL;


	while(p)
	{
		r=p->link;
		p->link=q;
		q=p;
		p=r;
	}
	
return q;
}

struct emp *recursive_reverse(struct emp *p)
{
	struct emp *head;

	if(!p)
		return NULL;

	if(p->link)
	{
		head = recursive_reverse(p->link);
		p->link->link=p;
		p->link=NULL;

		return head;
	}

	else
		return p;

}

void add_node_at_begining()
{
	struct emp *temp;

	if(start==NULL)
	{
		printf("\n List is empty \n");
		return ;
	}

	temp=(struct emp*)malloc(sizeof(struct emp*));
	
	printf("\n Enter the employee data:");
	scanf("%d",&temp->data);

	temp->link=start;
	start=temp;
}


void add_node_after(int position)
{
	struct emp *temp,*q;
	int i;
	
	q=start;

	for(i=0;i<=position;i++)
	{
		q=q->link;
	}

	temp=(struct emp*)malloc(sizeof(struct emp*));

	printf("\n Enter the employee data:");
	scanf("%d",&temp->data);

	temp->link=q->link;
	q->link=temp;

}


void delete_node(int edata)
{
	struct emp * q, *temp;

	if(start->data==edata)
	{
		temp=start;
		start=start->link;
		free(temp);
		return;
	}


	q=start;

	while(q->link->link != NULL)
	{
		if(q->link->data==edata)
		{
			temp=q->link;
			q->link=temp->link;
			free(temp);
			return;
		}

		q=q->link;
	}


	if(q->link->data==edata)
	{
		temp=q->link;
		free(temp);
		q->link=NULL;
		return;
	}

else
	printf("\n Element %d not found \n ",edata);

}



int main()
{
	int choice,i,number,position,edata;

while(1)
{
	printf("\n*******************************************\n");
	printf("\t 1. Create list \n");
	printf("\t 2. Display \n");
	printf("\t 3. Reverse\n");
	printf("\t 4. Reverse using Recursion\n");
	printf("\t 5. Add node at begining\n");
	printf("\t 6. Add node after\n");
	printf("\t 7. Delete a node\n");
	printf("\t 8. Exit \n");
	printf("\n*******************************************\n");

	printf("\n Enter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{
	
	case 1: printf("\n How many node you want:");
		scanf("%d",&number);

		for(i=0;i<number;i++)
		{
			create();
		}
		break;

	case 2: display();
		break;

	case 3: start=reverse(start);
		break;

	case 4: start=recursive_reverse(start);
		break;

	case 5: add_node_at_begining();
		break;

	case 6: printf("\n Enter the position to add the node:");
		scanf("%d",&position);
		add_node_after(position);
		break;
	case 7: printf("\n Enter a data to delete:");
		scanf("%d",&edata);
		delete_node(edata);
		break;

	case 8:exit(0);

	default: printf("\n Please enter correct choice \n");
			
	
	}


}
}
