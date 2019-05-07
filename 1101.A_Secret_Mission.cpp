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

const int N          = (int)5e4 + 5 ;
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

vector < vector < pii > > g ;
int par[N], dep[N], root[N][16], mx[N][16] ;

struct krushkal{
    int b, e, v ;
    krushkal():b(0),e(0),v(0){}
    krushkal(int b, int e, int v):b(b),e(e),v(v){}
    bool operator<(const krushkal& p)const{
        return v < p.v ;
    }
} ;

int Find(int s){
    return par[s] = (par[s] == s) ? s : Find(par[s]) ;
}

void dfs(int s, int p, int v){
    root[s][0] = p ;
    mx[s][0] = v ;
    dep[s] = 1 + dep[p] ;
    for(int i = 1 ; i < 16 ; ++i){
        root[s][i] = root[root[s][i - 1]][i - 1] ;
        mx[s][i] = max(mx[root[s][i - 1]][i - 1],mx[s][i - 1]) ;
    }
    for(pii i : g[s]){
        if(i.ff == p)continue ;
        dfs(i.ff, s, i.ss) ;
    }
}

int getMax(int a, int b){
    if(dep[a] < dep[b])swap(a, b) ;
    int d = dep[a] - dep[b], res = 0 ;
    for(int i = 15 ; i >= 0 ; --i){
        if(d & (1 << i)){
            res = max(res, mx[a][i]) ;
            a = root[a][i] ;
        }
    }
    if(a == b)return res ;
    for(int i = 15 ; i >= 0 ; --i){
        if(root[a][i] != root[b][i]){
            res = max(res, max(mx[a][i], mx[b][i])) ;
            a = root[a][i], b = root[b][i] ;
        }
    }
    res = max(res, max(mx[a][0], mx[b][0])) ;
    return res ;
}

int main(){
    //freopen("input.txt","r",stdin) ;
    //freopen("output.txt","w",stdout) ;
    int test = Int , tc = 0 ;
    while(test--){
        int n = Int, m = Int ;
        g.clear() ;
        g.resize(n + 1) ;
        mem(par) ;
        mem(mx) ;
        mem(root) ;
        mem(dep) ;
        vector < krushkal > mst ;
        for(int i = 1 ; i <= m ; ++i){
            mst.pb({Int, Int, Int}) ;
        }
        sort(all(mst)) ;
        for(int i = 0 ; i <= n ; ++i)par[i] = i ;
        for(krushkal i : mst){
            int u = Find(i.b), v = Find(i.e) ;
            if(u != v){
                g[i.b].pb({i.e, i.v}) ;
                g[i.e].pb({i.b, i.v}) ;
                par[u] = v ;
            }
        }
        dfs(1, 0, 0) ;
        int q = Int ;
        printf("Case %d:\n",++tc);
        while(q--){
            int res = getMax(Int, Int) ;
            printf("%d\n",res);
        }
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


