#include<stdio.h>
void insert(int a[],int n)
{
int i,j,temp;
 for(i=1;i<n;i++)
 {
   j=i-1;
   temp=a[i];
   while(j>=0 && a[i]>temp)
   {
     a[j+1]=a[j];
     j--;
   }
   a[j+1]=temp;
 }
}
void print(int a[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
  printf("%d ",a[i]);
 }
}
int main()
{
 int n,a[n];
 printf("enter array size:");
 scanf("%d",&n);
 printf("enter array elements:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("before sorting:");
 print(a,n);
 insert(a,n);
 printf("after sorting:");
 print(a,n);
 return 0;
}
