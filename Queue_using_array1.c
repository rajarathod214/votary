#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX 30

int array[MAX],front=0,rear=0;

void enqueue(int x)
{
	if(rear==MAX)
	{
		printf("\n Overflow \n");
	}

	else
	{
		array[rear++]=x;
	}

}

void dequeue()
{
	if(rear==front)
	{
		printf("\n Underflow \n");
	}

	else
	{
		front++;
	}

}

void display()
{
	int i;

	if(front==rear)
	{
		printf("\n Queue is empty \n");
	}

	else
	{
		printf("\n");

		for(i=front;i<rear;i++)
		{
			printf("%d\n",array[i]);
		}
	}

}


int main()
{
        int choice, i, count, number;

while(1)
{

        printf("\n ************************************************************************ \n");
        printf("\t 1] Enqueue\n\t 2] Dequeue\n\t 3] Display\n\t 4] Exit");
        printf("\n ************************************************************************ \n");

        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1: printf("\n How many element you want to insert :");
                scanf("%d",&count);

                for(i=0;i<count;i++)
                {
                        printf(" %d element :",i);
                        scanf("%d",&number);
                        enqueue(number);
                }
                printf("\n ************************************************************************ \n");

                break;


        case 2: dequeue();
                printf("\n ************************************************************************ \n");
                break;


        case 3: display();
                printf("\n ************************************************************************ \n");
                break;


        case 4:
                printf("\n ************************************************************************ \n");
                exit(0);


        }
}
}
   
