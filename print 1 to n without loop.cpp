#include<bits/stdc++.h>
using namespace std;

// 1,2,3,4,5,....,n

void print_till_n(int n)
{
	if(n==0) return;

	print_till_n(n-1);
	cout<<n<<", ";
}

void print_till_n2(int n, int i=1)
{
	if(i==n+1) return;

	cout<<i<<",";
	print_till_n2(n,i+1);
}


int main()
{
	// print_till_n(4);
	print_till_n2(9);
}