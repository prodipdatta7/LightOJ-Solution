#include<bits/stdc++.h>
using namespace std;
const int N =1e3+1;
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

int p[N];
vi id;

void pre() {
    for(int i = 1 ; i < N ; i++) {
        id.pb(i) ;
        for(int j = i ; j < N ; j += i) {
            p[j]++ ;
        }
    }
}

bool cmp(int a, int b) {
    if(p[a] == p[b])
        return a > b ;
    return p[a] < p[b] ;
}

int main() {
    pre();
    sort(all(id),cmp);
    int t = Int, tc = 0 ;
    while(t--) {
        int n = Int;
        printf("Case %d: %d\n",++tc,id[n-1]);
    }
    return 0;
}

