#include <bits/stdc++.h> 
using namespace std;

void fast_IO() { ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<vector<ll> > vvl;
ll mod = 1e9 + 7;
 
int fun(string s, string t){
    int n = s.length();
    map<char, vector<int> > mp;

    for(int i=n-1;i>=0;i--){
        mp[t[i]].push_back(i);
    }

    vector<int> indx(n,0);
    for(int i=0;i<n;i++){
        // cout<< mp[s[i]].back()<<" ";
        indx[i] = mp[s[i]].back();
        mp[s[i]].pop_back();
    }
    // cout<<"\n";

    stack<int> st;
    st.push(indx[0]);

    int ans = 0;
    for(int i=1;i<n;i++){
        while(!st.empty() && st.top() < indx[i]){
            st.pop();
            ans ++;
        }
        st.push(indx[i]);
    }
    return ans;
}

void solve()
{
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.length();
        int f[256] = {0};
        for(int i=0;i<n;i++) f[s[i]]++;

        string given = "ANOT";

        int mxcnt = -1;
        string ans="";

        do{
            string t="";
            for(char c: given){
                int fc = f[c];
                while(fc--) t += c;
            }

            // cout<<t<<" ";
            int cnt = fun(s,t);
            // cout<<cnt<<"\n";

            if(cnt > mxcnt){
                mxcnt = cnt;
                ans = t;
            }
        }
        while(next_permutation(given.begin(), given.end()));

        reverse(ans.begin(), ans.end());

        cout<<ans<<"\n";
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