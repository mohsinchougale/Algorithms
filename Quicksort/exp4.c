#include <stdio.h>
#include <stdlib.h>
int cnt=1;
int Merge(int A[],int low,int mid,int high)
{
 int left[mid-low+1];
 int right[high-mid];
 int count = 0;
 for(int i=0;i<mid-low+1;i++)
 {
   left[i]=A[low+i];
 }
 printf("\n%d:-",cnt);
 cnt++;
 printf("Left Array: ");
 for(int i=0;i<mid-low+1;i++)
 {
   printf("%d," ,left[i]);
 }
 for(int i=0;i<high-mid;i++)
 {
   right[i]=A[mid+i+1];
 }
 printf("\n\nRight Array: ");
 for(int i=0;i<high-mid;i++)
 {
   printf("%d," ,right[i]);
 }
 printf("\n");
 int l = 0;
 int m = 0;
 int k = low;
 while (l < mid-low+1 && m < high-mid)
 {
   if (left[l] <= right[m])
   {
     A[k] = left[l];
     l++;
     k++;
   }
   else
   {
     A[k] = right[m];  count+=mid-low+1-l;  m++;
     k++;
   }
 }
 while (l < mid-low+1)
 {
   A[k] = left[l];
   l++;
   k++;
 }
 while (m < high-mid)
 {
   A[k] = right[m];
   m++;
   k++;
 }
 return count;
}

int MergeSort(int A[],int low,int high)
{
 int c=0;
 if(low<high)
 {
   int mid=(low+high)/2;
   c+=MergeSort(A,low,mid);
   c+=MergeSort(A,mid+1,high);
   c+=Merge(A,low,mid,high);
 }
 return c;
}

int main()
{
 int n;
 printf("Enter a number:");
 scanf("%d",&n);
 int arr[n];
 printf("Enter elements of array:");
 for(int i=0;i<n;i++)
 {
   scanf("%d",&arr[i]);
 }
 printf("\nElements of array before being sorted:\n");
 for(int i=0;i<n;i++)
 {
   printf("%d ",arr[i]);
 }
 int ans=MergeSort(arr,0,n-1);
 printf("\n\nElements of array after being sorted:");
 for(int i=0;i<n;i++)
 {
   printf("%d ",arr[i]);
 }
 printf("\n\n");
 printf("The number of inversions are:%d\n",ans);
 return 0;
}
