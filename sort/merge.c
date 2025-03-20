#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=0;
    int c[h-l+1];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=a[j++];
        }
    }
     while(i <= mid)
        c[k++] = a[i++];
     while(j <= h)
        c[k++] = a[j++];
        for(i=l,k=0;i<=h;i++,k++)
        {
            a[i]=c[k];
        }
}
void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
       int mid=(l+h)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,mid,h);
    }
}
int main()
{
    int n=8,i;
    int a[n];
    
    printf("enter the array:");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("after sortig");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}