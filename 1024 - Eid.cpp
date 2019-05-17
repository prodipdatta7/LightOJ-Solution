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

vector < int > v, pm, cur ;
int b[10005] ;

void multiply(int x){
    int c = 0 ;
    for(int &i : v){
        int xx = i * x + c ;
        i = xx % 10 ;
        c = xx / 10 ;
    }
    while(c){
        v.pb(c % 10) ;
        c /= 10 ;
    }
}

bool prime(int x){
    for(int i = 2 ; i * i <= x ; ++i)
        if(x % i == 0)return 0 ;
    return 1 ;
}

void factorize(int n){
    for(int i : pm){
        if(i * i > n)break ;
        if(n % i == 0){
            int cnt = 0 ;
            while(n % i == 0){
                n /= i ;
                ++cnt ;
            }
            cur.pb(i) ;
            b[i] = max(b[i], cnt) ;
        }
    }
    if(n > 1)b[n] = max(b[n], 1), cur.pb(n) ;
}

int main(){
    for(int i = 2; i <= 100 ; ++i){
        if(prime(i))pm.pb(i) ;
    }
    int test = Int , tc = 0 ;
    while(test--){
        v.clear() ;
        cur.clear() ;
        v.pb(1) ;
        int n = Int ;
        for(int i = 1 ; i <= n ; ++i){
            factorize(Int) ;
        }
        sort(all(cur)) ;
        cur.resize(unique(all(cur)) - cur.begin()) ;
        for(int i : cur){
            while(b[i]--){
                multiply(i) ;
            }
        }
        printf("Case %d: ",++tc);
        for(int i = sz(v) - 1 ; i >= 0 ; --i)printf("%d",v[i]);
        cout << '\n' ;
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/

