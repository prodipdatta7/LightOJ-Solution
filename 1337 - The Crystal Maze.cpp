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
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

string s[506];
bool valid(int r,int c,int n,int m) {
    return r >= 0 and r <n and c >= 0 and c < m and s[r][c] != '#';
}

int res[500], vis[505][505], id;

void bfs(int r, int c, int n, int m) {
    queue<pii> q;
    q.push({r,c});
    vis[r][c] = ++id;
    int cnt = 0 ;
    if(s[r][c] == 'C')cnt++;
    while(!q.empty()) {
        pii u = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++) {
            int x = u.ff + dx[i];
            int y = u.ss + dy[i] ;
            if(!vis[x][y] and valid(x,y,n,m)) {
                vis[x][y] = id ;
                q.push({x,y});
                if(s[x][y] == 'C')
                    cnt++;
            }
        }
    }
    res[id] = cnt ;
}

int main() {
    int t = Int , tc = 0;
    while(t--) {
        id = 0 ;
        mem(res);
        mem(vis);
        int n = Int, m = Int, Q = Int;
        for(int i = 0 ; i < n ; i++) {
            s[i].clear();
            cin >> s[i] ;
        }
        printf("Case %d:\n",++tc);
        while(Q--) {
            int r = Int - 1, c = Int - 1;
            if(!vis[r][c]) {
                bfs(r,c,n,m);
            }
            //error(vis[r][c])
            printf("%d\n",res[vis[r][c]]);
        }
    }
    return 0 ;
}

