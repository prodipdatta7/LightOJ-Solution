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

ll dp[20][20][2][2] ;
int vis[20][20][2][2], len, tt;
vi digit ;

ll call(int pos, int tot, int isStart, int flag){
    if(pos == len)return tot ;
    ll& ret = dp[pos][tot][isStart][flag] ;
    int& v = vis[pos][tot][isStart][flag] ;
    if(v == tt)return ret ;
    v = tt ;
    ret = 0 ;
    int limit = (flag) ? digit[pos] : 9 ;
    for(int i = 0 ; i <= limit ; ++i){
        if(!i and !isStart){
            ret += call(pos + 1, tot, 0, flag and i == limit) ;
        }
        else{
            ret += call(pos + 1, tot + (!i) , isStart | (i > 0), flag and i == limit) ;
        }
    }
    return ret ;
}

ll solve(ll x){
    if(x < 0)return 0 ;
    if(x <= 9)return 1 ;
    digit.clear() ;
    len = 0 ;
    while(x){
        digit.pb(x % 10) ;
        x /= 10 ;
        ++len ;
    }
    reverse(all(digit)) ;
    ++tt ;
    return call(0, 0, 0, 1) + 1 ;
}

int main(){
    int test = Int , tc = 0 ;
    while(test--){
        ll a = Long, b = Long ;
        ll res = solve(b) - solve(a - 1) ;
        printf("Case %d: %lld\n",++tc, res);
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


