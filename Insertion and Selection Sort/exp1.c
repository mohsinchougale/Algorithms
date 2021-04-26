#include <stdio.h>

void print(int a[], int n)
{
  for (int i = 0; i < n; i++ )
  {
    printf("%d", a[i]);
  }

}

int insertion_sort(int stack[], int size)
{
  int i,key;
  for(int j = 1; j<size; j++)
  {
    key = stack[j];
    i = j-1;

    while(i > -1 && stack[i] > key)
    {
      stack[i+1] = stack[i];
      i--;
    }
    stack[i+1] = key;

  }

  return 0;
}


int main()
{
  int n;
  printf("Enter no. of alphabets: ");
  scanf("%d",&n);

  int frequency[n];
  printf("Frequency of each alphabet: ");
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &frequency[i]);
  }

  int k;
  printf("No. of keys: ");
  scanf("%d", &k);

  int keySize[k];
  int sum = 0;
  printf("No. of letters per key: ");
  for(int i = 0; i < k; i++)
  {
    scanf("%d", &keySize[i]);
    sum+= keySize[i];
  }

  if(n > sum)
  {
    printf("-1");
    return 0;
  }


  else
  {

    insertion_sort(frequency,n);
    insertion_sort(keySize,k);

    int matrix[k][keySize[k-1]];
    int counter = n-1;
    for(int j = 0; j<keySize[k-1]; j++)
    {
      for(int i = 0; i<k; i++)

      {
        if(j>=keySize[i])
        {
          matrix[i][j] = 0;
          continue;
        }

        matrix[i][j] = frequency[counter];
        counter--;
        if (counter<-1)
        {
          matrix[i][j] = 0;
        }
      }
    }

    int sum = 0,element;
    for (int i = 0; i<k; i++)
    {
      for(int j =0; j<keySize[k-1]; j++)
      {
        element = matrix[i][j];
        sum+=(j+1)*element;
      }
    }
    printf("\n");
    printf("\n");
    printf("Total sum is: %d\n",sum);

  }
}
