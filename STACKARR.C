//This Program to implement stack using array
#include<stdio.h>
#include<conio.h>
#define MAX 10
typedef struct stacktype	//defining structure using typedef
{
	int a[MAX];             //Array declaration
	int top;                //Top contain stack top element
}STACK;
void main()
{
	int ch,item,i;
	STACK s;                   //structure variable
	int is_overflow(STACK);    //function overflow
	int is_underflow(STACK);   //function underflow
	void push(STACK *,int);    //function push
	int pop(STACK *);          //function pop
	int peep(STACK);           //function peep
	s.top=-1;                  //stack at top -1
	while(1)
	{
		printf("1:Push\n2:Pop\n3:Peep\n4:Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		clrscr();
		switch(ch)
		{
			case 1:
			item=0;
			if(is_overflow(s))
			{
				printf("Stack is overflow\n");
			}
			else
			{
				printf("Enter Item:");
				scanf("%d",&item);
				push(&s,item);
			}
			break;
			case 2:
			item=0;
			if(is_underflow(s))
			{
				printf("Stack has No element\n");
			}
			else
			{
				for(i=0;i<=s.top;i++)
				{
					printf("%d\n",s.a[i]);
				}
				item=pop(&s);
				printf("Element at top of the stack : %d\n",item);
				printf("Element At top of the stack deleted\n");
				for(i=0;i<=s.top;i++)
				{
					printf("%d\n",s.a[i]);
				}
			}
			break;
			case 3:
			item=0;
			item=peep(s);
			printf("Element at TOP : %d\n",item);
			break;
			case 4:
			exit();
			default:
			printf("Wrong Choice Entered\n");
		}
	}
}
int is_overflow(STACK s)
{
	if((s.top)==MAX-1)        //when stack at top is max-1
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int is_underflow(STACK s)
{
	if(s.top==-1)             //if top of stack is -1
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int peep(STACK s)
{
	return s.a[s.top];       //return top of stack value
}
void push(STACK *stk ,int item)
{
	stk->top=stk->top+1;      //increment the top of stack index
	stk->a[stk->top]=item;    //insert element at top of stack
}
int pop(STACK *stk)
{
	int item;
	item=stk->a[stk->top];      //taking top of stack element into item
	stk->top=stk->top-1;        //decrementing top of stack index
	return item;                //return item
}
