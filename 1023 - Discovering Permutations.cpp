#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
const long long M = (long long)1e9+7;
typedef     long long       ll;
int Int() {
    int x;
    scanf("%d",&x);
    return x;
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
#define     sq(a)       (a)*(a)
vector<int> per ;
int chosen[N], n, m , cnt ;
void Search() {
    if(per.size() == n) {
        cnt++;
        if(cnt > m)return ;
        for(int i = 0 ; i < (int)per.size() ; i++) {
            printf("%c",per[i] + 64);
        }
        puts("");
    } else {
        for(int i = 1 ; i <= n ; i++) {
            if(chosen[i])continue ;
            chosen[i] = 1 ;
            per.pb(i);
            Search() ;
            if(cnt > m)return;
            chosen[i] = 0 ;
            per.pop_back();
        }
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    int t = Int, tc = 0 ;
    while(t--) {
        n = Int , m = Int ;
        cnt = 0 ;
        memset(chosen,0,sizeof chosen);
        per.clear();
        printf("Case %d:\n",++tc);
        Search();
    }
    return 0;
}

