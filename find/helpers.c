/*
 * helpers.c
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"
bool search(int value, int values[], int n)
{
    // implementing binary search
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
            upper=mid-1;         //checking in left half
      else if(values[mid]<value)
            low=mid+1;           //checking in right half
        else
        return true;
    }
    return false;
}


void sort(int values[], int n)
{
    // impplementing modified bubble sort
    int i,j,flag,temp;
    for(i=0;i<=n-1;i++)
    {
        flag=0;
        for(j=0;j<=n-2;j++)
        {
            if(values[j]>values[j+1] )   //comparing term with index j by term with index j+1
            {
                flag=1;
                temp=values[j];      //swapping if term with jth index is greater than term with j+1 index
                values[j]=values[j+1];
                values[j+1]=temp;
            }
        }
        if(flag==0)      // checking if list is sorted already
        break;
    }
    return;
}
