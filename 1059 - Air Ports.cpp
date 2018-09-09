#include<bits/stdc++.h>
using namespace std;
const int N =1e4+5;
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

vector<pii> g[N];
bool vis[N] ;
int f;
int Prims(int s,int A) {
    priority_queue< pii, vector< pii > , greater< pii > > pq;
    pq.push({0,s});
    int cost = 0 ;
    vis[s] = 1 ;
    while(!pq.empty()) {
        int u = pq.top().ss;
        int cc = pq.top().ff;
        if(!vis[u]) {
            if(cc >= A)f++,cost += A ;
            else cost += cc ;
            vis[u] = 1 ;
        }
        pq.pop();
        for(int i = 0 ; i < (int) g[u].size(); i++) {
            int v = g[u][i].ss;
            int co = g[u][i].ff;
            if(!vis[v]) {
                pq.push({co,v});
            }
        }
    }
    return cost ;
}

int main() {
    //freopen("in.txt","r",stdin);
    int t = Int, tc = 0;
    while(t--) {
        for(int i = 0 ; i < N ; i++) {
            g[i].clear();
        }
        mem(vis);
        int n = Int, m = Int, A = Int ;
        for(int i = 1 ; i <= m ; i++) {
            int l = Int, r = Int, c = Int ;
            g[l].pb({c,r});
            g[r].pb({c,l});
        }
        int cost = 0;
        f = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            if(!vis[i]) {
                cost += A + Prims(i,A);
                f++;
            }
        }
        printf("Case %d: %d %d\n",++tc,cost,f);
    }
    return 0 ;
}

