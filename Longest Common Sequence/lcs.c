#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char b[100][100];
int m,n;

int display_num(int f[m][n],int m,int n)
{
  for(int i=0;i<=m;i++)
  {     for(int j=0;j<=n;j++)
           printf(" %d ",f[i][j]);
      printf("\n");
  }
}

int print(char X[],int i,int j)   //prints the LCS
{

    if(i==0 || j==0)  //termination condition for recurssion
    {
      return 0;
    }


    if(b[i][j]=='D')   //if D is present then print letter
    {
        print(X,i-1,j-1);

        printf("%c ",X[i-1]);
    }
    else if(b[i][j]=='U') //if U is present then recur for immediate upper element
    {
        print(X,i-1,j);
    }
    else
    {
        print(X,i,j-1);  //else reccur for immediate left element
    }

    return 0;


}


int* maxlength(char X[],char Y[],int m,int n)  //function for counting length
{   int j;
    int i;
    printf("\n m=%d,n=%d",m,n);
    int c[m+1][n+1];


    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
        b[i][0]='0';
    }

    for(int j=0;j<=n;j++)
    {
        c[0][j]=0;
        b[0][j]='0';
    }

     for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])   //if element is equal then
            {
                c[i][j]=c[i-1][j-1]+1;  //increment diagonal element by 1 and store at index(i,j)
                b[i][j]='D';            //store D at b(i,j)

            }
//find which one is max immediate upper element or immediate left element whichever is greater store it at c[i,j]
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='U';  //for upper element store U at b[i,j]
            }

            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='L';    //for upper element store L at b[i,j]
            }
        }
    }

    printf("\n\n Matrix C\n\n");     //print c
    for(int i=0;i<=m;i++)
    {     for(int j=0;j<=n;j++)
             printf(" %d ",c[i][j]);
        printf("\n");
    }
    printf("\n");

   printf("\n Matrix B:\n\n");    //print b
   for(int i=0;i<=m;i++)
   {     for(int j=0;j<=n;j++)
             printf(" %c ",b[i][j]);
          printf("\n");
   }

    printf("\n Print LCS: ");
    print(X,m,n);  //print LCS function call
    return c[m][n];//length of LCS
}



//Driver code
int main()
{
    char X[] = "GANESH";
    char Y[] = "BARNES";

    printf("\n String 1 = %s",X);
    printf("\n String 2 = %s\n",Y);
    int m = strlen(X);
    int n = strlen(Y);

    int length = maxlength(X,Y,m,n) ;
    printf("\n \n Length of LCS : %d\n\n",length);


    return 0;

}
