#include<bits/stdc++.h>
using namespace std;

// a = {1, 2, 7, 4, 5}

bool is_sorted(int a[], int n, int order=1, int i=0)
{
	if(i==n-1) return true;
	if(i+1<n)
	{
		if((order==1 && a[i]>a[i+1]) || (order==-1 && a[i]<a[i+1]))
		{
			cout<<"i: "<<i<<"\n";
			return false;
		}
	}
	return is_sorted(a, n, order, i+1);
}

// Time complexity:
// t(n) = t(n-1) + c
// => O(n)



/* changes:
------------
> got rid of variable i
> getting rightmost index not following the order.
*/

// {1,2,3,4} a[n-2]<=a[n-1]
bool is_sortedd(int a[], int n, int order=1)
{
	if(n==1) return true;
	if((order==1 && a[n-2]>a[n-1]) || (order==-1 && a[n-2]<a[n-1]))
	{
		cout<<"i: "<<n-2<<"\n";
		return false;
	}
	return is_sortedd(a, n-1, order);
}


int main()
{
	int a[] = {9,4,0,2,1};
	int n = sizeof(a)/sizeof(a[0]);

	// cout<<is_sorted(a,n);
	cout<<is_sortedd(a,n);
}