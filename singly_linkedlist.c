#include<stdio.h>
#include<stdlib.h>
#include "header.h"

struct emp 
{
	int data;
	struct emp *link;

}*start;

/**************************************** Creation of Nodes ******************************************/
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

/**************************************** Display of Nodes ******************************************/

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
		//	printf("|%d|(%d)|%d|-->",temp->data,temp,temp->link);
			printf("%d-->",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}

}

/**************************************** Reversing node  ******************************************/


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
/**************************************** Reverse with recursion **************************************/

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

/**************************************** Add Node at begining ******************************************/

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

/**************************************** Add node after given position *********************************/

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


/**************************************** Deletion of Nodes ******************************************/
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

/****************************************  Find Nth node from last ****************************************/

void find_nth_node_from_last(int pos1)
{
	struct emp *temp=start,*nthnode=NULL;
	int count;
	if(temp==NULL)
	{
		printf("\n List is empty \n");
		return;
	}
	
	for(count=1;count<pos1;count++)
	{
		temp=temp->link;
	}


	while(temp)
	{
		if(nthnode==NULL)
			nthnode=start;
		else
			nthnode=nthnode->link;

		temp=temp->link;
	}


	if(nthnode)
		printf("\n THe %d node form last is [%d(%p)|%p]\n",pos1,nthnode->data,nthnode,nthnode->link);
	else
		printf("\n Less than %d node \n",pos1);
	
	
}

/**************************************** Total Number of nodes **************************************/

int total_node()
{
	struct emp *temp=start;
	int count=0;


	if(temp==NULL)
	{
		printf("\n List is empty\n");
		return 0 ;
	}

	while(temp)
	{
		temp=temp->link;
		count++;
	}
	

	printf("\n Total node = %d \n",count);
	
	return count;	
}

/**************************************** Find node position from first ***********************************/

void find_position_from_first(int edata)
{
	struct emp *temp=start;
	int count=0,flag=0;

	if(temp==NULL)
	{
		printf("\n List is empty \n");
		return;
	}


	while(temp)
	{	
		count++;
		if(temp->data==edata)
		{
			flag=1;
			printf("\n %d found at %d position \n",edata, count);
		}

		temp=temp->link;
	}


	if(flag==0)
		printf("\n No %d data found \n",edata);
}

/**************************************** Sorting in asending ************************/

struct emp* asending_order()
{
	struct emp *temp=start;
	
	int temp1,count=0,i,j;
	
//	count=total_node();
	printf("cnt:%d\n",count);
	if(temp==NULL)
	{
		printf("\n List is empty \n");
		return NULL;
	}

	/* Total node count */

	while(temp)
	{
			count++;
		temp=temp->link;
	}

	printf("\n count = %d \n",count);

	temp=start;


	for(i=0;i<count;i++)
	{
		for(j=0;j<count-i;j++)
		{
			if(temp->link != NULL)
			if((temp->data)>(temp->link->data))
			{
				temp1=temp->data;
				temp->data=temp->link->data;
				temp->link->data=temp1;
			}
			
			temp=temp->link;
		}// End of j loop (outer)
		
		temp=start;
	}//End of i loop (inner)

//	return temp;

}

/**************************************** Delete a middle node* ************************/

void delete_middle_node()
{
	struct emp *temp=start,*temp1,*p,*q;
//	int count=0,i;


	if(temp==NULL)
	{
		printf("\n List is empty \n");
		return;
	}
	
	else if(temp->link == NULL)
		{
			printf("\n Only one node is present \n");
			return;
		}


	p=q=start;	


	while((q->link != NULL)&&(q->link->link!=NULL))
	{
		temp1=p;
		p=p->link;
		q=q->link->link;
	}

	temp1->link=p->link;
	free(p);
	p=NULL;
	


/*
	while(temp)
	{
		temp=temp->link;
		count++;
	}

	
	temp=start;

	for(i=1;i<(count/2);i++)
	{
		temp=temp->link;
		printf("\n %d\t\n ",temp);
	}

	
		temp1=temp->link;
		temp->link=temp->link->link;
		temp=temp->link;
		free(temp1);

	
*/
}



 
/**************************************** Main function ********************************/

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
	printf("\t 8. Find Nth node from last\n ");
	printf("\t 9. Total nodes\n ");
	printf("\t 10.find_position_from_first\n ");
	printf("\t 11.Asending_order\n");
	printf("\t 12.Delete a middle node \n");
	printf("\t 13.Exit \n");
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


	case 8: printf("\n Enter the position from last:");
		scanf("%d",&position);
		find_nth_node_from_last(position);		
		break;

	case 9: total_node();
		break;

	case 10:printf("\n Enter the data to search:");
		scanf("%d",&edata); 
		find_position_from_first(edata);
		break;
	
	case 11:asending_order();
		 break;
	
	case 12:delete_middle_node();
		 break;

	case 13: exit(0);

	default: printf("\n Please enter correct choice \n");
			
	
	}

}
}
