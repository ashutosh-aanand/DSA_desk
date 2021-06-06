#include <bits/stdc++.h> 
using namespace std;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<vector<ll> > vvl;
ll mod = 1e9 + 7;
 

void solve()
{
    int t; cin>>t;
    while(t--){
        ll x; cin>>x;
        if(x>=(111*(x%11))) cout<<"YES\n";
        else cout<<"NO\n";
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