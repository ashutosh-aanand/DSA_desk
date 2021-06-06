#include<iostream>
#include<vector>
using namespace std;

/*
n=2
  00
10  01
01  10
11  11
*/

// n=3

// 000
// 001 001
// 011 010
// 010 001
// 110 100
// 100 010
// 101 001
// 111 010

// 	000
// 001 001
// 010 011
// 100 111
// 010 101
// 001 100
// 010 110
// 100 010

int pow(int a,int b)
{
	int ans=1;
	while(b){
		if(b&1) ans*=a;
		a*=a,b=b/2;
	}
	return ans;
}

// method1
vector<int> solve1(int n)
{
	int rep = pow(2,n)-1;
	int mx = pow(2,n-1);

	vector<int> ans;
	ans.push_back(0);

	int curr = 0;
	int mul = 1;
	float f;

	while(rep--)
	{
		curr ^= mul;
		ans.push_back(curr);
		// cout<<mul<<" ";
		
		if(mul == mx) f = 0.5;
		else if(mul == 1) f = 2;

		mul *= f;
	}
	return ans;
}

int main()
{
	vector<int> ans;

	ans = solve1(3);

	for(int x: ans) cout<<x<<", ";
}