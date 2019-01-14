#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5 ;
const double eps = 1e-9 ;
const int MAX_N = 1e8 + 5 ;
const int inf = 2e9 ; 
const long long Inf = (long long)1e18 ;
const long long M = (long long)1e9+7 ;
#define     ll      long long
#define     ull     unsigned long long
#define        ignore    continue
#define        exit    break
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
ll Long() {
    ll x;
    scanf("%lld",&x);
    return x;
}


ll is_composite[MAX_N / 64] ;
unsigned int pre[5761500] ;
int pm[5761500] , cnt = 0 ;

void linear_sieve(){
    pm[0] = 2 ;
    pre[0] = 2 ;//printf("%u %d\n",pre[cnt] , cnt);
    for(ll i = 3 ; i * i < MAX_N ; i += 2){
        if(!(is_composite[i / 64] & (1LL << (i % 64)))){
            for(ll j = i * i ; j < MAX_N ; j += (i + i)){
                is_composite[j / 64] |= (1LL << (j % 64)) ;
            }
        }
    }
    //cout << pre[0] << ' ' << pre[1] << '\n' ;
    for(ll i = 3 ; i < MAX_N ; i += 2){
        if(!(is_composite[i / 64] & (1LL << (i % 64)))){
            pre[++cnt] = pre[cnt - 1] * i ;
            pm[cnt] = i ;
          //   if(cnt < 10){
          //       cout << cnt << ' ' << pm[cnt] << '\n' ;
          //       cout << pre[cnt] << ' ' << pre[cnt - 1] << ' ' << pm[cnt] << ' ' << i << '\n' ;
          //   }
        }
    }
    cnt++;
}
#define     Int                 Int()
#define     Long                Long()
#define     pii                 pair<int,int>
#define     ff                  first
#define     ss                  second
#define     pb                  push_back
#define     eb                  emplace_back
#define     all(x)              x.begin(),x.end()
#define     mem(a)              memset(a,0,sizeof a)
#define     memn(a)             memset(a,-1,sizeof a)


int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    linear_sieve() ;
    int t = Int , tc = 0 ;
    while(t--) {
       int n = Int ;
       unsigned int res = 1 ;
       for(int i = 0 ; i < cnt and  pm[i] * pm[i] <= n ; ++i){
            int cn = 0 ;
            int m = n ;
            while(m >= pm[i]){
                cn++ ;
                m /= pm[i] ;
                if(cn > 1)res *= pm[i] ;
                //cout << pm[i] << ' ' << cn << '\n' ;
            }
       }
       int u = upper_bound(pm , pm + cnt , n) - pm ;
       u-- ;
       //cout << res << '\n' ;
       //cout << pre[u] << ' ' << n << '\n' ;
       res *= pre[u];
       printf("Case %d: %u\n",++tc , res);
    }
    return 0;
}

