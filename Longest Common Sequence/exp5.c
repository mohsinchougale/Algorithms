#include<stdio.h>
#define ll long long int
void swap(ll* a,ll* b)
{
	ll t=*a;
	*a=*b;
	*b=t;
}
int partition(ll arr[],ll brr[],ll low,ll high)
{
	ll pivot=arr[high];
	ll i=low-1;
	for(ll j=low;j<=high-1;j++)
  {
		if(arr[j]<=pivot)
    {
			i++;
			swap(&arr[i],&arr[j]);
			swap(&brr[i],&brr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	swap(&brr[i+1],&brr[high]);
	return (i+1);
}
void quickSort(ll arr[],ll brr[],ll low,ll high)
{
	if(low<high)
  {
		ll pi=partition(arr,brr,low,high);
		quickSort(arr,brr,low,pi-1);
		quickSort(arr,brr,pi+1,high);
	}
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
  {
	    ll n,i,j,k;
	    scanf("%lld",&n);
	    ll l[n],u[n],i1[n],i2[n],s[n];
	    for(i=0;i<n;i++)
      {
	        scanf("%lld %lld",&l[i],&u[i]);
	        i1[i]=i2[i]=i;
	        s[i]=0;
	    }
	    quickSort(l,i1,0,n-1);
	    quickSort(u,i2,0,n-1);
	    for(i=0;i<n;i++)
      {
	        s[i1[i]]+=n-1-i;
	        s[i2[i]]+=i;
	    }
	    for(i=0;i<n;i++)
	        printf("%lld ",s[i]);
	    printf("\n");
	}
	return 0;
}
