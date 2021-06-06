#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,j,n)    for(ll i=j;i<n;i++)
#define frr(i,n,j)    for(ll i=n;i>=j;i--)
#define tc           ll t1; cin>>t1; while(t1--)
#define inp          ll n; cin>>n; ll a[n]; fr(i,0,n) cin>>a[i];
#define inp1         ll n1; cin>>n1; ll a[n1]; fr(i,0,n1) cin>>a[i];
#define vec          vector<ll>
#define pb           push_back
#define pii          pair<ll,ll>
#define mp           make_pair
#define F            first
#define S            second
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define srt(v)       sort(v.begin(),v.end())
#define srte(v)      sort(v.rbegin(),v.rend())
#define maxx         1000005
#define lb(v,n)      lower_bound(v.begin(),v.end(),n)-v.begin()
#define ub(v,n)      upper_bound(v.begin(),v.end(),n)-v.begin()
#define inf          LONG_MAX
#define zer          LONG_MIN
const long           mod=pow(10,9)+7;
const long           maxN = 2e5 + 5;
 
//-----------------------------------------------------------
// ---------------------- DEBUG -----------------------------
//-----------------------------------------------------------
void _print(auto x) {cerr << x <<endl;}
 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
} 
 
// For printing set, vector, map etc
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
//----------------------------------------------------------------
//------------------- STRING MANUPULATION-------------------------
//----------------------------------------------------------------
bool ispalindrome(string s);
ll stringToInt(string s);
string addTwoStrings(string num1, string num2);
ll stringModuloM(string s,ll M);
 
//----------------------------------------------------------------
//-------------------MATHEMATICAL TOOLS---------------------------
//----------------------------------------------------------------
// basics
ll power(ll x, ll y,ll m);
ll stringPowerStringModM(string s,string str,ll m);
ll modInv(ll x,ll m);
// P&C stuffs
ll fact[maxN],invFact[maxN];
void factAndFactInvFillup();
ll nCr(ll n,ll r);
// Prime related stuffs
int isPrime[maxN],primeDivisorC[maxN],factorsC[maxN];   
set<int> primesTillMaxN;
void seive();
vector<ll> primeFactorizationOfN(ll n);

// //  Disjoint_set_union 
// const int N = 1+ 2e5 ; int parent[N] ; int sizee[N];
// void make_set(int v) { parent[v] = v; sizee[v] = 1; }
// int find_set(int v) { if (v == parent[v]) return v; return parent[v] = find_set(parent[v]); }
// void union_sets(int a, int b) { a = find_set(a); b = find_set(b); if (a != b) {
//  if (sizee[a] < sizee[b]) swap(a, b); parent[b] = a; sizee[a] += sizee[b]; } }

 
//----------------------------------------------------------------
//--------------- TESTCASE GANARATION HELPERS---------------------
//----------------------------------------------------------------
template <typename t> vector<vector<t>> subsets(vector<t> v); // returns all subsets
vector<ll> randomArrayGenarator(ll l,ll r,ll count); // [l,r] i.e. both inclusive
ll    randomSingleNumGenarator(ll l,ll r); // [l,r] i.e. both inclusive
template <typename T> void permute(T &a, int l, int r);
 
//-----------------------------------------------------------------
//-----------------BASIC HELPERS-----------------------------------
//-----------------------------------------------------------------
#define vn(v,n,val)        std::vector<ll> v (n , val);
#define vnm(v,n,m,val)        std::vector<vector<ll>> v (n , vector<ll> (m, val));
#define vnmk(v,n,m,k,val)       std::vector<vector<vector<ll> >> dp (n , vector<vector<ll>>(m,vector<ll>(k,val)));
template <typename T> int len(T &a) {return (int)a.size();}
void _pri(auto &x) {cout << x <<" ";}
void _priln(auto &x) {cout << x <<" "; cout<<endl;}
template <typename T> 
void pri(T v){ for(auto i:v) cout<<i<<" "; }  // can print  1D vect & set of int,char,string etc.
void priln(){  cout<<'\n'; }
template <typename T> 
void pri2D(T v) { for(auto i:v) { pri(i); cout<<'\n'; } } // can print  2D vect & set of int,char,string etc.
 
