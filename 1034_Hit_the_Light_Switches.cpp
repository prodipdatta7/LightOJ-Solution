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



//Strongly Connected Component (Kosaraju)

vector< set < int > > g , gr ;
vi used , comp , order ;

void dfs1(int s){
    used[s] = 1 ;
    for(int i : g[s]){
        if(!used[i]){
            dfs1(i);
        }
    }
    order.pb(s);
}

void dfs2(int s){
    used[s] = 1 ;
    comp.pb(s);
    for(int i : gr[s]){
        if(!used[i]){
            dfs2(i);
        }
    }
}

int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t = Int , tc = 0 ;
    while(t--) {
        int n = Int , m = Int , x, y;
        g.clear() ;
        gr.clear() ;
        used.clear() ;
        order.clear() ;
        g.resize(n + 1) ;
        gr.resize(n + 1) ;
        for(int i = 1 ; i <= m ; i++){
            x = Int ,y = Int ;
            g[x].insert(y) ;
            gr[y].insert(x) ;
        }
        used.assign(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i++){
            if(!used[i]){
                dfs1(i);
            }
        }
        used.assign(n + 1 , 0) ;
        int id = 0 ;
        vi scc(n + 1, 0) ;
        for(int i = (int)order.size() - 1 ; i >= 0 ; i--){
            int u = order[i] ;
            if(!used[u]){
                comp.clear() ;
                dfs2(u) ;
                ++id ;
                for(int j : comp){
                    scc[j] = id ;
                    //error(scc[j], j)
                }
            }
        }
        gr.clear() ;
        gr.resize(id + 1) ;
        for(int i = 1 ; i <= n ; ++i){
            for(int j : g[i]){
                if(scc[i] != scc[j]){
                    gr[scc[i]].insert(scc[j]) ;
                }
            }
        }
        int res = 0 ;
        vi deg(id + 1 , 0) ;
        for(int i = 1 ; i <= id ; ++i){
            for(int j : gr[i]){
                ++deg[j] ;
            }
        }
        for(int i = 1 ; i <= id ; ++i)if(!deg[i])++res ;
        printf("Case %d: %d\n",++tc, res);
    }
    return 0;
}


/*...Always look at the part - 04...*/
/*...............END................*/


