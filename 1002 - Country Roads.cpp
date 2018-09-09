#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;
const long long M = (long long)1e9+7;
#define     ll      long long
#define     ull     unsigned long long
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
#define     Int         Int()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     pb          push_back

vector<pii> g[550];
int vis[550], res[550];
void bfs(int s) {
    priority_queue< pii > q;
    q.push({0,s});
    res[s] = 0 ;
    while(!q.empty()) {
        int u = q.top().ss;
        vis[u] = 1 ;
        q.pop();
        for(int i = 0 ; i < (int)g[u].size(); i++) {
            int v = g[u][i].ff ;
            int c = g[u][i].ss ;
            int x = max(res[u],c);
            if(res[v] > x) {
                res[v] = x ;
                if(!vis[v])q.push({-res[v],v});
            }
        }
    }
}

int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        for(int i = 0 ; i < 550 ; i++) {
            g[i].clear();
            res[i] = INT_MAX;
            vis[i] = 0 ;
        }
        int n = Int, m =Int ;
        for(int i = 1 ; i <= m ; i++) {
            int l = Int, r = Int, w = Int ;
            g[l].pb({r,w});
            g[r].pb({l,w});
        }
        int s = Int ;
        bfs(s);
        printf("Case %d:\n",++tc);
        for(int i = 0 ; i < n ; i++) {
            if(res[i] == INT_MAX)puts("Impossible");
            else printf("%d\n",res[i]);
        }
    }
    return 0 ;
}