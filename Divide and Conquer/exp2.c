#include <stdio.h>
#include<stdlib.h>
int min;
int RMaxMin(int *A, int i, int j)
{
  int mid, min1;
  if(i == j)
    min = i;
  else if(i == j - 1)
  {
    if(A[j] < A[i])
      min = j;
    else
      min = i;
  }
  else
  {
    mid = (i + j)/2;
    RMaxMin(A, mid+1, j);
    min1 = min;
    RMaxMin(A, i, mid);
    if(A[min1] < A[min])
      min = min1;
  }
}

void delete(int *A, int index, int n)
{
  for (int i = index; i < n; i++)
  A[i] = A[i+1];
}

void One_Sized_Game(int *A, int n)
{
  while(n > 1)
  {
    RMaxMin(A, 1, n);
    for (int i = 1; i <= n; i++)
    {
      A[i] = A[i] - min;
      if(A[i] < 0)
      {
        delete(A, i, n);
        n--;
        i--;
      }
    }
  }

  if(n == 1)
    printf("Ladia\n");
  else
    printf("Kushagra\n");
}
int main()
{
  int m, n;
  scanf ("%d",&m);
  for(int k = 0; k < m; k++)
  {
    scanf ("%d",&n);
    int A[n+1];
    for (int i = 1; i <= n; i++)
    {
      scanf("%d",&A[i]);
    }
    One_Sized_Game(A, n);
  }

  return 0;
}
