#include<bits/stdc++.h>
using namespace std;
const int N =1e3+5;
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

int a[N] ,tot ,sum ;
vector<int> g[N] ;
bool vis[N] ;
void dfs(int s) {
    sum += a[s] ;
    vis[s] = 1 ;
    tot++;
    for(int i = 0 ; i < (int) g[s].size() ; i++) {
        int to = g[s][i] ;
        if(!vis[to]) {
            dfs(to);
        }
    }
}
int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        mem(a);
        mem(vis);
        for(int i = 0 ; i < N ; i++) {
            g[i].clear();
        }
        int n = Int, m = Int ;
        for(int i = 1 ; i <= n ; i++) {
            a[i] = Int ;
        }
        for(int i = 1 ; i <= m ; i++) {
            int l = Int, r = Int ;
            g[l].pb(r);
            g[r].pb(l);
        }
        int f = 0 , eq = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            if(!vis[i]) {
                sum = tot = 0 ;
                dfs(i);
                if((sum % tot) or(eq > 0 and sum/tot != eq)) {
                    f = 1 ;
                    break;
                }
                eq = sum / tot ;
            }
        }
        if( f ) printf("Case %d: No\n",++tc);
        else printf("Case %d: Yes\n",++tc);
    }
    return 0 ;
}