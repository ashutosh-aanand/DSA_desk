#include<bits/stdc++.h>
using namespace std;

// 2: 1,2,3,4,5,6,7,8,9,10, ....
// 3: 1,3,5,7,9,...
// 4: 1,3,5,9,..
// 5: 1,3,5,..

// n%2==0 	else n = n - n/2
// n%3==0  else n = n - n/3

bool isLucky(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(n%i==0) return false;
		n=n-n/i;
	}
	return true;
}

bool isLuckyR(int n, int i=2)
{
	if(i>n) return true;
	if(n%i==0) return false;

	return isLuckyR(n-n/i,i+1);
}

int main()
{
	cout<<isLucky(13);
	// cout<<isLuckyR(9);
}