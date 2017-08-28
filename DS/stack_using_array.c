#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX_SIZE 100


void push(int);
void pop();
void isempty();
void display();

int array[MAX_SIZE],top=-1;


int main()
{
	int choice,size,number,count,i;

while(1)
{
		printf("\n *********************************************************\n");
	printf("\n \t\t----Stack Operation----\n");
	printf("\t 1] Push 2] Pop 3] isempty 4] Display 5] Exit \n");
	printf("\n Enter your choice:");
	scanf("%d",&choice);

	switch(choice)
	{

	case 1: printf("\n How many element you want to push into the stack : ");
		scanf("%d",&count);

		for(i=0;i<count;i++)
		{
			printf("\n Enter %d number to insert:",i);
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

return 0;
}



void push(int x)
{
	if(top==MAX_SIZE - 1)
	{
		printf("\n Stack overflow \n");
	
	}


	array[++top]=x;

}


void isempty()
{
	if(top==-1)
		printf("\n Stack is empty \n");

	else
		printf("\n Stack is not empty \n");


}



void pop()
{
	if(top==-1)
	{
		printf("\n Error: No element to pop\n");
	}

	top--;

}

void display()
{
	int i;

	printf("\n Stack:\n");

	for(i=top;i>=0;i--)
	{
		printf("%d",array[i]);
		printf("\n");
	}

}
