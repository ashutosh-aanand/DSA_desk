#include<iostream>
using namespace std;

// k=3
// 1 2 3 4 5 6 7 8  n=8
// 6 7 . 1 2 3 4 5  n=7

// 3 4 . 5 6 . 1 2

// 1->4
// 2->5
// 3->6

// (5+3-1)%8 +1
// (6+3-1)%8+1

// (nxt + k - 1) % n + 1

// n=1 return 1

int jos(int n, int k) // O(n)
{
	if(n==1) return 1;
	return (jos(n-1,k) + k - 1) % n + 1;
}

int josp(int n, int k) // O(n)
{
	return (n==1) ? 1 : (josp(n-1,k) + k - 1) % n + 1;
}

// t(n) = t(n-1) + c => O(n)

// In Javascript
// const josp = (n,k) => (n==1) ? 1 : (josp(n-1,k) + k -1) % n + 1;

int main()
{
	// cout<<jos(5,3);
	cout<<josp(5,3);
}