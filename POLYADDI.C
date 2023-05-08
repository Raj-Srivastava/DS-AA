#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct polynomial
{
	int coeff,power;
	struct polynomial *next;
}POLY;
void main()
{
	int c,co,po,t;
	POLY *P1=NULL,*P2=NULL,*P3=NULL;
	void insertion(POLY  **,int,int);
	void traversing(POLY *);
	void addition(POLY **,POLY *,POLY *);
	printf("Enter Polynomial One\n");
	printf("How many terms in one polynomial:");
	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		printf("Enter Coefficient of terms %d : ",c);
		scanf("%d",&co);
		printf("Enter power of term %d : ",c);
		scanf("%d",&po);
		insertion(&P1,co,po);
	}
	printf("Enter Polynomial Two\n");
	printf("How many terms in Second polynomial:");
	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		printf("Enter Coefficient of terms %d : ",c);
		scanf("%d",&co);
		printf("Enter power of term %d : ",c);
		scanf("%d",&po);
		insertion(&P2,co,po);
	}
	addition(&P3,P1,P2);
	traversing(P1);
	traversing(P2);
	traversing(P3);
	getch();
}
void insertion(POLY **h,int c,int p)
{
	POLY *temp;
	temp=(POLY*)malloc(sizeof(POLY));
	temp->coeff=c;
	temp->power=p;
	temp->next=*h;
	*h=temp;
}
void addition(POLY **h3,POLY *h1,POLY *h2)
{
	while((h1!=NULL)&&(h2!=NULL))
	{
		if(h1->power==h2->power)
		{
			insertion(h3,h1->coeff+h2->coeff,h1->power);
			h1=h1->next;
			h2=h2->next;
		}
		else if(h1->power>h2->power)
		{
			insertion(h3,h1->coeff,h1->power);
			h1=h1->next;
		}
		else if(h2->power>h1->power)
		{
			insertion(h3,h2->coeff,h2->power);
			h2=h2->next;
		}
	}
}
void traversing(POLY *head1)
{
	while(head1!=NULL)
	{
		printf("%d x ^ %d +",head1->coeff,head1->power);
		head1=head1->next;
	}
}
void sort(POLY **head1)
{
	POLY *loc;
	loc=*head1;
	while(loc!=NULL)
	{
		if((loc->power)>(loc->next)->power)
		{

		}
	}
}