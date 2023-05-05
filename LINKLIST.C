/*This Program for linked list*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct lklist           	//Structure with typedef
{
	int info;                       //info variable
	struct lklist *next;            //self referential structure
}node;                                  //data type of size structure
void main()
{
	node *head=NULL;                 //pointer head with NULL value
	int choice,item;                 //choice variable and item
	void insert_at_beg(node **,int); //function for insert at beg
	void insert_at_end(node **,int); //function for insert at end
	void traverse(node *);           //function for traverse
	void delete_at_beg(node **);     //function for delete at beg
	void delete_at_end(node **);
	void delete_after(node **);
	void insert_after(node *,int);
	void reverse_list(node **);
	node *search(node *,int);
	clrscr();
	while(1)
	{
	       printf("\n1:Insert at beginning\n2:Insert at End\n3:Traverse\n");
	       printf("4:Delete at beginning\n5:Delete at end\n");
	       printf("6:Insert After\n7:Delete after\n8:Reverse the list\n9:Exit\n");
	       printf("Enter Choice:");
	       scanf("%d",&choice);	//taking choice from user
	       clrscr();
	       switch(choice)
	       {
			case 1:
			printf("Insert Item:");  //taking item from user
			scanf("%d",&item);
			insert_at_beg(&head,item); //calling function for insert at beginning
			break;
			case 2:
			printf("Insert at End:");
			scanf("%d",&item);
			insert_at_end(&head,item);
			break;
			case 3:
			if(head==NULL)
			{
				printf("There is no element in list\n");
			}
			else
			{
				traverse(head);
			}
			break;
			case 4:
			if(head==NULL)
			{
				printf("List is Empty\n");
			}
			else
			{
				delete_at_beg(&head);
				printf("Element deleted successfully\n");
			}
			break;
			case 5:
			if(head==NULL)
			{
				printf("List is empty\n");
			}
			else
			{
				delete_at_end(&head);
				printf("Element Deleted Successfully\n");
			}
			case 6:
			printf("Insert Item After:");  //taking item from user
			scanf("%d",&item);
			insert_after(head,item);
			break;
			case 7:
			if(head==NULL)
			{
				printf("Deletion Not Possible");
			}
			else
			{
				printf("Element of list is:\n");
				traverse(head);
				delete_after(&head);
				printf("Element Deleted Succesfully\n");
				printf("List of element after deletion:\n");
				traverse(head);
			}
			break;
			case 8:
			if(head==NULL)
			{
				printf("Reverse is not possible");
			}
			else
			{       printf("Old list is :\n");
				traverse(head);
				reverse_list(&head);
				printf("List is reverse\n");
				printf("Reversed List is:\n");
				traverse(head);
			}
			break;
			case 9:
			exit(0);

			default:
			printf("Wrong input\n");

	       }
	}
}
void insert_at_beg(node **start,int item)        //defining function
{
	node *temp;                              //pointer temp declare
	temp=(node*)malloc(sizeof(node));        //block created address of node stored in temp
	temp->info=item;                         //storing item to info
	if(*start==NULL)                         //checking condition either head is NULL or not
	{
		temp->next=NULL;                 //next block store address as NULL
	}
	else
	{
		temp->next=*start;               //temp block next contain address of start or head
	}
	*start=temp;                             //head or start  contain temp block address
}
void insert_at_end(node **start,int item)        //Definition of function
{
	node *temp,*loc;                         //declaring pointers
	temp=(node*)malloc(sizeof(node));        //block has been created of size node
	temp->info=item;                         //item will stored in temp block info place
	temp->next=NULL;                         //NULL will assign to temp block next place or address position
	if(*start==NULL)                         //checking condition if start(address) is NULL or Not
	{
		*start=temp;                     //if true then start will contain address of temp

	}
	else
	{
		loc=*start;                      //loc will temporary hold start address
		while(loc->next!=NULL)           //loop for block to check next contain the NULL
		{
			loc=loc->next;
		}
	}
	loc->next=temp;
}
void traverse(node *start)
{
	while(start!=NULL)
	{
		printf("%d\n",start->info);
		start=start->next;
	}
}
void delete_at_beg(node **start)
{
	node *temp;
	temp=*start;
	*start=(*start)->next;
	free(temp);
}
void delete_at_end(node **start)
{
	node *loc,*temp;
	loc=*start;
	if((*start)->next==NULL)	//Checking condition if list contain only one node or element
	{
		temp=*start;		//temp pointer contain address of start
		*start=NULL;		//start pointer contains NULL
	}
	else
	{
		while((loc->next)->next!=NULL)  //checking address at next node or list of upcoming list
		{
			loc=loc->next;
		}
		temp=loc->next;
		loc->next=NULL;
	}
	free(temp);
}
void insert_after(node *start,int item)
{
	node *search(node *,int);
	int place;
	node *temp,*loc;
	printf("Enter Place:");
	scanf("%d",&place);
	loc=search(start,place);
	temp=(node*)malloc(sizeof(node));
	temp->info=item;
	temp->next=loc->next;
	loc->next=temp;
}
node *search(node *strt,int place)
{       int i=1;
	node *loc1;
	loc1=strt;
	while(loc1!=NULL)
	{
		if(i==place)
		{
			return loc1;
		}
		loc1=loc1->next;
		i++;
	}
	return NULL;
}
void delete_after(node **start)
{
	node *search(node *,int);
	node *temp,*loc;
	int place;
	printf("Enter place after which you want to delete :");
	scanf("%d",&place);
	loc=search(*start,place);
	if(loc==NULL)
	{
		printf("Entered place not found");
	}
	else
	{
		temp=loc;
		loc->next=(temp->next)->next;
	}
}
void reverse_list(node **start)
{
	node *temp,*loc;
	loc=*start;
	temp=loc->next;
	loc->next=NULL;
	while(temp!=NULL)
	{
		loc=temp;
		temp=temp->next;
		loc->next=*start;
		*start=loc;
	}
}




