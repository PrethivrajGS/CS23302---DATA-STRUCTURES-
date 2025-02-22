//linear search
#include<stdio.h>
int linear(int a[],int n,int data)
{
    int flag=0,i;
    for(i=0;i<n;i++)
    {
        if(a[i]==data)
        {
            printf("element found at the index:%d",i);
            printf("\nposition of the element is:%d",i+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("element not found!");
    }
    
}
int main()
{
    int a[10],data,i,n,flag=0;
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("enter the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the data to be found:");
    scanf("%d",&data);
    linear(a,n,data);
}
