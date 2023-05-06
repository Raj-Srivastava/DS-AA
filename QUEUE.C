#define MAX 10
#include<stdio.h>
#include<conio.h>
typedef struct queuetype
{
	int a[MAX];
	int front,rear;
}Queue;
void main()
{
	Queue Q;
	int item,choice,i;
	int isunderflow(Queue);
	int isoverflow(Queue);
	void enqueue(Queue *,int);
	int dequeue(Queue *);
	Q.front=Q.rear=-1;
	while(1)
	{
		printf("1:Enqueue\n2:Dequeue\n3:Exit\n");
		printf("Enter Your choice:");
		scanf("%d",&choice);
		clrscr();
		switch(choice)
		{
			case 1:
			if(isoverflow(Q))
			{
				printf("Queue is overflow\n");
			}
			else
			{
				printf("Enter item you want to enter:");
				scanf("%d",&item);
				enqueue(&Q,item);
				printf("Element Inserted Succesfully\n");
			}
			break;
			case 2:
			if(isunderflow(Q))
			{
				printf("Queue  have no element\n");
			}
			else
			{
				for(i=Q.front;i<=Q.rear;i++)
				{
					printf("%d\n",Q.a[i]);
				}
				item=dequeue(&Q);
				printf("The Item deleted from queue is %d\n",item);
				for(i=Q.front;i<=Q.rear;i++)
				{
					printf("%d\n",Q.a[i]);
				}
			}
			break;
			case 3:
			exit();
			default:
			printf("You have entered wrong choice\n");
		}
	}
}
int isunderflow(Queue Q)
{
	if(Q.front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isoverflow(Queue Q)
{
	if((Q.front==0)&&(Q.rear==MAX-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(Queue *Q,int item)
{
	int i;
	if(Q->front==-1)
	{
		Q->front=0;
		Q->rear=0;
	}
	else if(Q->rear<MAX-1)
	{
		Q->rear=Q->rear+1;
	}
	else
	{
		for(i=Q->front;i<=Q->rear;i++)
		{
			Q->a[i-(Q->front)]=Q->a[i];
		}
		Q->rear=(Q->rear)-(Q->front);
		Q->front=0;
		Q->rear=Q->rear+1;
	}
	Q->a[Q->rear]=item;
}
int dequeue(Queue *Q)
{
	int item;
	item=Q->a[Q->front];
	if(Q->front==Q->rear)
	{
		Q->front=Q->rear=-1;
	}
	else
	{
		Q->front=Q->front+1;
	}
	return item;
}