#include<stdio.h>

int m, n;
int c=0;
int count=0;
int recursive=0;
int g[50][50];
int x[50];



void nextValue(int k)

{

 int j;
 while(1)
 {

  x[k]=(x[k]+1)%(m+1);  //next higher colour
  if(x[k]==0)  //all colours have been used
  {
   return;
  }      //check if colour is distinct from other colours

  for(j=1;j<=n;j++)

  {

   if(g[k][j]==1&&x[k]==x[j])  //(k,j) is edge, adj vertices have same colour

    break;

  }

  if(j==(n+1)) //new colour found

  {

   return;  //try to find another colour

  }

 }

}


void GraphColoring(int k)

{

 int i;
 recursive++;

 while(1)  // generate all legal assignment for x[k]

 {

  nextValue(k);  //assign x[k] a legal val

  if(x[k]==0) //no new color possible

  {

   return;  // at most m color have been used to color the n vertices

  }



 if(k==n)  //// at most m color have been used to color the n vertices


 {

  c=1;

  for(i=1;i<=n;i++)

  {

   printf("%d -> ", x[i]);

  }

  count++;  //for counting number of solution

  printf("\n");

 }

 else{

    printf("Recursive Graph Coloring call for vertex %d and count %d:\n",k+1,count);
    GraphColoring(k+1);
 }



 }

}


int main()

{

 int i, j;

 int temp;

 printf("\nEnter the number of nodes: " );

 scanf("%d", &n);

 printf("\nEnter Adjacency Matrix:\n");

 for(i=1;i<=n;i++)

 {

  for(j=1;j<=n;j++)

  {

   scanf("%d", &g[i][j]);

  }

 }



 printf("\nPossible Solutions are:\n");

 for(m=1;m<=n;m++)

 {

  if(c==1)

  {

   break;

  }

  GraphColoring(1);

 }



 printf("\nThe minimum number of color required are: %d", m-1);
 printf("\nThe total number of solutions are: %d", count);
 printf("\nThe number of recursive calls is: %d", recursive);

 return 1;

}
