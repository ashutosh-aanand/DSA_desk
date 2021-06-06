#include <bits/stdc++.h> 
using namespace std;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<vector<ll> > vvl;
ll mod = 1e9 + 7;
 

void solve()
{
    int n; cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    priority_queue<int, vector<int>, greater<int> > pq;

    ll sum=0, ans=0, ct=0;
    for(int i=0;i<n;i++){
        if(sum+a[i] < 0){
            if(!pq.empty() && pq.top() < a[i]){
                sum -= pq.top();
                pq.pop();
                ct--;
            }
        }
        if(sum+a[i] >= 0){
            sum += a[i];
            ct++;
            if(a[i]<0){
                pq.push(a[i]);
            }
        }
        ans = max(ans, ct);
    }
    cout<<ans<<"\n";
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