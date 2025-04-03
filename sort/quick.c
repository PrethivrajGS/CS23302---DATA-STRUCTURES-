#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    while(i<j)
    {
        do{
            i++;
        }while(a[i]<=pivot && i<=h );
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
    }
        swap(&a[l],&a[j]);
        return j;
    
}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}
int main()
{
    
    int a[100],i,n;
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("enter the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("after sorting");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}