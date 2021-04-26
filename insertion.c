#include <stdio.h>

# define MAXSIZE 100
int stack[MAXSIZE];

int main()
{
  int size,element,compare = 0,exchange = 0,key,i;

  printf("Enter size of array: ");
  scanf("%d", &size);

   printf("Enter the elements of array: \n");

   for(int a = 0; a<size; a++)
   {
     scanf("%d", &element);
     stack[a] = element;
   }

   printf("The array is: ");
   for(int b = 0; b<size; b++)
   {
     printf("%d ",stack[b]);
   }

   // Insertion sort

   for(int j = 1; j<size; j++)
   {
     key = stack[j];
     i = j-1;
     printf("\nKey: %d",key);

     while(i > -1 && stack[i] > key)
     {
       compare++;//For all cases where stack[i] > key
       stack[i+1] = stack[i];
       exchange++;
       i--;
     }
     if(stack[i] <= key && i != -1)
     {
       //Taking care of when the while condition is false due to i == -1.
       //Because in that case there will be no comparison
       compare++;//For that one case when stack[i] < key
     }

     stack[i+1] = key;
     printf("\nIteration: ");
     for(int b = 0; b<size; b++)
     {
       printf("%d ",stack[b]);
     }
     printf("\n");
   }


   printf("\nThe sorted array is: ");
   for(int b = 0; b<size; b++)
   {
     printf("%d ",stack[b]);
   }

   printf("\nNo. of comparisons: %d", compare);
   printf("\nNo. of exchanges: %d", exchange);


}