template <typename T>
void scan(T &n) { cin>>n; }   // single value
template <typename T>
void scan(vector<T> &v,int n) { fr(i,0,n) cin>>v[i]; }   // 1D vector
template <typename T>
void scan(vector<T> &v,int n,int m) { fr(i,0,n) fr(j,0,m) cin>>v[i][j]; } // 2D Vector

//----------------------------------------------------------------
//------------------- SOLUTION BLOCK -----------------------------
//----------------------------------------------------------------
void solve()
{
     string s;
     cin>>s;
     ll n=s.size();
     vnm(dp,2,n+1,0);

     

     fr(i,0,n){
      if(s[i]=='0'){
        dp[1][i+1] += dp[0][i]+1;
      }else if(s[i]=='1') {
        dp[0][i+1] += dp[1][i]+1;
      }else{
        dp[0][i+1] += dp[1][i]+1;
        dp[1][i+1] += dp[0][i]+1;
      }
     }

     debug_out(dp);

     ll ans=0;

     fr(i,0,n){
       ans += max(dp[0][i+1],dp[1][i+1]);
     }

     cout<<ans<<endl;

   
}

 
int main() {
    fast;   // Always use fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("op.txt" , "w" , stdout);
    #endif
    clock_t tv1, tv2;
    double time;
    tv1 = clock();
    // factAndFactInvFillup();
    // seive();
    // helper();

    // for(auto i:primesTillMaxN) v.pb(i);

    // fr(i,0,5) cout<<v[i]<<" ";
    // cout<<endl;

    tc
    solve();
 
    tv2 = clock();
    time = (tv2 - tv1)/(CLOCKS_PER_SEC / (double) 1000.0);
 
    #ifndef ONLINE_JUDGE
       cout<<"Time Elasped: "<< time <<" ms"<<endl; 
    #endif

}
 
//---------------------------------------------------------------
//---------------------------------------------------------------
//------------------- STRING MANUPULATIONS ----------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
bool ispalindrome(string s)
{
    int l = s.size();
    for(int i=0;i<l/2;i++)
    {
        if(s[i] != s[l-1-i])
            return false;
    }
    return true;
}
 
ll stringToInt(string s)
{
  if(s.size()>18) return -1;
 
  ll ans=0;
  for(int i=0;i<(int)s.size();i++)
  {
    ans = ans*10 + s[i]-'0';
  }
  return ans;
}
string addTwoStrings(string num1, string num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    int n=num1.size(),m=num2.size();
    int carry=0;
    int n1=0,n2=0;
    string ans="";
    int i=0,j=0;
    while(i<n || j<m)
    {
        if(i<n) { n1 = num1[i]-'0' ; i++;}
        if(j<m) { n2 = num2[j]-'0' ; j++;}
        ans = char( (n1+n2+carry)%10  + '0' ) + ans;
        carry = (n1+n2+carry)/10;
        if(i<n || j<m) {
             
        }else if(carry>0){
            ans =  char( (carry)%10  + '0' ) + ans;
        }
        n1=0,n2=0;
    }
    return ans;
}
ll stringModuloM(string s,ll M)
{
   ll res=0;
   for(int i=0;i<s.size();i++)
      res=(10*res+s[i]-'0')%M;
   return res;
}
 
//---------------------------------------------------------------
//---------------------------------------------------------------
//--------------------- MATHEMATICAL TOOLS ----------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
ll power(ll x, ll y,ll m)
{
  ll res = 1; 
  x = x % m;
 
  while (y > 0)
  {
    if (y & 1)
      res = (res*x) % m;
 
    y = y>>1; 
    x = (x*x) % m;
  }
  return res;
}
 
ll modInv(ll x,ll m)
{
  return power(x,m-2,m);
}
 
