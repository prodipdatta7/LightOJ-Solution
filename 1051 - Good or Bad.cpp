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

char s[55] ;
int dp[55][5][6], n, bad ;

bool isVowel(char c){
    return c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U' ;
}

int call(int p, int v, int c){
    if(v == 3 or c == 5){
        bad = 1 ;
        return 0 ;
    }
    if(p == n)return 1 ;
    int& ret = dp[p][v][c] ;
    if(~ret)return ret ;
    ret = 0 ;
    if(s[p] == '?'){
        ret |= call(p + 1, v + 1, 0) | call(p + 1, 0, c + 1) ;
    }
    else{
        int f = isVowel(s[p]) ;
        if(f){
            ret |= call(p + 1,v + 1, 0) ;
        }
        else {
            ret |= call(p + 1, 0, c + 1) ;
        }
    }
    return ret ;
} 

int main(){
    int test = Int , tc = 0 ;
    while(test--){
        memn(dp) ;
        scanf("%s",s) ;
        n = strlen(s) ;
        bad = 0 ;
        int res = call(0, 0, 0) ;
        printf("Case %d: ",++tc);
        if(bad and res)puts("MIXED") ;
        else if(res)puts("GOOD") ;
        else puts("BAD") ;
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


