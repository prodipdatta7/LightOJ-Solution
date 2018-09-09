#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;
const long long M = (long long)1e9+7;
#define     ll      long long
#define     ull     unsigned long long
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
void Char(char* ch) {
    scanf("%s",ch);
}
template<typename t>inline t abs(t a) {
    if(a>=0)return a;
    return -a;
}
template<typename t>inline t gcd(t a, t b) {
    return !b ? a : gcd(b, a%b);
}
#define     Int         Int()
#define     Long        Long()


int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        ll n = Long, m = Long, x = Long, y = Long ;
        ll a = 1LL*(x - n), b = 1LL*(y - m)  ;
        printf("Case %d: %lld\n",++tc,gcd(abs(a),abs(b)) + 1LL );
    }
    return 0;
}

