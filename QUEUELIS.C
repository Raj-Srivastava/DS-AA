#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct Queue
{
	int data;
	struct Queue *next;
}QUEUE;
void main()
{
	QUEUE *head=NULL;
	int ch,item;
	void enqueue(QUEUE **,int);
	void dequeue(QUEUE **);
	void newp(QUEUE *);
	while(1)
	{
		printf("1:Enqueue\n2:Dequeue\n3:exit\n");
		scanf("%d",&ch);
		clrscr();
		switch(ch)
		{
			case 1:
			printf("Enter Data:");
			scanf("%d",&item);
			enqueue(&head,item);
			newp(head);
			break;
			case 2:
			dequeue(&head);
			newp(head);
			break;
			case 3:
			exit();
			default:
			printf("Wrong choice\n");
			break;
		}
	}
}
void enqueue(QUEUE **start,int item)
{
	QUEUE *temp,*loc;
	temp=(QUEUE*)malloc(sizeof(QUEUE));
	temp->data=item;
	temp->next=NULL;
	loc=*start;
	if(loc==NULL)
	{
		*start=temp;
	}
	else
	{
		while(loc->next!=NULL)
		{
			loc=loc->next;
		}
		loc->next=temp;
	}
}
void dequeue(QUEUE **start)
{
	QUEUE *loc;
	loc=*start;
	if(*start==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		loc=*start;
		*start=(*start)->next;
	}
	free(loc);
}
void newp(QUEUE *start)
{
	while(start!=NULL)
	{
		printf("%d\n",start->data);
		start=start->next;
	}
}