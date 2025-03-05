#include<stdio.h>
void countsort(int a[],int n)
{
    int k=a[0],i;
    for(i=1;i<n;i++)
    {
    if(a[i]>k)
    {
        k=a[i];
    }
    }
   int count[k+1],b[n];
   for(i=0;i<=k;i++)
   {
       count[i]=0;
   }
   for(i=0;i<n;i++)
   {
       ++count[a[i]];// storing the no. of repeated values in the given array as new array.
   }
   for(i=1;i<=k;i++)
   {
       count[i]=count[i]+count[i-1];// adding the current index and previous index
   }
   for(i=n-1;i>=0;i--)
   {
       b[--count[a[i]]]=a[i];// storing the element in the new array b by decrementing one index of count
   }
   for(i=0;i<n;i++)
   {
       a[i]=b[i];//copying b array into array a.
   }
}
int main()
{
    int a[100],n;
    printf("enter n:");
    scanf("%d",&n);
    printf("enter the array:");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    countsort(a,n);
    printf("after sortig:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}