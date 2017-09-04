#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct node
{
	int data;
	struct node *next;
};

	struct node *front=NULL;
	struct node *rear=NULL;


void enqueue(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node*));

	temp->data=x;
	temp->next=NULL;

	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
	}	

	else
	{
		rear->next=temp;
		rear=temp;
	}

}

void dequeue()
{
	struct node *temp=front;

	if(front==NULL)
		printf("\n Queue is empty\n");

	if(front==rear)
	{
		front=rear=NULL;
	}

	else
	{
		front=front->next;
	}

	free(temp);
}

void display()
{
	struct node *temp=front;

	if(temp==NULL)
		printf("\n Queue is empty \n");

	else
	{
		while(temp)
		{
			printf(" %3d",temp->data);
			temp=temp->next;
		}
	
	}

	
	
}


int main()
{
	int choice,count,number,i;

	while(1)
	{
		printf("\n ************************************************************ \n");
		printf("\t 1] Enqueue\n\t 2] Dequeue\n\t 3] Display\n\t 4] Exit");
		printf("\n ************************************************************ \n");
		printf("\n Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
		
		case 1: printf("\n How many elements you want to insert:");
			scanf("%d",&count);
			for(i=0;i<count;i++)
			{
				printf("%d element:",i);
				scanf("%d",&number);
				enqueue(number);
			}
			printf("\n ************************************************************ \n");
			break;

		case 2:	dequeue();
			printf("\n ************************************************************ \n");
			break;

		case 3: display();
			printf("\n ************************************************************ \n");
			break;

		case 4: 
			printf("\n ************************************************************ \n");
			exit(0);
		}

	}

}
