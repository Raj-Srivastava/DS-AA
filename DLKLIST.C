/*This Program is for doubly linked list*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct dlklist
{
	struct dlklist *prev;
	int info;
	struct dlklist *next;
}node;
void main()
{
	node *head=NULL,*tail=NULL;
	int choice,item;
	void insert_at_beg(node **,node **,int);
	void insert_at_end(node **,node **,int);
	void insert_after(node **,node **,int);
	void insert_before(node **,int);
	void traverse(node *);
	void delete_at_beg(node **,node **);
	void delete_at_end(node **,node **);
	void delete_after(node **,node **);
	void delete_before(node **);
	node *search(node *,int);
	while(1)
	{
		printf("\n1:Insert At Beginning\n2:Insert At End\n3:Insert After\n");
		printf("4:Insert Before\n5:Traverse\n6:Delete At Beginning\n");
		printf("7:Delete At End\n8:Delete After\n9:Delete Before\n");
		printf("10:Traverse Reverse\n11:Exit\n");
		printf("Enter Choice:");
		scanf("%d",&choice);
		clrscr();
		printf("---------------------------------------------------\n");
		switch(choice)
		{
			case 1:
			printf("Enter Element You Want to Enter:");
			scanf("%d",&item);
			insert_at_beg(&head,&tail,item);
			break;
			case 2:
			printf("Enter Element You Want to Enter:");
			scanf("%d",&item);
			insert_at_end(&head,&tail,item);
			break;
			case 3:
			printf("Enter Element You Want to Enter After:");
			scanf("%d",&item);
			insert_after(&head,&tail,item);
			break;
			case 4:
			printf("Enter Element you want to Enter:");
			scanf("%d",&item);
			insert_before(&head,item);
			break;
			case 5:
			traverse(head);
			break;
			case 6:
			if(head==NULL)
			{
				printf("Deletion is Not possible\n");
			}
			else
			{
				delete_at_beg(&head,&tail);
				printf("Element Deleted Succesfully");
			}
			break;
			case 7:
			if(head==NULL)
			{
				printf("Deletion is Not possible\n");
			}
			else
			{
				delete_at_end(&head,&tail);
				printf("E;ement Deleted Succesfully");
			}
			break;
			case 8:
			if(head==NULL)
			{
				printf("Deletion is not possible");
			}
			else
			{
				printf("List of Element is:\n");
				traverse(head);
				delete_after(&head,&tail);
				printf("Element Deleted Succesfully\n:");
				printf("New List\n");
				traverse(head);
			}
			break;
			case 9:
			if(head==NULL)
			{
				printf("Deletion is not possible");
			}
			else
			{
				printf("List of Element is:\n");
				traverse(head);
				delete_before(&head);
				printf("Element Deleted Succesfully\n:");
				printf("New List\n");
				traverse(head);
			}
			break;
			case 11:
			exit();
			default:
			printf("Entered Choice is incorrect Please Enter Right Choice:\n");
		}
	}
}
void insert_at_beg(node **start,node **end,int item)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=item;
	temp->prev=NULL;
	if(*start==NULL)
	{
		temp->next=NULL;
		*start=temp;
		*end=temp;
	}
	else
	{
		(*start)->prev=temp;
		temp->next=*start;
		*start=temp;
	}
}
void insert_at_end(node **start,node **end,int item)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->info=item;
	temp->next=NULL;
	if(*start==NULL)
	{
	   temp->prev=NULL;
	   *start=temp;
	}
	else
	{
	   (*end)->next=temp;
	   temp->prev=*end;
	}
	*end=temp;
}
void insert_after(node **start,node **end,int item)
{
	node *search(node *,int);
	node *temp,*loc;
	int value;
	printf("Enter Value You want after:");
	scanf("%d",&value);
	loc=search(*start,value);
	if(loc==NULL)
	{
		printf("Element Not Found");
	}
	else
	{
		temp=(node*)malloc(sizeof(node));
		temp->info=item;
		temp->prev=loc;
		temp->next=loc->next;
		loc->next=temp;
		if(temp->next==NULL)
		{
			*end=temp;
		}
	}
}
void insert_before(node **start,int item)
{
	node *search(node *,int);
	node *temp,*loc;
	int value;
	printf("Enter Value Before you enter:");
	scanf("%d",&value);
	loc=search(*start,value);
	if(loc==NULL)
	{
		printf("Entered Value is Not found");
	}
	else
	{
		temp=(node*)malloc(sizeof(node));
		temp->info=item;
		if((loc->prev)==NULL)
		{
			temp->next=loc;
			temp->prev=NULL;
			loc->prev=temp;
			*start=temp;
		}
		else
		{
			temp->prev=loc->prev;
			temp->next=loc;
			(loc->prev)->next=temp;
			loc->prev=temp;
		}
	}
}
node *search(node *start,int value)
{
	node *loc;
	loc=start;
	while((loc->next)!=NULL)
	{
		if((loc->info)==value)
		{
			return loc;
		}
		loc=loc->next;
	}
	return NULL;
}
void traverse(node *start)
{
	while(start!=NULL)
	{
		printf("%d\n",start->info);
		start=start->next;
	}
}
void delete_at_beg(node **start,node **end)
{
	node *loc;
	loc=*start;
	if((loc->next)==NULL)
	{
		*start=NULL;
		*end=NULL;
	}
	else
	{
		*start=loc->next;
		(*start)->prev=NULL;
	}
	free(loc);
}
void delete_at_end(node **start,node **end)
{
	node *loc;
	loc=*end;
	if((loc->prev)==NULL)
	{
		*start=NULL;
		*end=NULL;
	}
	else
	{
		*end=loc->prev;
		(loc->prev)->next=NULL;
	}
	free(loc);

}
void delete_after(node **start,node **end)
{
	node *search(node *,int);
	node *temp,*loc;
	int value;
	printf("Enter Element You want to delete after:");
	scanf("%d",&value);
	loc=search(*start,value);
	if(loc==NULL)
	{
		printf("Element Not Found");
	}
	else
	{
		if((loc->next)==NULL)
		{
			printf("Deletion Not possible");
		}
		else
		{
			if((loc->next)->next==NULL)
			{
				*end=loc;
				loc->next=NULL;
				loc=loc->next;
				free(loc);
			}
			else
			{
				temp=loc->next;
				loc->next=temp->next;
				(temp->next)->prev=loc;
			}
		}
	}
	free(temp);
}
void delete_before(node **start)
{
	node *search(node *,int);
	node *temp,*loc;
	int value;
	printf("Enter Element You want to delete before:");
	scanf("%d",&value);
	loc=search(*start,value);
	if(loc==NULL)
	{
		printf("Element Not Found");
	}
	else
	{
		if((loc->prev)==NULL)
		{
			printf("Deletion Not possible");
		}
		else
		{
			if((loc->prev)->prev==NULL)
			{
				*start=loc;
				loc->prev=NULL;
				loc=loc->prev;
				free(loc);
			}
			else
			{
				temp=loc->prev;
				loc->prev=temp->prev;
				(temp->prev)->next=loc;
			}
		}
	}
	free(temp);
}
