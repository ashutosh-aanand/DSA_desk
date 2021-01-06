#include<bits/stdc++.h>
using namespace std;


// f(n) = f(n-1)+f(n-2);
// f(0) = 0, f(1) = 1

int fib(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return fib(n-1) + fib(n-2);
}

// iterative
int fibn(int n)
{
	if(n==0||n==1) return n;

	int a=0, b=1,c = a+b;

	for(int i=2;i<=n;i++)
	{
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}
// 0,1,1,2,3

int main()
{
	// cout<<fib(10);
	cout<<fibn(3);
}