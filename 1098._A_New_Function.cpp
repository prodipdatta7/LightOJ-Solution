#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5 ;
const double eps = 1e-9 ;
const int MAX_N = 1e7 + 5 ;
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
    int t = Int , tc = 0 ;
    while(t--) {
       ll n = Long ;
       ll res = 0 ;
       for(ll i = 2 ; i * i <= n ; i++){
            ll j = n / i ;
            res += ((i + j) * (j - i + 1) / 2LL) ;
            res += 1LL * i * (j - i) ;
       }
       printf("Case %d: %lld\n",++tc , res);
    }
    return 0;
}

