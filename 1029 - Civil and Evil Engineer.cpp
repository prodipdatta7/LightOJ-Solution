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

struct cost {
    int w , x, y;
};

bool choto(cost A ,cost B) {
    return A.w < B.w;
}

bool boro(cost A ,cost B) {
    return A.w > B.w;
}

int par[N],edge;
void pre() {
    for(int i = 0 ; i < N ; i++) {
        par[i] = i ;
    }
}
vector<cost> g ;

int Find(int s) {
    if(par[s] == s)return s;
    return par[s] = Find(par[s]) ;
}

int MST(int n) {
    int mx = 0 , mn = 0 , nod = 0;
    sort(all(g),choto);
    pre();
    for(int i = 0 ; i < edge ; i++) {
        cost u = g[i];
        int l = Find(u.x);
        int r = Find(u.y);
        if(l != r) {
            mn += u.w;
            nod++;
            par[l] = r ;
            if(nod == n)
                break;
        }
    }
    pre();
    sort(all(g),boro);
    nod = 0;
    for(int i = 0 ; i < edge ; i++) {
        cost u = g[i];
        int l = Find(u.x);
        int r = Find(u.y);
        if(l != r) {
            mx += u.w;
            nod++;
            par[l] = r ;
            if(nod == n)
                break;
        }
    }
    return mn + mx ;
}
int main() {
    int t = Int , tc = 0 ;
    while(t--) {
        g.clear();
        int n = Int ;
        int x , y ,  w ;
        edge = 0 ;
        while(scanf("%d %d %d",&x,&y,&w) == 3 and(x or y or w)) {
            cost p;
            p.w = w,p.x = x ,p.y = y;
            g.pb(p);
            edge++;
        }
        int res = MST(n);
       // cout<<res<<endl;
        if(res & 1)printf("Case %d: %d/2\n",++tc,res);
        else printf("Case %d: %d\n",++tc,res/2);
    }
    return 0 ;
}

