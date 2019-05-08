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

ll dp[33][33][66] ;
int lcs[33][33] ;
int sz_a, sz_b, sz_tot ;
string a, b ;

ll call(int i, int j, int tot){
	if(i == sz_a){
		tot += sz_b - j ;
		return tot == sz_tot ;
	}
	if(j == sz_b){
		tot += sz_a - i ;
		return tot == sz_tot ;
	}
	ll& ret = dp[i][j][tot] ;
	if(~ret)return ret ;
	ret = 0 ;
	if(a[i] == b[j])ret += call(i + 1, j + 1, tot + 1) ;
	else {
		ret += call(i + 1, j, tot + 1) ;
		ret += call(i, j + 1, tot + 1) ;
	}
	return ret ;
}

int LCS(){
	mem(lcs) ;
	string c = ' ' + a ;
	string d = ' ' + b ;
	for(int i = 1 ; c[i] ; ++i){
		for(int j = 1 ; d[j] ; ++j){
			if(c[i] == d[j])lcs[i][j] = 1 + lcs[i - 1][j - 1] ;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]) ;
		}
	}
	return lcs[sz_a][sz_b] ;
}

int main(){
    int test = Int , tc = 0 ;
    while(test--){
        cin >> a >> b ;
        printf("Case %d: ",++tc);
        sz_a = sz(a), sz_b = sz(b) ;
        int res = sz_a + sz_b - LCS() ;
        sz_tot = res ;
        memn(dp) ;
        ll ans = call(0, 0, 0) ;
        printf("%d %lld\n",res,ans);
    }
    return 0 ;
}

/*...Always look at the part - 04...*/
/*...............END................*/


