#include<stdio.h>
void heapify(int a[],int n,int i)
{
    int temp,max,lc,rc;
    max=i;
    lc=(2*i)+1;
    rc=(2*i)+2;
    if(lc<=n && a[lc]>a[max])
    {
        max=lc;
    }
    if(rc<=n && a[rc]>a[max])
    {
        max=rc;
    }
    if(max!=i)
    {
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
        heapify(a,n,max);
    }
}
void heapsort(int a[],int n)
{
    int temp,i;
    for(i=(n/2)-1;i>=0;i--)
    {
        heapify(a,n,i);//building the max heap
    }
    for(i=n-1;i>=0;i--)//deletin the root by exchanging the least leaf node
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i-1,0);
    }
}
int main()
{
 int n,a[10],i;
 printf("enter array size:");
 scanf("%d",&n);
 printf("enter array elements:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("before sorting:");
 {
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
 }
 heapsort(a,n);
 printf("\nafter sorting:");
 {
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
 }
 return 0;
}
