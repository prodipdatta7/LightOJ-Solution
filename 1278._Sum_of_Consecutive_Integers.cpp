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


bitset < MAX_N > is_composite;
std::vector< int > pm;

void linear_sieve(){
    for(int i = 2 ; i < MAX_N ; i++){
        if(!is_composite[i])pm.push_back(i) ;
        for(int j = 0 ; j < (int)pm.size() and i * pm[j] < MAX_N ; j++){
            is_composite[i * pm[j]] = 1 ;
            if(i % pm[j] == 0)break ;
        }
    }
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

int fact(ll n){
    int res = 1 ;
    while(n % 2 == 0)n /= 2 ;
    for(int i = 1 ; i < (int)pm.size() and 1LL * pm[i] * pm[i] <= n ; i++){
        if(n % pm[i] == 0){
            int cnt = 0 ;
            while(n % pm[i] == 0){
                n /= pm[i] ;
                cnt++ ;
            }
            res *= (cnt + 1) ;
        }
    }
    if(n > 1)res <<= 1 ;
    return res - 1 ;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    linear_sieve() ;
    int t = Int , tc = 0 ;
    while(t--) {
       ll n = Long ;
       printf("Case %d: %d\n",++tc , fact(n));
    }
    return 0;
}

