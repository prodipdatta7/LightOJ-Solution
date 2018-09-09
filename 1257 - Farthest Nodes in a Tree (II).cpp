#include<bits/stdc++.h>
using namespace std;
const int N =3e4+5;
const long long M = (long long)1e9+7;
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

vector<pii> g[N];

int dwn[N], sub[N];
int id , mv ;
void form(int s, int w, int  p = -1) {
    dwn[s] = dwn[p] + w ;
    if(dwn[s] > mv) {
        mv = dwn[s];
        id = s ;
    }
    for(int i = 0 ; i < (int)g[s].size() ; i++) {
        int v = g[s][i].ff;
        int w = g[s][i].ss;
        if(v == p)continue;
        form(v,w,s);
    }
}

void form1(int s, int w, int  p = -1) {
    sub[s] = sub[p] + w ;
    if(sub[s] > mv) {
        mv = sub[s];
        id = s ;
    }
    for(int i = 0 ; i < (int)g[s].size() ; i++) {
        int v = g[s][i].ff;
        int w = g[s][i].ss;
        if(v == p)continue;
        form1(v,w,s);
    }
}

void form2(int s, int w, int  p = -1) {
    dwn[s] = dwn[p] + w ;
    for(int i = 0 ; i < (int)g[s].size() ; i++) {
        int v = g[s][i].ff;
        int w = g[s][i].ss;
        if(v == p)continue;
        form2(v,w,s);
    }
}


int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        for(int i = 0 ; i < N ; i++) {
            g[i].clear();
            sub[i] = dwn[i] = 0;
        }
        int n = Int ;
        for(int i = 1 ; i < n ; i++) {
            int l = Int, r = Int, w = Int ;
            g[l].pb({r,w});
            g[r].pb({l,w});
        }
        form(0,0);
        int s = id ;
        mv = id = 0 ;
        mem(dwn);
        form1(s,0);
        int e = id ;
        mv = id = 0 ;
        form2(e,0);
        printf("Case %d:\n",++tc);
        for(int i = 0 ; i < n ; i++) {
            printf("%d\n",max(sub[i],dwn[i]));
        }
    }
    return 0 ;
}

