#include<bits/stdc++.h>
using namespace std;
void test_here_once(){ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}
#define ll long long

//adj matrix input

/*
eg.,
n e
e lines : u -> v
*/
vector<vector<int> > input_adj_matrix_directed(int n, int e)
{
	vector<vector<int> > adj(n+1, vector<int>(n+1, 0));

	int u,v;
	while(e--)
	{
		cin>>u>>v;
		adj[u][v]=1;
	}
	return adj;
}
vector<vector<int> > input_adj_matrix_undirected(int n, int e)
{
	vector<vector<int> > adj(n+1, vector<int>(n+1, 0));

	int u,v;
	while(e--)
	{
		cin>>u>>v;
		adj[u][v]=adj[v][u]=1;
	}
	return adj;
}

// Adjacency list input
/*
n e
e lines: u -> v
*/
vector<vector<int> > input_adj_list_directed(int n, int e)
{
	vector<vector<int> > adj(n+1);
	int u,v;
	while(e--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	return adj;
}
vector<vector<int> > input_adj_list_undirected(int n, int e)
{
	vector<vector<int> > adj(n+1);
	int u,v;
	while(e--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return adj;
}

// Edge list input
vector<vector<int> > input_edge_list_undirected(int n, int e)
{
	vector<vector<int> > edjes(e+1);
	int u,v;
	while(e--)
	{
		cin>>u>>v;
		edjes.push_back({u,v});
	}
	return edjes;
}


// ----------------------------------------------------------------------------------




void bfs_with_distance(vector<int> adj[], int s, int v)
{
	queue<int> q;
	vector<bool> vis(v,false);
	vector<int> dist(v,0);

	q.push(s);
	dist[s]=0;
	vis[s]=true;

	while(!q.empty())
	{
		int curr = q.front(); q.pop();

		for(int nbr: adj[curr])
		{
			if(!vis[nbr])
			{
				dist[nbr]=dist[curr]+1;
				q.push(nbr);
				vis[nbr]=true;
			}
		}
	}
}


// 2. 0-1 BFS  [hacker-earth]

/*This type of BFS is used to find the shortest distance between two nodes
in a graph provided that the edges in the graph have the weights 0 or 1.
If you apply the BFS explained earlier in this article, you will get
an incorrect result for the optimal distance between 2 nodes.
*/

void bfs_01(vector<pair<int,int> > adj[], int s, int v)
{
	deque<int> dq;
	vector<int> dist(v, INT_MAX);

	dist[s]=0;
	dq.push_front(s);

	while(!dq.empty())
	{
		int curr = dq.front();
		dq.pop_front();

		for(auto nbr: adj[curr])
		{
			if(dist[curr] + nbr.second < dist[nbr.first])
			{
				dist[nbr.first] = dist[curr] + nbr.second;

				if(nbr.second==0) dq.push_front(nbr.first);
				else dq.push_back(nbr.first);
			}
		}
	}
}

//Print Shortest path using BFS

void print_shortest_path_bfs(vector<vector<int> >& adj, int n, int s, int d)
{
	queue<int> q;
	vector<int> dist(n+1,INT_MAX);
	vector<bool> vis(n+1, 0);
	vector<int> prev(n+1, -1);

	q.push(s);
	vis[s]=true;
	prev[s]=-1;
	dist[s]=0;

	while(!q.empty())
	{
		int curr = q.front(); q.pop();

		for(int nbr: adj[curr])
		{
			if(!vis[nbr])
			{
				q.push(nbr);
				vis[nbr]=true;
				dist[nbr] = dist[curr] + 1;
				prev[nbr] = curr;
			}
		}
	}

	// for(int i=1;i<=n;i++) cout<<prev[i]<<" ";

	vector<int> path;
	path.push_back(d);
	
	int curr = d;
	while(prev[curr]!=-1)
	{
		curr=prev[curr];
		path.push_back(curr);
	}

	reverse(path.begin(), path.end());

	for(int x: path) cout<<x<<" "; cout<<endl;

}




// DFS
void dfs(vector<int> adj[], int s, vector<int>& vis)
{
	vis[s]=true;
	for(int nbr: adj[s])
	{
		if(!vis[nbr]) dfs(adj, nbr, vis);
	}
}

// iterative dfs using stack
void dfs_iterative(vector<int> adj[], int s, int v) // O(V+E)
{
	stack<int> st;
	st.push(s);
	vector<int> vis(v+1,0);
	vis[s]=true;

	while(!st.empty())
	{
		int curr=st.top();
		st.pop();

		for(int nbr: adj[curr])
		{
			if(!vis[nbr])
			{
				st.push(nbr);
				vis[nbr]=true;
			}
		}
	}
}

// MINIMUM SPANNING TREE

/*
Given an undirected and connected graph G=(V,E), a spanning tree of the graph G
 is a tree that spans G (i.e., it includes every vertex of ) 
 and is a subgraph of G (i.e., every edge in the tree belongs to G)

The cost of the spanning tree is the sum of the weights of all the edges in the tree. 

"Minimum spanning tree" is the spanning tree where the cost is minimum 
among all the spanning trees. There also can be many minimum spanning trees.

Minimum spanning tree has direct application in:
 > design of networks
 > used in algorithms approximating the travelling salesman problem, 
 > multi-terminal minimum cut problem
 > minimum-cost weighted perfect matching.

Other practical applications are:
 > Cluster Analysis
 > Handwriting recognition
 > Image segmentation
*/

// 1. Kruskal's algorithm (greedy)

// m1) using dfs

// m2) using disjoint sets

bool cmp(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b)
{
	return a.first<b.first;
}

int root(int node, vector<int>& parent)
{
	while(parent[node]!=node)
	{
		parent[node]=parent[parent[node]];
		node = parent[node];
	}
	return node;
}

void make_union(int a, int b, vector<int>& parent, vector<int>& size)
{
	int root_a = root(a, parent);
	int root_b = root(b, parent);

	if(root_a!=root_b)
	{
		if(size[root_a] < size[root_b])
		{
			parent[root_a] = root_b;
			size[root_b] += size[root_a];
			size[root_a] = 0;
		}
		else
		{
			parent[root_b] = root_a;
			size[root_a] += size[root_b];
			size[root_b] = 0;
		}
	}
}

// vector<int, pair<int,int> >  =>  {cost, {node1,node2}}
int kruskal(vector<pair<int, pair<int,int> > > edges, int n)
{
	sort(edges.begin(), edges.end(), cmp);
	vector<int> parent(n+1);
	vector<int> size(n+1,0);

	for(int i=1;i<=n;i++) parent[i]=i, size[i]=1;
	
	int x,y,cost;
	int ans=0;
	for(auto edge: edges)
	{
		x = edge.second.first;
		y = edge.second.second;
		cost = edge.first;

		if(root(x, parent)!=root(y, parent))// if they are part of disjoint sets
		{
			make_union(x, y, parent, size);
			ans+=cost;
		}
	}
	return ans;
}

// 2. Prim's algorithm

typedef pair<int, int> pii;

int prims(vector<pii> adj[], int n, int x)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	pq.push({0,x});

	vector<bool> vis(n+1,false);

	int ans=0;
	while(!pq.empty())
	{
		pii node = pq.top(); pq.pop();

		int x=node.second;

		if(!vis[x])
		{
			ans+=node.first;
			vis[x]=true;

			for(pii nbr: adj[x])
			{
				if(!vis[nbr.second]) pq.push(nbr);
			}
		}
	}
	return ans;
}

// Shortest path algorithms

/*
The shortest path problem is about finding a path between 2 vertices in a graph
 such that the total sum of the edges weights is minimum.
This problem could be solved easily using (BFS) if all edge weights were same,
but here weights can take any value. 
Three different algorithms are discussed below depending on the use-case.
*/

// 1. Bellman Ford's algo.   (dp)
// 2. Dijkstra's algo.		 (greedy)
// 3. Floyd Warshall's algo. (dp)


// 1. Bellman ford

/*
> requires edge list representation of a graph.
> relax all edjes (n-1) times.
*/

vector<int> bellman_ford(vector<vector<int> >& edges, int n, int s)
{
	vector<int> cost(n+1,INT_MAX);
	cost[s]=0;

	for(int i=1;i<=n;i++)
	{
		int changes = 0;
		for(auto edge: edges)
		{
			int u = edge[0], v = edge[1], w = edge[2];

			if(cost[u] + w < cost[v])
			{
				cost[v] = cost[u] + w;
				changes++;
			}
		}
		
		if(changes==0) break;
		if(i==n && changes>0) cout<<"There is a -ve cycle in the graph.This algo. won\'t give right result";
	}
	return cost;
}

void bellman_ford_input()// edge list
{
	int n,m; cin>>n>>m;
	vector<vector<int> > edges;

	int u,v,w;
	while(m--)
	{
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}

	vector<int> cost = bellman_ford(edges, n, 1);

	for(int i=1;i<=n;i++) cout<<i<<": "<<cost[i]<<"\n";
}

// 2. Dijkstra's algorithm 		=> works only if all edge weights are +ve

//time complexity: O(n^2)

/*
> requires adjacency list rep.of graph

> works on directed as well as undirected graphs
> vertices whose neighbours once relaxed need not to be visited again.
> each time, we select the min. cost vertex from the set of remaining vertices,
	and relax its neighbours.

> It assumes that if a vertex was selected anytime as min cost vertex then it was
	an optimal selection and
	any other path leading to it won't give less cost (as all edges are +ve weighted)

> ** It doesn't give right result in case of edges with -ve weights.
*/

vector<int> dijkstras(int s, int n, vector<vector<pair<int,int> > >& adj)
{
	vector<int> vis(n+1, false);
	vector<int> cost(n+1, INT_MAX);

	priority_queue<pii, vector<pii>, greater<pii> > pq; //min priority queue
	pq.push({0,s});
	cost[s]=0;

	while(!pq.empty())
	{
		pii node = pq.top(); pq.pop();

		int u = node.second;

		if(!vis[u])
		{
			vis[u]=true;
			for(pii nbr: adj[u])
			{
				int edge_cost = nbr.first;
				int v = nbr.second;
				if(cost[u] + edge_cost < cost[v])
				{
					cost[v] = cost[u] + edge_cost;
					pq.push({cost[v], v});
				}

				if(edge_cost<0) cout<<"This graph contains a -ve edge. So, Dijkstra\'s algo. won't give right answer.";
			}
		}
	}
	return cost;
}

void dijkstra_input()//adjacency list
{
	int n,m; cin>>n>>m;
	vector<vector<pair<int,int> > > adj(n+1);

	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		adj[u].push_back({w,v});
	}
	vector<int> ans = dijkstras(1,n, adj);

	for(int i=1;i<=n;i++) cout<<i<<": "<<ans[i]<<"\n";
}

