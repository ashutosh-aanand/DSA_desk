#include <bits/stdc++.h> 
using namespace std;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<vector<ll> > vvl;
ll mod = 1e9 + 7;


void solve()
{
	ll q; cin>>q;
	ll a[q+1], c[q+1];
	cin>>a[0]>>c[0];

	ll h = 0;
	// m1)
	// while((1<<h)<=q) h++;
	// m2)
	h = ceil(log2(q+1));

	ll up[q+1][h+1];
	memset(up, -1, sizeof(up));

	// for(ll i=0;i<=h;i++){
	// 	up[0][i] = -1;
	// }

	for(ll i=1;i<=q;i++){
		ll t; cin>>t;
		if(t==1){
			ll par;
			cin>>par>>a[i]>>c[i];
			up[i][0] = par; // parent of i is par
			for(ll j=1;j<=h;j++){
				if(up[i][j-1] != -1)
					up[i][j] = up[up[i][j-1]][j-1];
			}
		}
		else
		if(t==2){
			ll v,w;
			cin>>v>>w;


			ll wt = 0, cost = 0;

			while(w){
				ll top = v;
				for(ll j=h;j>=0;j--){
					ll anc = up[top][j];
					// cout<<top<<" "<<anc<<"\n";
					if(anc!=-1){
						if(a[anc]) top = anc;
					}
				}
				// cout<<top<<"\n\n";
				
				// buy from top
				ll cnt = min(w,a[top]);
				w -= cnt;
				a[top] -= cnt;
				

				wt += cnt;
				cost += cnt*c[top];

				if(top == v) break;
			}

			cout<<wt<<" "<<cost<<"\n";
		}
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