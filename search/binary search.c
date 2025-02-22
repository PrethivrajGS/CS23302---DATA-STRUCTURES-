//linear search
#include<stdio.h>
int binary(int a[],int n,int data)
{
    int i,l=1,h=n,mid,flag=0;
    while(l<=h)
    {
         mid=(l+h)/2;
        if(a[mid]==data)
        {
            printf("element found at the index:%d",mid);
            printf("\nposition of the element is:%d",mid+1);
            flag=1;
            break;
        }
        if(a[mid]>data)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(flag==0)
    {
        printf("element not found!");
    }
}
int main()
{
    int a[10],data,i,n;
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("enter the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the data to be found:");
    scanf("%d",&data);
    binary(a,n,data);
}
