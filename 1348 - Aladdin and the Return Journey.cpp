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
int a[N] , dep[N] , par[N][20] , tree[2][N << 2];
vi T[2] ;
int be[N] , en[N] , len[N];

void dfs(int s , int p = 0){
    dep[s] = 1 + dep[p] ;
    par[s][0] = p ;
    len[s] = 1 ;
    T[0].pb(s) ;
    be[s] = sz(T[0]) - 1 ;
    for(int i = 1 ; i < 20 ; ++i){
        par[s][i] = par[par[s][i - 1]][i - 1] ;
    }
    for(int i : g[s]){
        if(i == p)continue ;
        dfs(i , s) ;
        len[s] += len[i] ;
    }
    T[1].pb(s) ;
    en[s] = sz(T[1]) - 1 ;
}

int LCA(int a , int b){
    if(dep[a] < dep[b])swap(a , b) ;
    int d = dep[a] - dep[b] ;
    for(int i = 19 ; i >= 0 ; --i){
        if(d & (1 << i)){
            a = par[a][i] ;
        }
    }
    if(a == b)return a ;
    for(int i = 19 ; i >= 0 ; --i){
        if(par[a][i] != par[b][i]){
            a = par[a][i] ;
            b = par[b][i] ;
        }
    }
    return par[a][0] ;
}

void build(int id , int i , int b , int e){
    if(b == e){
        tree[id][i] = a[T[id][b]] ;
        return ;
    }
    int mid = (b + e) >> 1 ;
    build(id , i << 1 , b , mid) ;
    build(id , i << 1 | 1 , mid + 1 , e) ;
    tree[id][i] = tree[id][i << 1] + tree[id][i << 1 | 1] ;
}

void upd(int id , int i , int b , int e , int p , int v){
    if(b > p or e < p)return ;
    if(b == p and e == p){
        tree[id][i] = v ;
        return ;
    }
    int mid = (b + e) >> 1 ;
    upd(id , i << 1 , b , mid , p , v) ;
    upd(id , i << 1 | 1 , mid + 1 , e , p , v) ;
    tree[id][i] = tree[id][i << 1] + tree[id][i << 1 | 1] ;
}

int query(int id , int i , int b , int e , int l , int r){
    if(b > r or e < l)return 0;
    if(l <= b and e <= r){
        return tree[id][i] ;
    }

    int mid = (b + e) >> 1 ;
    int x = query(id , i << 1 , b, mid, l, r) ;
    int y = query(id , i << 1 | 1 , mid + 1, e, l, r) ;
    return x + y ;
}


int main(){
    int test = Int , tc = 0 ;
    while(test--){
        int n = Int ;
        g.clear() ;
        mem(tree) ;
        mem(len) ;
        mem(dep) ;
        mem(par) ;
        mem(en) ;
        mem(be) ;
        mem(a) ;
        T[0].clear() ;
        T[1].clear() ;
        g.resize(n + 1) ;
        for(int i = 1 ; i <= n ; ++i)
            a[i] = Int ;
        for(int i = 1 ; i < n ; ++i){
            int x = Int + 1 , y = Int + 1 ;
            g[x].pb(y) ;
            g[y].pb(x) ;
        }
        T[0].pb(0) ;
        T[1].pb(0) ;
        dfs(1) ;
        build(0 , 1 , 1 , n) ;
        build(1 , 1 , 1 , n) ;
        int q = Int ;
        printf("Case %d:\n",++tc);
        while(q--){
            int typ = Int ;
            if(typ){
                int i = Int + 1 , v = Int ;
                upd(0 , 1 , 1 , n , be[i] , v) ;
                upd(1 , 1 , 1 , n , en[i] , v) ;
            }
            else{
                int i = Int + 1 , j = Int + 1 ;
                int anc = LCA(i , j) ;
                int x = be[i] + len[i] - 1  ;
                int y = be[j] + len[j] - 1  ;
                int z = be[anc] + len[anc] - 1 ;
                int up = query(0 , 1 , 1 , n , 1 , x) - query(1 , 1 , 1 , n , 1 , en[i] - 1) ;
                up += query(0 , 1 , 1 , n , 1 , y) - query(1 , 1 , 1 , n , 1 , en[j] - 1) ;
                up -= 2 * (query(0 , 1 , 1 , n , 1 , z) - query(1 , 1 , 1 , n , 1 , en[anc] - 1)) ;
                up += query(0 , 1 , 1 , n , be[anc] , be[anc]) ;
                printf("%d\n",up);
            }
        }
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


