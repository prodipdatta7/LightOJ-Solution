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
    int t = Int, tc = 0 ;
    while(t--) {
        int n = Int ;
        char ch[n] ;
        scanf("%s",ch);
        int cnt = 0 , res = 0 ;
        for(int i = 0 ; ch[i] ; i++) {
            if(ch[i] == '.') {
                cnt++;
            } else {
                if(cnt) {
                    res += (cnt/3) ;
                    if(cnt % 3) {
                        res++;
                        int x = cnt % 3 ;
                        if(x == 1)i++;
                    }
                    cnt = 0 ;
                }
            }
        }
        if(cnt) {
            res += (cnt/3) ;
            if(cnt % 3) {
                res++;
            }
        }
        printf("Case %d: %d\n",++tc,res);
    }
    return 0 ;
}