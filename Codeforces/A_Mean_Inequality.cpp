#include <bits/stdc++.h> 
using namespace std;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
ll MOD = 10e7;
 

void solve()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        n = 2*n;
        ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
        
        sort(a,a+n);

        for(int i=1;i+1<n;i+=2){
            swap(a[i],a[i+1]);
        }
        for(ll x: a) cout<<x<<" ";
        cout<<"\n";

    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fast_IO();
    solve();
}
