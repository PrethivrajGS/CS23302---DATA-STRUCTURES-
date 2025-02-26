#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a,j,j+1);
            }
        }
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
    bubblesort(a,n-1);
    printf("after sorting");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}