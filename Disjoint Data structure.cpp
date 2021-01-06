#include<bits/stdc++.h>
using namespace std;
void test_here_once(){ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}


/*
Assume that you have a set of N elements that are into further subsets and 
you have to track the connectivity of each element in a specific subset or 
connectivity of subsets with each other.
You can use the union-find algorithm (disjoint set union) to achieve this.
*/

// parent[n+1] an array consisting of parent node of each node from 1 to n.
// 				parent[i] will contain parent node of node i.
//   it will be initialised as parent[i]=i for each i

// size[n+1] if i is a root node of a disjoint set, size[i] will contain the
//    size of that disjoint set.

int root(int node, vector<int>& parent)//O(log(n))
{
	while(parent[node]!=node)
	{
		parent[node]=parent[parent[node]];
		node = parent[node];
	}
	return node;
}

bool find(int a, int b, vector<int>& parent)
{
	int root_a = root(a, parent);
	int root_b = root(b, parent);

	return root_a==root_b;
}

void make_union(int a, int b, vector<int>& parent, vector<int>& size)
{
	int root_a = root(a, parent);
	int root_b = root(b, parent);

	if(root_a!=root_b)
	{
		if(size[root_a] < size[root_b])
		{
			parent[root_a]=root_b;
			size[root_b]+=size[root_a];
			size[root_a]=0;
		}
		else
		{
			parent[root_b]=root_a;
			size[root_a]+=size[root_b];
			size[root_b]=0;
		}
	}
}


int main()
{
	test_here_once();
}