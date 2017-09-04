#include<stdio.h>
#include<stdlib.h>

#define BUF_SIZE 100

int array[BUF_SIZE], top=-1;


void push(int x)
{
	if(top==BUF_SIZE-1)
	{
		printf("\n Stack s overflow \n");
	}


	array[++top]=x;
}


void pop()
{
	if(top==-1)
	{
		printf("\n ERROR: No element to pop \n");
	}

	printf("\n array[%d]=%d element deleted\n",top,array[top]);
	top--;

	
}


void isempty()
{
	if(top==-1)
		printf("\n Stack is empty \n");
	else
		printf("\n Stack is not empty\n");

}

void display()
{
	int i;

	if(top==-1)
		isempty();
	
	else
	{
		printf("\n\t *******Stack Display******* \t\n");

		for(i=top;i>=0;i--)
		{
			printf("%3d\n",array[i]);

		}	

	}
}



int main()
{
	
	int choice,i,number,count;


	while(1)
	{
		printf("\n *********************************************************\n");
		printf("\n\t 1] Push\n\t 2] Pop\n\t 3] Isempty\n\t 4] Display\n\t 5] Exit\n");
		
		printf("\n Enter your choice:");
		scanf("%d",&choice);


		switch(choice)
		{
		
		case 1: printf("\n How many element you want to insert:");
			scanf("%d",&count);

			for(i=0;i<count;i++)
			{
				printf("\n Enter the %d number:",i);
				scanf("%d",&number);

				push(number);
			}
			printf("\n *********************************************************\n");
			break;

		case 2: pop();
			printf("\n *********************************************************\n");
			break;


		case 3: isempty();	
			printf("\n *********************************************************\n");
			break;

		case 4: display();
			printf("\n *********************************************************\n");
			break;

		default:
			printf("\n *********************************************************\n");
			exit(0);

		}			
	

	}

}
