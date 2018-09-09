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
template<typename t>inline t abs(t a) {
    if(a>=0)return a;
    return -a;
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

template <typename T> inline void Int(T &n) {
    n = 0;
    int f = 1;
    register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}
template<typename T, typename U> inline void Int(T &a, U &b) {
    Int(a);
    Int(b);
}
template<typename T, typename U, typename W> inline void Int(T &a, U &b, W &c) {
    Int(a,b);
    Int(c);
}
template<typename T, typename U, typename W,typename X> inline void Int(T &a, U &b, W &c, X &d) {
    Int(a,b,c);
    Int(d);
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
bool vis[24][24];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
string s[25];
bool valid(int r, int c, int n, int m) {
    return (r >= 0 and r < n  and c >= 0 and c < m) ? 1 : 0 ;
}
int bfs(int r, int c, int n, int m) {
    queue< pair<int,int> > q;
    memset(vis, 0, sizeof vis);
    int cnt = 1 ;
    vis[r][c] = 1 ;
    q.push({r,c});
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        for(int i = 0 ; i < 4; i++) {
            int x = p.ff + dx[i];
            int y = p.ss + dy[i];
            if(valid(x,y,n,m)) {
                if(s[x][y] == '.' and !vis[x][y]) {
                    q.push({x,y});
                    vis[x][y] = 1;
                    cnt++;
                }
            }
        }
    }
    return cnt ;
}
int main() {
    int t = Int, tc = 0;
    while(t--) {
        int n = Int, m = Int,r = 0,c = 0;
        for(int i = 0; i < m ; i++) {
            cin >> s[i] ;
            if( !r and !c ) {
                for(int j = 0 ; s[i][j] ; j++) {
                    if(s[i][j] == '@' ) {
                        r = i, c = j ;
                        break;
                    }
                }
            }
        }
        int res = bfs(r,c,m,n);
        printf("Case %d: %d\n",++tc,res);
    }
    return 0;
}

