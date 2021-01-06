#include<bits/stdc++.h>
using namespace std;

void toh(int n, char pr = 'a', char sec='c', char aux = 'b')
{
	if(n==0) return;

	toh(n-1, pr, aux, sec);
	cout<<"move "<<n<<" form "<<pr<<" to "<<sec<<"\n";
	toh(n-1, aux, sec, pr);
}

int toh_ct(int n, char pr = 'a', char sec='c', char aux = 'b')
{
	if(n==0) return 0;

	int ans=0;
	ans += toh_ct(n-1, pr, aux, sec);
	// cout<<"move "<<n<<" form "<<pr<<" to "<<sec<<"\n";
	ans += 1;
	ans += toh_ct(n-1, aux, sec, pr);
	return ans;
}

// t(n) = 2*t(n-1)
//  (2^n - 1)

// 2^0 + 2^1 + 2^2 + ..... + 2^(n-1) = 1*((2^n)-1)/(2-1) = 2^n - 1


int main()
{
	cout<<toh_ct(8);
}