// All pairs shortest path algorithm

// m1) Greedy: we can use dijkstra's for all nodes as source node one by one =>O(n^3)

// m2) DP: 
// Floyd Warshall's algorithm => O(n^3)

/*
> in this algo. we take (nxn) matrix dist and taking each node "k" as an 
	intermediate node we will find the shortest path between all pairs of node

> dist[u][v] = min(dist[u][v], dist[u][k]+dist[k][v]);

*/

void floyd_warshalls(int n, vector<vector<pair<int,int> > >& adj)
{
	vector<vector<ll> > dist(n+1, vector<ll>(n+1,INT_MAX));

	//initialisation of dist matrix
	for(int i=1;i<=n;i++)
	{
		for(pii nbr: adj[i])
		{
			int u=i, v=nbr.second;
			int wt = nbr.first;
			
			dist[u][v] = wt;
		}
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;

	// algorithm
	for(int k=1;k<=n;k++)
	{
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				dist[u][v] = min(dist[u][v], dist[u][k]+dist[k][v]);
			}
		}
	}
	

	// printing the result
	for(int i=1;i<=n;i++)
	{
		cout<<"for"<<i<<"\n-----\n";
		for(int j=1;j<=n;j++)
		{
			cout<<i<<"->"<<j<<" :"<<dist[i][j]<<"\n";
		}
		cout<<"\n";
	}
}

