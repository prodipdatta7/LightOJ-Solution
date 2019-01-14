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
/*#include <bits/stdc++.h>*/
using namespace std ;

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
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}

const int N         = (int)2e5 + 5 ;
const int maxN      = (int)1e6 + 6 ;
const ll Mod        = (ll)1e9 + 7 ;

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

ll dp[16][1 << 16] ;
int n , a[20][20];

ll call(int pos , int mask){
    if(pos == n){
        return 0 ;
    }
    ll& ret = dp[pos][mask] ;
    if(~ret)return ret ;
    ret = 0 ;
    for(int i = 0 ; i < n ; ++i){
        if(!(mask & (1 << i)))ret = max(ret , call(pos + 1 , mask | (1 << i)) + a[pos][i]) ;
    }
    return ret ;
}

int main(){
    int test = Int , tc = 0 ;
    while(test--){
        n = Int ;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                a[i][j] = Int ;
            }
        }
        memset(dp , -1 , sizeof dp) ;
        ll res = 0;
        for(int i = 0 ; i < n ; ++i){
            res = max(res , call(1 , 1 << i) + a[0][i]) ;
        }
        printf("Case %d: %lld\n",++tc , res);
    }
    return 0 ;
}