// For string to power string modulo m( (s^str)%m )
ll stringPowerStringModM(string s,string str,ll m)
{
   ll a=stringModuloM(s,m),b=stringModuloM(str,m-1);
   ll ans=power(a,b,m);
   return ans;
}
 
void factAndFactInvFillup()
{
  // filling factorials
  fact[0] = 1;
  fr(i,1,maxN)
    fact[i] = (i*fact[i-1])%mod; 
 
  // filling inverse factorials
  invFact[maxN-1]=modInv(fact[maxN-1],mod);
  frr(i,maxN-1,1)
    invFact[i-1]=(i*invFact[i])%mod;
   
}
 
ll nCr(ll n,ll r)
{
  if(r>n) return 0;
  ll temp= (fact[n]*invFact[r])%mod;
  return (temp*invFact[n-r])%mod;
}
 
//--------------- DEALING WITH PRIMES --------------
// --------------------------------------------------
void numberOfPrimeDivisors();
void noOfFactors();
void primesTillMaxNhelper();
void seive()
{
  for(int i=0;i<maxN;i++)
     { 
      isPrime[i]=1; 
      primeDivisorC[i]=0; 
      factorsC[i]=0;
     }
 
     isPrime[0]=0;  isPrime[1]=0;
    for(ll i=2;i*i<maxN;i++)
    {
        if( isPrime[i]==1)
        for(ll j=i;i*j<maxN;j++)
           isPrime[i*j]=0;
    }
    // numberOfPrimeDivisors();
    // noOfFactors();
    primesTillMaxNhelper();
}
void primesTillMaxNhelper()
{
  fr(i,2,maxN) if(isPrime[i]) primesTillMaxN.insert(i);
}
void numberOfPrimeDivisors()
{
    primeDivisorC[0]=0; primeDivisorC[1]=1;  
    for(int i=2;i*i<maxN;i++)
    {
        if(isPrime[i]==1)
        for(int j=2;i*j<maxN;j++)
          primeDivisorC[i*j]+=1;
    }
}
void noOfFactors()
{
     for(int i=1;i<maxN;i++)
        for(int j=1;i*j<maxN;j++)
             factorsC[i*j]++;
}
 
vector<ll> primeFactorizationOfN(ll n)
{
  std::vector<ll> ans;
  for(int i=2;i*i<=n;i++)
  {
    while(n%i==0){
      ans.pb(i);
      n/=i;
    }
  }
  if(n>1) ans.pb(n);
  return ans;
}
 
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------- TESTCASE GANARATION HELPERS ------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
 
template <typename t>
vector<vector<t>> subsets(vector<t> v)
{
  ll n=v.size();
  std::vector<std::vector<t>> ans;
  for(int i=0;i<(1<<n);i++)
  {
    std::vector<t> temp;
    for(int j=0;j<n;j++)
    {
      
      if( i>>j & 1 ) {
        temp.push_back(v[j]);
        // cout<<v[j]<<" ";
      } 
    }
    ans.push_back(temp);
    // cout<<endl;
  }
  return ans;
}
ll randomSingleNumGenarator(ll l,ll r)
{
  // to prevent sequence repetition between runs     
  srand(time(NULL));  
 
  ll temp = l +  rand() % (r-l+1);
 
  return temp;
}
vector<ll> randomArrayGenarator(ll l,ll r,ll count)
{
  std::vector<ll> ans;
  if(count>1e6) return ans;
 
  // to prevent sequence repetition between runs     
  srand(time(NULL));  
 
  fr(i,0,count)
  {
    ll temp = l +  rand() % (r-l+1);
    ans.push_back(temp);
  }
 
  return ans;
}
template <typename T>
void permute(T &a, int l, int r)
{
int i;
if (l == r)
    debug_out(a);
else
{
    for (i = l; i <= r; i++)
    {
        swap(a[l], a[i]);
        permute(a, l+1, r);
        swap(a[l], a[i]); //backtrack
    }
}
}