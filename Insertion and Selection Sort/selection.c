#include <stdio.h>

# define MAXSIZE 100;
int stack[100];

int main()
{
  int size,element,compare = 0,exchange = 0,i,j,min,temp;

  printf("Enter size of array: ");
  scanf("%d", &size);

   printf("Enter the elements of array:- \n");

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
   printf("\n");

   //Selection sort
   for(int i = 0; i < size - 1; i++)
   {
     min = i;

     for(j = i+1; j<size; j++)
     {
       if(stack[j] < stack[min])
       {
         min = j;
       }
       //Irrespective of whether the if statement is true or not, comparison will take place
       compare++;
     }
     //Exchanges will happen only when a new min is found. If min remains equal to i, then no exchanges.
     if(min != i)
     {
       exchange++;
     }
     temp = stack[i];
     stack[i] = stack[min];
     stack[min] = temp;

     printf("\nIteration: ");
     for(int index = 0; index<size; index++)
     {
       printf("%d ", stack[index]);
     }
     printf("\n");
   }

   printf("\nSorted array is: ");
   for(int index = 0; index<size; index++)
   {
     printf("%d ", stack[index]);
   }

   printf("\n\nNo. of comparisons: %d", compare);
   printf("\nNo. of exchanges: %d", exchange);


}
