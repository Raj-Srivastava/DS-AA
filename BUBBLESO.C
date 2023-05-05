#include<stdio.h>
#include<conio.h>
void main()
{
int arr[10],r;
void input_array(int[10],int);
void bubble_sort(int[10],int);
void output_array(int[10],int);
clrscr();
printf("Enter number of elements:");
scanf("%d",&r);
input_array(arr,r);
bubble_sort(arr,r);
output_array(arr,r);
getch();
}
void input_array(int arr[10],int r)
{
int i;
for(i=0;i<r;i++)
{
printf("Enter %d element:",i+1);
scanf("%d",&arr[i]);
}
}
void bubble_sort(int arr[10],int r)
{
int i,j,temp;
for(i=r-1;i>=0;i--)
{
	for(j=0;j<r;j++)
	{
		if(arr[j]>arr[j+1])
		{
		temp=arr[j+1];
		arr[j+1]=arr[j];
		arr[j]=temp;
		}
	}
}
}
void output_array(int arr[10],int r)
{
int i;
for(i=0;i<r;i++)
{
printf("%d\t",arr[i]);
}
}