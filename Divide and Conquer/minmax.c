#include<stdio.h>

int max, min;	//declared global variables

int a[100];
void maxmin(int i, int j)
{
  int max1, min1, mid;
  if(i==j)	//if array cotains only 1 element
  {
    printf("Subarray: %d \n\n",a[i]);
    printf("Here %d = %d \n",i,j);
    printf("Therefore Minimum = Maximum = %d \n",a[i]);
    max = min = a[i];
  }
  else
  {
  if(i == j-1)	//if array contains 2 elements
  {
    printf("Subarray: %d %d \n\n",a[i],a[j]);
    if(a[i] <a[j])
    {
      printf(" %d < %d \n",a[i],a[j]);
      printf("Maximum = %d \n",a[j]);
      printf("Minimum = %d \n",a[i]);
      max = a[j];
      min = a[i];
    }
    else
    {
      printf(" %d < %d \n",a[j],a[i]);
      printf("Maximum= %d \n",a[i]);
      printf("Minimum= %d \n",a[j]);
      max = a[i];
      min = a[j];
    }
  }
  else	//array contains more than 2 elements
  {
    mid = (i+j)/2;
    printf("Subarray: ");
    for(int m=i;m<mid;m++)
    {
      printf("%d ",a[m]);
    }
    printf("\n");
    maxmin(i, mid);
    printf("Now Maximum = %d Minimum = %d \n",max,min);
    max1 = max;
    min1 = min;
    printf("Subarray: ");
    for(int m=mid+1;m<j;m++)
    {
      printf("%d ",a[m]);
    }
    printf("\n");
    maxmin(mid+1, j);
    if(max <max1)
    {
      printf("New Maximum = %d \n",max1);
      max = max1;
    }
    if(min > min1)
    {
      printf("New Minimum = %d \n",min1);
      min = min1;
    }
  }
}
}
int main ()
{
  int i, num;
  printf ("\nEnter the size of array: ");
  scanf ("%d",&num);
  printf ("Enter the numbers: \n");
  for (i=1;i<=num;i++)
  {
    scanf ("%d",&a[i]);
  }

  max = a[0];
  min = a[0];
  maxmin(1, num);
  printf ("Minimum element: %d\n", min);
  printf ("Maximum element: %d\n", max); return 0;
}
