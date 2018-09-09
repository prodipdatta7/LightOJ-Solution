#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
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
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     vi          vector<int>
#define     vll         vector<ll>
#define     vs          vector<string>
#define     pb          push_back
#define     PQi         priority_queue<int>
#define     PQl         priority_queue<ll>
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)

vector<int> g[N] ;
int sz[N] ;
ll res = 0;

void dfs(int s, int p = -1) {
    sz[s] = 1 ;
    ll sub = 0 ;
    int f = 0 ;
    for(int i = 0 ; i < (int)g[s].size() ; i++) {
        int to = g[s][i] ;
        if(to == p)continue ;
        dfs(to,s);
        sz[s] += sz[to] ;
        res += sub * 1LL* sz[to];
        sub += 1LL * sz[to] ;
        //f++ ;
    }
    //if(f > 1) res += sub ;
}

int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        int n = Int ;
        for(int i = 0 ; i < N ; i++) {
            g[i].clear();
            sz[i] = 0 ;
        }
        for(int i = 1; i < n ; i++) {
            int l = Int , r = Int ;
            g[l].pb(r);
            g[r].pb(l);
        }
        dfs(1);
        printf("Case %d: %d %lld\n",++tc,n-1,res);
        res = 0;
    }
    return 0 ;
}