void floyd_warshalls_input() //adjacency list
{
	int n,m; cin>>n>>m;
	vector<vector<pair<int,int> > > adj(n+1);
	int u,v,w;
	while(m--)
	{
		cin>>u>>v>>w;
		adj[u].push_back({w,v});
	}
	floyd_warshalls(n, adj);
}

// Count number of connected components in undirected graph
// int count_connected_components(vector<int> adj[], int n)
// {
// 	vector<bool> vis(n+1, false);
// 	int ct=0;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(!vis[i])
// 		{
// 			ct++;
// 			dfs(adj, i, vis);
// 		}
// 	}
// 	return ct;
// }

//Articulation points

//m1) brute force

/*
Things needed:
1. "adj matrix" rep of graph
2. dfs for adj matrix
*/

// vector<int> articulation_pts_m1(vector<vector<int> > adj, int n)
// {
// 	int init_ct = count_connected_components(adj, n);

// 	for(int i=1;i<=n;i++)
// 	{
// 		// remove ith vertex and associated edges
// 		for(int j=1;j<=n;j++)
// 		{
// 			remove[j]=adj[i][j];
// 			if(adj[i][j]==1) adj[i][j]=adj[j][i]=0;
// 		}
// 		// count no. of connected componenets
// 		int curr_ct = count_connected_components(adj, n);

