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
msi mp;
struct data {
    int l, r, c ;
    data() {
        l = r = c = 0 ;
    }
    bool operator<(const data& p)const {
        return c < p.c ;
    }
} tree[250];
int par[1000];
void pre() {
    for(int i = 0 ; i <= 100; i++) {
        par[i] = i ;
    }
}

int Find(int s) {
    return (par[s] == s) ? s : par[s] = Find(par[s]) ;
}
int Krushkal(int n,int m) {
    sort(tree+1, tree+m+1);
    int cost = 0 ;
    for(int i = 1 ; i <= m ; i++ ) {
        int x = tree[i].l, y = tree[i].r, z = tree[i].c ;
        int u = Find(x), v = Find(y);
        if(u != v) {
            par[u] = v ;
            cost += z ;
            n--;
            if(n == 1)
                return cost ;
        }
    }
    return -1 ;

}

int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        mp.clear();
        pre();
        int n = Int , cnt = 0;
        for(int i = 1 ; i <= n ; i++) {
            string a ,b ;
            cin >> a >> b ;
            int cost = Int ;
            if(mp.find(a) == mp.end()) {
                cnt++;
                mp[a] = cnt;
            }
            if(mp.find(b) == mp.end()) {
                cnt++;
                mp[b] = cnt;
            }
            tree[i].l = mp[a];
            tree[i].r = mp[b];
            tree[i].c = cost ;
        }
        int res = Krushkal(cnt,n);
        if(res == -1)printf("Case %d: Impossible\n",++tc);
        else printf("Case %d: %d\n",++tc,res);
    }
    return 0 ;
}

