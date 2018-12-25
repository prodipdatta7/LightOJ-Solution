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

const int N          = (int)1e4 + 5 ;
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

struct dsu{
    int par[N] ;
    void init(){
        for(int i = 0 ; i < N ; ++i)par[i] = i ;
    }
    
    int Find(int s){
        return par[s] == s ? s : par[s] = Find(par[s]) ;
    }

    void Union(int x , int y){
        int u = Find(x) ;
        int v = Find(y) ;
        if(u != v){
            par[u] = v ;
        }
    }
}H;

vvi g ;
int low[N], d[N], col[N], vis[N], cur, tt ;
vector < pii > bridge ;

void Trajan(int s, int p = 0){
    d[s] = low[s] = ++cur ;
    vis[s] = tt ;
    int cnt = 0 ;
    for(int i : g[s]){
        if(i == p){
            ++cnt ;
            if(cnt == 1)continue ;
            else if(cnt > 1)low[s] = min(low[s], d[i]) ;
        }
        else if(vis[i] == tt)low[s] = min(low[s], d[i]) ;
        else Trajan(i, s) ;
        low[s] = min(low[s], low[i]) ;
        if(d[s] < low[i])bridge.pb({i , s}) ;
        else H.Union(i, s) ;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test = Int , tc = 0 ;
    while(test--){
        int n = Int, m = Int ;
        g.clear() ;
        mem(low) ;
        mem(d) ;
        g.resize(n + 1) ;
        for(int i = 1 ; i <= m ; ++i){
            int x = Int + 1, y = Int + 1 ;
            g[x].pb(y) ;
            g[y].pb(x) ;
        }
        cur = 0 ;
        ++tt ;
        bridge.clear() ;
        H.init() ;
        Trajan(1) ;
        mem(col) ;
        int id = 0 ;
        for(int i = 1 ; i <= n ; ++i){
            int x = H.Find(i) ;
            if(!col[x])col[x] = ++id ;
        }
        vi f(id + 1) ;
        for(pii i : bridge){
            int x = H.Find(i.ff), y = H.Find(i.ss) ;
            f[col[x]]++ ;
            f[col[y]]++ ;
        }
        int res = 0 ;
        for(int i = 1 ; i <= id ; ++i){
            if(f[i] == 1)++res ;
        }
        printf("Case %d: %d\n",++tc, (res + 1) >> 1);
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