// 		if(curr_ct > init_ct) art_pt.push_back(i);

// 		// add ith vertex back to the graph
// 		for(int j=1;j<=n;j++)
// 		{
// 			if(remove[j]==1) adj[i][j]=adj[j][i]=1;
// 		}
// 	}
// }


void print_adj(vector<vector<int> >& adj, int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<i<<": ";
		for(int nbr: adj[i]) cout<<nbr<<" "; cout<<"\n";
	}
}


// Topological sort 

// m1) using indegrees
/*
i> count the indegrees of each node
ii>start with node have indegree = 0 
*/

void topological_sort(vector<vector<int> >& adj, int n)
{
	int indegree[n+1]={0};

	for(int i=1;i<=n;i++)
	{
		for(int nbr: adj[i])
		{
			indegree[nbr]++;
		}
	}

	queue<int> q;

	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0) q.push(i);
	}

	vector<int> ans;
	while(!q.empty())
	{
		int curr = q.front(); q.pop();
		ans.push_back(curr);

		for(int nbr: adj[curr])
		{
			indegree[nbr]--;
			if(indegree[nbr]==0) q.push(nbr);
		}
	}

	for(int x: ans) cout<<x<<" "; cout<<"\n";
}


// Eulerian graph
void _dfs(vector<vector<int> >  &adj, int i, vector<int> &vis){
	vis[i] = true;

	for(int nbr: adj[i]){
		if(!vis[nbr]){
			_dfs(adj, nbr, vis);
		}
	}
}

bool isConnected(vector<vector<int> >  &adj)
{
	int n = adj.size();

	vector<bool> vis(n, false);

	int i;
	for(i=0;i<n;i++){
		if(adj[i]){
			_dfs(adj, i, vis);
			break;
		}
	}

	if(i==n) return true;

	for(i=0;i<n;i++){
		if(adj[i]>0 && !vis[i]) return false;
	}
	return true;
}



void isEulerian(vector<vector<int> >  &adj){
	if(! isConnected(adj)){ cout<<"no\n"; return; }

	int odd = 0;
	for(int i=0;i<adj.size();i++){
		if(adj[i].size() & 1) odd ++;
	}

	if(odd > 2){ cout<<"no\n"; return;}

	if(odd == 2){ cout<<"has eulerean path but no eulerian cycle\n"; return;}
	if(odd == 0){ cout<<"Eulerian\n"; return;}
	cout<<"no\n";
}





int main()
{
	test_here_once();
	// bellman_ford_input();
	// dijkstra_input();
	// floyd_warshalls_input();
	int n,m; cin>>n>>m;
	vector<vector<int> > adj(n+1);
	while(m--)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		// adj[v].push_back(u);
	}
	// print_adj(adj,n);
	// int s,d; cin>>s>>d;
	// print_shortest_path_bfs(adj, n, s, d);
	topological_sort(adj, n);

}