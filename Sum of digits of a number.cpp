#include<bits/stdc++.h>
using namespace std;


// recursive
int digits_sum(int n)
{
	if(n<10) return n;
	return digits_sum(n/10) + n%10;
}

// log10(n)
// => O(no. of digits)

int digits_sum(int n)
{
	return (n<10) ? n : digits_sum(n/10) + n%10;
}

// JS code
// const digits_sum = n => (n<10) ? n : digits_sum(n/10) + n%10;



// iterative code
int digits_sum_i(int n)
{
	int sum = 0;
	while(n>0){
		sum += n%10;
		n/=10;
	}
	return sum;
}





int main()
{
	cout<<digits_sum(12349);
}