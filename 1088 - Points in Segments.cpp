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
vector<int> Unique(vector<int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
    return v;
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

int tree[N];

void upd(int i, int n) {
    while(i <= n ) {
        tree[i]++;
        i += (i & -i) ;
    }
}

int ask(int i) {
    int s = 0 ;
    while(i) {
        s += tree[i];
        i -= (i & -i) ;
    }
    return s ;
}

int main() {
    int t = Int , tc = 0 ;
    while(t--) {
        mem(tree);
        int n = Int, q = Int ;
        int a[n + 1];
        for(int i = 1 ; i <= n ; i++) {
            a[i] = Int ;
        }
        vector<int>v(a + 1, a + n + 1);
        pair<int,int>p[q + 1];
        for(int i = 1 ; i <= q ; i++) {
            p[i].ff = Int, p[i].ss = Int ;
            v.pb(p[i].ff);
            v.pb(p[i].ss);
        }
        v = Unique(v) ;
        map<int,int> mp;
        int id = 0;
        for(int i = 0; i < (int)v.size() ; i++) {
            if(mp.find(v[i]) == mp.end()) {
                mp[v[i]] = ++id;
            }
        }
        int m = (int)v.size() ;
        for(int i = 1 ; i <= n ; i++) {
            a[i] = mp[a[i]];
            upd(a[i],m);
        }
        printf("Case %d:\n",++tc);
        for(int i = 1 ; i <= q ; i++) {
            int d = ask(mp[p[i].ff] - 1);
            int f = ask(mp[p[i].ss]);
            printf("%d\n",f - d) ;
        }
    }
    return 0 ;
}

