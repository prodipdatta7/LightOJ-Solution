#include<bits/stdc++.h>
using namespace std;
const int N =2e4+5;
const long long M = (long long)1e9+7;
#define     ll      long long
#define     ull     unsigned long long
int Int() {
    int x;
    scanf("%d",&x);
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
int deg[N];

int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        for(int i = 0 ; i < N ; i++) {
            g[i].clear();
            deg[i] = 0 ;
        }
        map< string, int > mp;
        int n = Int , id = 0;
        for(int i = 1 ; i <= n ; i++) {
            string a, b;
            cin >> a >> b ;
            if(mp.find(a) == mp.end()) {
                mp[a] = ++id;
            }
            if(mp.find(b) == mp.end()) {
                mp[b] = ++id;
            }
            g[mp[a]].pb(mp[b]);
            deg[mp[b]]++;
        }
        queue<int>q;
        for(int i = 1 ; i <= id; i++) {
            if(deg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            deg[u] = - 1;
            q.pop();
            for(int i = 0 ; i < (int)g[u].size(); i++) {
                int v = g[u][i];
                deg[v]--;
                if(deg[v] == 0)q.push(v);
            }
        }
        int f = 0 ;
        for(int i = 1 ; i <= id ; i++) {
            if(deg[i] != -1) {
                f = 1 ;
                break;
            }
        }
        printf("Case %d: ",++tc);
        if(f)puts("No");
        else puts("Yes");
    }
    return 0 ;
}