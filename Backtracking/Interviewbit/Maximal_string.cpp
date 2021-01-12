#include<iostream>
#include<string>
using namespace std;

/*
Given a string S and integer k, what is maximal lexicographical string 
that can be made from S if you do atmost k swaps.

Problem Constraints
1 <= |S| <= 9

S contains only digits from 0 to 9.

1 <= k <= 5
*/

/*
rough
254 => {524, 425} => 524
524 => {542} => 542
425 => {452, 524} => 524
*/


// method 1
string solve1(string s, int k)
{
	if(k==0) return s;

	int n = s.length();
	string ans = "0";

	int swaps = 0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(s[i]<s[j]){

				swap(s[i], s[j]);
				ans = max(ans, solve1(s, k-1));
				swap(s[i], s[j]);

				swaps ++;
			}
		}
	if(swaps == 0) return s;

	return ans;
}



int main()
{
	string s = "63820";

	cout<<solve1(s,3);

}