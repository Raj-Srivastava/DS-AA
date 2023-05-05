//This Program for linear search
#include<stdio.h>
#include<conio.h>
#define size 10
void main()
{
int a[size],item,index;
void input_array(int [],int);
int linear_search(int [],int,int);
clrscr();
input_array(a,size);
printf("Enter Number You want to Search:");
scanf("%d",&item);
index=linear_search(a,size,item);
if(index<size)
{
printf("%d Element at index %d",item,index+1);
}
else
{
printf("Element Not Found");
}
getch();
}
void input_array(int a[],int m)
{
int i;
for(i=0;i<m;i++)
{
printf("Enter Element at %d:",i+1);
scanf("%d",&a[i]);
}
}
int linear_search(int a[],int m,int item)
{
int i;
for(i=0;i<m;i++)
{
if(item==a[i])
{
return i;
}
}
return i;
}