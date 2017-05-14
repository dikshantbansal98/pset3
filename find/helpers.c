
 
#include <cs50.h>

#include "helpers.h"
bool search(int value, int values[], int n)
{
    
    if(n<=0)
    {
        return false;
    }
    int low,upper,mid;
    low=0;upper=n-1;
    while(low<=upper)
    {
        mid=(low+upper)/2;
        if(values[mid]>value)
            upper=mid-1;
      else if(values[mid]<value)
            low=mid+1;
        else
        return true;
    }
    return false;
}


void sort(int values[], int n)
{
    
    int i,j,flag,temp;
    for(i=0;i<=n-1;i++)
    {
        flag=0;
        for(j=0;j<=n-2;j++)
        {
            if(values[j]>values[j+1] )  
            {
                flag=1;
                temp=values[j];      
                values[j]=values[j+1];
                values[j+1]=temp;
            }
        }
        if(flag==0)      
        break;
    }
    return;
}
