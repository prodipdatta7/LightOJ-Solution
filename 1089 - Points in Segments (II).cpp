#include<bits/stdc++.h>
using namespace std;
const int N =1e6+5;
const long long M = (long long)1e9+7;
#define     ll      long long
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
ll Long() {
    ll x;
    scanf("%I64d",&x);
    return x;
}
void Char(char* ch) {
    scanf("%s",ch);
}

#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     vi          vector<int>
#define     vl          vector<ll>
#define     pb          push_back
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     mem(a,b)    memset(a,b,sizeof a)

map<int,int>mp,f;
struct point {
    int l,r,id;
    point() {
        l=0,r=0,id=0;
    }
} up[N],qu[N];

int id;
vi p;

int Map(int n) {
    if(mp.find(n) == mp.end()) {
        mp[n] = ++id;
    }
    return mp[n];
}

int tree[N];

void update(int i, int n, int v) {

    while(i<=n) {
        tree[i]+=v;
        i += (i & -i);
    }
}

int ask(int i) {

    int sum = 0;
    while(i) {
        sum += tree[i] ;
        i -= (i & -i);
    }

    return sum;
}

int main() {
    int t = Int, tc = 0;
    while(t--) {
        p.clear();
        mp.clear();
        f.clear();
        id = 0 ;
        mem(tree, 0);
        int n = Int, q = Int;
        for(int i = 1 ; i <= n ; i ++) {
            int l = Int, r = Int;
            up[i].l = l,up[i].r = r,up[i].id  = i;
            p.pb(l),p.pb(r);
        }
        for(int i = 1 ; i <= q ; i ++) {
            int qq = Int ;
            p.pb(qq);
            qu[i].id = qq;
        }
        sort(all(p));
        for(int i = 0 ; i < (int) p.size() ; i++) {
            f[p[i]] = Map(p[i]);
        }
        for(int i = 1 ; i <= n ; i ++) {
            int l = f[up[i].l], r = f[up[i].r];
            update(l,id,1);
            update(r+1,id,-1);
        }
        printf("Case %d:\n",++tc);
        for(int i = 1 ; i <= q ; i ++) {
            int qq = f[qu[i].id] ;
            int ans = ask(qq);
            printf("%d\n",ans);
        }
    }
    return 0;
}

