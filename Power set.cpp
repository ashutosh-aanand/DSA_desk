#include<bits/stdc++.h>
using namespace std;


void power(string s, string curr="", int i=0)
{
	if(i==s.length()){ cout<<"{"<<curr<<"}\n";return;}

	power(s,curr, i+1);
	power(s,curr+s[i],i+1);
}

// abc
// {} {a} {a,b} {a,b,c} {b} {b,c} {c} {c,a}

// 		""
// 	 a     b 	c     
//    ab ac   bc	
//   abc 


void powerSet(int n, vector<int> f, string curr="") // O(2^n)
{
	cout<<"{"<<curr<<"}\n";

	for(char i='a';i<='z';i++)
	{
		if(f[i])
		{
			f[i]-=1;
			n--;
			powerSet(n,f, curr + i);
		}
	}
}

void fun(string s)
{
	int n = s.length();
	vector<int> f(256, 0);

	for(int i=0;i<n;i++) f[s[i]]++;

	powerSet(n, f);
}


int main()
{
	fun("abc");
	// power("abc");
}