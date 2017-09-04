#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



struct node
{
	int data;
	struct node *link;

};

struct node *top=NULL;


void push(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node*));


	temp->data=x;
	temp->link=top;
	top=temp;
}

void pop()
{
	struct node *temp;

	if(top==NULL)
	{
		printf("\n Stack is empty\n");
		return;
	}


	temp=top;
	top=top->link;
	free(temp);
}

void isempty()
{

	if(top==NULL)
	{
		printf("\n Stack is empty \n");
	}

	else
	{
		printf("\n Stack is not empty \n");
	}

	
}	


void display()
{
	struct node *temp=top;

	
	
	if (temp==NULL)
	{
		isempty();
		return;
	}
	
	else
	{
		while(temp)
		{
			printf("\n %d \n",temp->data);
			temp=temp->link;

		}
	

	}

}



int main()
{
	int choice,number,count,i;


	while(1)
	{
		printf("\n *******************************************************\n");
		printf(" \n\t 1] Push\n\t 2] Pop\n\t 3] Isempty\n\t 4] Display\n\t 5] Exit\n");
		printf("\n Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
		
		case 1: printf("\n How many element you want to insert:");
			scanf("%d",&count);

			for(i=1;i<=count;i++)
			{
				printf("\n Enter %d number:",i);
				scanf("%d",&number);
				push(number);
			}
		printf("\n *******************************************************\n");
		break;


		case 2: pop();
			printf("\n *******************************************************\n");
			break;

		case 3: isempty();	
			printf("\n *******************************************************\n");
			break;

		case 4: display();
			printf("\n *******************************************************\n");
			break;

		default:
			printf("\n *******************************************************\n");
			exit(0);
		}	

	}

}
