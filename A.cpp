/*...Part - 01...*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
//#include <bits/stdc++.h>
using namespace std ;

/*...Part - 02...*/

typedef long long               ll ;
typedef long double             ld ;
typedef unsigned long long      ull ;
typedef pair<int,int>           pii ;
typedef pair<ll,ll>             pll ;
typedef vector<int>             vi ;
typedef vector<ll>              vll ;
typedef vector<vector<int>>     vvi ;

int Int(){int x ; scanf("%d",&x) ; return x ;}
ll Long(){ll x ; scanf("%lld",&x) ; return x ;}

/*...Part - 03...*/
/*....Debugger....*/

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

/*...Part - 04...*/
/*...Needed to change according to problem requirements...*/

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;

/*..........................................................*/
/*...Part - 05...*/

#define     debug(x)    cerr << #x << " = " << x << '\n' ;
#define     rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
#define     Int         Int()
#define     Long        Long()
#define     all(x)      x.begin() , x.end()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

/*...Part - 06...*/
/*...... ! Code start from here ! ......*/

vvi g ;
int d[N], low[N], vis[N], col[N] ;
int cur , tt , ttm, ans;

void init(int n){
    g.clear() ;
    g.resize(n) ;
}

void add(int x , int y){
    g[x].pb(y) ; g[y].pb(x) ;
}


struct DSU{
    static const int n = (int)2e5 + 6 ;
    int par[n], Rank[n];
    void init(){
        for(int i = 0 ; i < n ; ++i){
            par[i] = i, Rank[i] = 1 ;
        }
    }
    int Find(int s){
        return par[s] == s ? s : par[s] = Find(par[s]) ;
    }
    void Union(int x , int y){
        int u = Find(x), v = Find(y) ;
        if(u != v){
            if(Rank[u] >= Rank[v]){
                par[v] = u , Rank[u] += Rank[v] ;
            }
            else par[u] = v , Rank[v] += Rank[u] ;
        }
    }
}D;


void dfs(int s , int p = -1){
    vis[s] = ttm ;
    d[s] = low[s] = ++cur ;
    for(int i : g[s]){
        if(i == p)continue ;
        else if(vis[i] == ttm)low[s] = min(low[s], d[i]) ;
        else {
            dfs(i, s) ;
            low[s] = min(low[s], low[i]) ;
        }
        if(d[s] >= low[i]){
            D.Union(s , i) ;
        }
    }   
}

bool isBicolorable(int s, int p){
    col[s] = (col[p] == 1) ? 2 : 1 ;
    bool res = true ;
    int u = D.Find(s) ;
    for(int i : g[s]){
        int v = D.Find(i) ;
        if(u != v or i == p)continue ;
        if(col[i] > 0){
            if(col[i] == col[s])return false ;
        }
        else {
            res &= isBicolorable(i, s) ;
        }
    }
    return res ;
}

int solve(int n, int m){
    ++ttm ;
    cur = ans = 0 ;
    D.init() ;
    for(int i = 1 ; i <= n ; ++i){
        if(vis[i] != ttm)dfs(i) ;
    }
    int res = 0 ;
    mem(col) ;
    vi track(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; ++i){
        int x = D.Find(i) ;
        if(track[x] == 0 and col[i] == 0){
            track[x] = 1 ;
            if(isBicolorable(i,0) == false){
                res += D.Rank[x] ;
            }
        }
    }
    return res ;
}


int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int test = Int , tc = 0 ;
    while(test--){
        int n = Int , m = Int ;
        init(n + 1) ;
        for(int i = 0 ; i < m ; ++i){
            int x = Int , y = Int ;
            add(x + 1,y + 1) ;
        }
        int res = solve(n, m) ;
        printf("Case %d: %d\n",++tc, res);
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


