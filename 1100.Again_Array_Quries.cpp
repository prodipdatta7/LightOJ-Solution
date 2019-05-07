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

const int block = 350 ;
int a[N], ans[N], res, n ;

struct MO{
    int l, r, id ;
    MO():l(0),r(0),id(0){}
    MO(int l, int r, int id):l(l), r(r), id(id){}
    bool operator<(const MO& p)const{
        return make_pair(l / block, r) < make_pair(p.l / block , p.r) ;
    }
} ;


int main(){
    int test = Int , tc = 0 ;
    while(test--){
        int n = Int, q = Int ;
        vector < MO > Q ;
        for(int i = 0 ; i < n ; ++i){
            a[i] = Int ;
        }
        for(int i = 0 ; i < q ; ++i){
            int l = Int, r = Int ;
            Q.pb({l, r, i}) ;
        }
        sort(all(Q)) ;
        int cl = 0, cr = -1 ;
        vi cnt(1005, 0) ;
        for(MO i : Q){
            while(cl > i.l)cnt[a[--cl]]++ ;
            while(cr < i.r)++cnt[a[++cr]] ;
            while(cl < i.l)--cnt[a[cl++]] ;
            while(cr > i.r)--cnt[a[cr--]] ;
            int p = 0, res = inf ;
            for(int i = 1 ; i <= 1000 ; ++i){
                if(!cnt[i])continue ;
                if(cnt[i] > 1){
                    res = 0 ;
                    break ;
                }
                if(p)res = min(res, i - p) ;
                p = i ;
            }
            ans[i.id] = res ;
        }
        printf("Case %d:\n",++tc);
        for(int i = 0 ; i < q ; ++i){
            printf("%d\n",ans[i]);
        }
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


