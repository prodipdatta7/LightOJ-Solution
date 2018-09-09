#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
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
    return -1*a;
}
template<typename T> inline T modpow(T b, T p, T Mod) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
            res %= Mod ;
        }
        b *= b;
        b %= Mod;
        p >>= 1;
    }
    return res ;
}

template<typename T> inline T ModInv(T b, T Mod) {
    return modpow(b, Mod - 2, Mod );
}

template<typename T> inline T pwr(T b, T p) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
        }
        b *= b;
        p >>= 1;
    }
    return res ;
}

template<typename T> inline T gcd(T a, T b) {
    if(b==0) return a;
    return gcd(b, a%b);
}
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     vi          vector<int>
#define     vll         vector<ll>
#define     vs          vector<string>
#define     pb          push_back
#define     mii         map<int,int>
#define     msi         map<string,int>
#define     mll         map<ll,ll>
#define     muli        map<ull,int>
#define     mli         map<ll,int>
#define     mil         map<int,ll>
#define     umii        unordered_map<int,int>
#define     umsi        unordered_map<string,int>
#define     umll        unordered_map<ll,ll>
#define     umuli       unordered_map<ull,int>
#define     umli        unordered_map<ll,int>
#define     umil        unordered_map<int,ll>
#define     si          set<int>
#define     sll         set<ll>
#define     PQi         priority_queue<int>
#define     PQl         priority_queue<ll>
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)

bool v[N];
ll sp[N],id;

void sieve(){
     for(int i = 2 ; i <= N ; i+=2)
     v[i] = 1 ;
     sp[++id] = 2 ;
     for(int i = 3 ; i < N ; i+=2){
          if(!v[i]){
               sp[++id] = i;
               for(ll j =1LL * i*i ; j< N ; j+=i*2){
                    v[j] = 1 ;
               }
          }
     }
}
int power(ll n) {
     int res = 0 ;if(n==1)return 1;
     for(int i = 1 ; i <= id ; i++){
          if(sp[i] > n)break;
          int cnt = 0 ;
          while(n % (sp[i]) == 0){
               cnt++;
               n /= (sp[i]);
          }
          //cout<<cnt<<endl;
          res = __gcd(res,cnt);
     }
     //cout<<n<<endl;
     if(n > 1)res = 1 ;
     return res;
}
int D(int n){
     int mx = 0;
     for(int i = 2 ; i * i <= n ; i++){
          if(n % i == 0){
               if((n/i) % 2)
               return max(n/i,mx);
               else if(i & 1)mx = max(mx,i);
          }
     }
     if(mx)return mx;
     return 1 ;
}
int main() {
    //freopen("input.txt","r",stdin);
    sieve();
    int t = Int, tc = 0 ;
    while(t--){
             ll n = Long , m = n ;
             int ans = power(abs(n));
            // cout<<abs(n)<<endl;
             if(n < 0){
                  if(ans % 2 ==0){
                       ans = D(ans);
                  }
             }
             printf("Case %d: %d\n",++tc,ans);
    }
    return 0;
}