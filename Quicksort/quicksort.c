#include <stdio.h>
#include <stdlib.h>

void printarray(int A[],int num)
{   printf("\n");
    for(int i=0;i<num;i++)
    printf("%d ",A[i]);

}

void exchange(int *p,int *q)
{
    int temp=(*p);
         (*p)=(*q);
         (*q)=temp;

}
int partition(int A[],int p,int r)
{
    int x=A[r];
    printf("\nPivot=%d\n",x);
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i=i+1;

            exchange(A+i,A+j);
        }
    }

    exchange(A+i+1,A+r);
    return i+1;
}



void QuickSort(int A[],int p,int r)
{
    if(p<r)
    {
        printf("\npartition(A,%d,%d)",p,r);
        int q=partition(A,p,r);
        printf("\nPartition Array:");
        for(int i=p;i<=r;i++)
           printf("%d ",A[i]);


        printf("\n\nq=%d",q);
        printf("\nQuickSort(A,%d,%d)",p,q-1);
        QuickSort(A,p,q-1);
        printf("\n\nQuickSort(A,%d,%d)",q+1,r);
        QuickSort(A,q+1,r);
    }
}

int main()
{
 int i, num;
 printf ("\nEnter the total number of numbers: ");
 scanf ("%d",&num);  //nos in the array

 int A[num];
 printf ("Enter the numbers : \n");
 for (i=0;i<num;i++)
  scanf("%d",&A[i]);
  printf("\nUnsorted array:");
  printarray(A,num);
  QuickSort(A,0,num-1);
  printf("\n\nSorted array:");
  printarray(A,num);

}
