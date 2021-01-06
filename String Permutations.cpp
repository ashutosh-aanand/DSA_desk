#include<bits/stdc++.h>
using namespace std;


// cab
// => abc

// abc, acb, bac, bca, cab, cba
// n -> n!

// [][][] [a,b,c]

// [a][][]  [b,c]
// [a][b][] [c]
// [a][b][c]
// [a][c][] [b]
// [a][c][b]

// [b][][]  [a,c]
// [c][][]  [a,b]

void arrange(string s, vector<int>& f, int n, vector<string>& ans, string curr="")
{
	if(n==0){ ans.push_back(curr); return;}

	for(char i='A';i<='Z';i++)
	{
		if(f[i])
		{
			f[i]-=1;
			arrange(s,f,n-1,ans, curr+i);
			f[i]+=1;
		}
	}
}

vector<string> permutation(string s)
{
	vector<int> f(256,0);
	for(int i=0;i<s.length();i++) f[s[i]]++;

	vector<string> ans;
	arrange(s,f,s.length(), ans);
	return ans;
}

//Time complexity: 

// n + n*(n-1) + n*(n-1)*(n-2) + .... + n!
// n!(1/(n-1)! + 1/(n-2)! + .... + 1/2! + 1)
// n!(e-1)
// =>O(n!)

int main()
{
	vector<string> ans;
	ans = permutation("AAB");
	for(string x: ans) cout<<x<<"\n";
}