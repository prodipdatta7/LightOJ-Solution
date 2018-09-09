#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const long long M = (long long)1e9+7;
#define     ll      long long
#define     ull     unsigned long long
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
ll Long() {
    ll x;
    scanf("%lld",&x);
    return x;
}
void Char(char* ch) {
    scanf("%s",ch);
}
template<typename t>inline t abs(t a) {
    if(a>=0)return a;
    return -1*a;
}
template<typename T> inline T modpow(T b, T p, T Mod) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
            res %= Mod ;
        }
        b *= b;
        b %= Mod;
        p >>= 1;
    }
    return res ;
}

template<typename T> inline T ModInv(T b, T Mod) {
    return modpow(b, Mod - 2, Mod );
}

template<typename T> inline T pwr(T b, T p) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
        }
        b *= b;
        p >>= 1;
    }
    return res ;
}

template<typename T> inline T gcd(T a, T b) {
    if(b==0) return a;
    return gcd(b, a%b);
}
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     vi          vector<int>
#define     vll         vector<ll>
#define     vs          vector<string>
#define     pb          push_back
#define     mii         map<int,int>
#define     msi         map<string,int>
#define     mll         map<ll,ll>
#define     muli        map<ull,int>
#define     mli         map<ll,int>
#define     mil         map<int,ll>
#define     umii        unordered_map<int,int>
#define     umsi        unordered_map<string,int>
#define     umll        unordered_map<ll,ll>
#define     umuli       unordered_map<ull,int>
#define     umli        unordered_map<ll,int>
#define     umil        unordered_map<int,ll>
#define     si          set<int>
#define     sll         set<ll>
#define     PQi         priority_queue<int>
#define     PQl         priority_queue<ll>
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)
int dp[205][105];
int a[206][106];
int main() {
    //freopen("input.txt","r",stdin);
    int t = Int, tc = 0 ;
    while(t--){
         mem(a);
         mem(dp);
             int n = Int;
             int f = 1 ,h = 1 ;
             for(int i = 1 ; i <= 2*n - 1 ; i++){
                  for(int j = 1 ; j <= h; j++){
                       a[i][j] = Int;
                      // cout<<a[i][j]<<" ";
                  }
                 // puts("");
                  if(i >= n)f = -1;
                  h += f;
             }
             h = 2;
             f = 1;
             for(int i = 1 ; i <= 2*n - 1 ; i++){
                  if(i == 1){
                       dp[i][i] = a[i][i];
                       continue;
                  }
                  for(int j = 1 ; j <= h ; j++){
                       if(j == 1 and i <= n)dp[i][j] = a[i][j] + dp[i-1][j];
                       else if(j == h and h != 1 and i <= n){
                            dp[i][j] = a[i][j] + dp[i-1][j-1];
                       }
                       else if(i <= n){
                            //cout<<"i = "<<i<<endl;
                            dp[i][j] = a[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
                       }
                       else if(i > n){
                            dp[i][j] = a[i][j] + max(dp[i-1][j],dp[i-1][j+1]);
                       }
                      // cout<<dp[i][j]<< " ";
                  }
                  //cout<<h << " "<<i;
                  //puts("");
                  if( i >= n )f = -1;
                  h += f;
             }
             printf("Case %d: %d\n",++tc,dp[2*n-1][1]);
    }
    return 0;
}