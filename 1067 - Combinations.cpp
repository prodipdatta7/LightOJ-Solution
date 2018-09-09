#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e6+3;
#define ll long long
ll Bigmod(ll A,ll B,ll C) {
    if(B==0LL)return 1LL;
    ll x=Bigmod(A,B/2LL,C);
    x=(x*x)%C;
    if(B%2==1)
        x=(x*A)%C;
    return x;
}
long long dp[N];
void solve() {
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=N; i++) {
        dp[i]=(dp[i-1]*i);
        if(dp[i]>M)
            dp[i]%=M;
        // cerr<<dp[i]<<" ";
    }
}
int main() {
    solve();
    int t,tc=0;
    scanf("%d",&t);
    while(t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        long long a=dp[k]*dp[n-k];
        long long mod=Bigmod(a,M-2,M);
        long long y=(dp[n]*mod)%M;
        printf("Case %d: %d\n",++tc,y);
    }
    return 0;
}
