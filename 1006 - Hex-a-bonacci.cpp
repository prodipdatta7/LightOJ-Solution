#include<bits/stdc++.h>
using namespace std;
const int N =1e4+5;
const long long M = (long long)1e7+7;
const int Mod = (int)1e7+7;
#define     ll      long long
#define     ull     unsigned long long
int Int() {
    int x;
    scanf("%d",&x);
    return x;
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
#define     PQi         priority_queue<int>
#define     PQl         priority_queue<ll>
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)

int main() {
    int t = Int, tc = 0;
    while(t--) {
        int a[N] ;
        ll sum = 0 ;
        for(int i = 0 ; i <= 5 ; i++) {
            a[i] = Int ;
            sum += 1LL * a[i];
            sum %= M ;
        }
        int n = Int ;
        if(n <= 5) {
            printf("Case %d: %d\n",++tc,a[n] % M);
        } else {
            for(int i = 6 ; i <= n ; i++) {
                a[i] = sum ;
                sum = (sum - 1LL* a[i - 6] + 1LL* a[i]) % M;
            }
            printf("Case %d: %d\n",++tc,(a[n] + M) % M);
        }
    }
    return 0 ;
}

