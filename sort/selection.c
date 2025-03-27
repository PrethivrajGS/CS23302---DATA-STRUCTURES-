#include<stdio.h>
int smallest(int a[],int k,int n)
{
    int pos=k,i,small=a[k];
    for(i=k+1;i<n;i++)
    {
        if(a[i]<small)
        {
            small=a[i];
            pos=i;
        }
    }return pos;
}
void selectionsort(int a[],int n)
{
    int k,pos,temp;
    for(k=0;k<n;k++)
    {
        pos=smallest(a,k,n);
        temp=a[k];
        a[k]=a[pos];
        a[pos]=temp;
    }
}int main()
{
 int n,a[100],i;
 printf("enter array size:");
 scanf("%d",&n);
 printf("enter array elements:");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 
 selectionsort(a,n);
 printf("\nafter sorting:");
 for(i=0;i<n;i++)
 {
     printf("%d ",a[i]);
 }