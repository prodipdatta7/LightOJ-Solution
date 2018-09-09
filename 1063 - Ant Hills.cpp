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

void Char(char* ch) {
    scanf("%s",ch);
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

vector<int> g[N] ;

int tmr, low[N], in[N], P[N] ;

void dfs(int s, int p = -1) {
    int child = 0 ;
    low[s] = in[s] = ++tmr ;
    for(int i = 0 ; i < (int)g[s].size(); i++) {
        int to = g[s][i];
        if(to == p)continue;
        else if(in[to]) {
            low[s] = min(low[s],in[to]);
        } else {
            child++;
            dfs(to,s);
            low[s] = min(low[s],low[to]);
            if(low[to] >= in[s] and p != -1)P[s] = 1 ;
        }
    }
    if(child > 1 and p == -1)P[s] = 1 ;
}

int main() {
    int t = Int, tc = 0;
    while(t--) {
        for(int i = 0 ; i < N ; i++) {
            g[i].clear();
        }
        mem(low);
        mem(in);
        mem(P);
        tmr = 0 ;
        int n = Int, m = Int ;
        for(int i = 1; i <= m ; i++) {
            int l = Int, r = Int ;
            g[l].pb(r);
            g[r].pb(l);
        }
        int res = 0;
        for(int i = 1 ; i<= n ; i++) {
            if(!in[i])dfs(i);
            res += P[i];
        }
        printf("Case %d: %d\n",++tc,res);
    }
    return 0 ;
}

