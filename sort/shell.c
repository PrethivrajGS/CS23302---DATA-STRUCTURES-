//shell sort
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void shell(int a[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(j=gap;j<n;j++)
        {
            for(i=j-gap;i>=0;i-=gap)
            {
                if(a[i+gap]>a[i])
                {
                    break;
                }
                else
                {
                    swap(&a[i+gap],&a[i]);
                }
            }
        }
    }
}
int main()
{
    int i,n,a[100];
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("enter array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    shell(a,n);
    printf("array after sorting:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}