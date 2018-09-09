#include<bits/stdc++.h>
using namespace std;
const int N =1e5+6;
#define ll long long
ll tree[N<<2],lazy[N<<2];
void update(ll i,ll l,ll r,ll x,ll y,ll v) {
    if(l>r)return;
    if(lazy[i]!=0) {
        tree[i]+=(lazy[i]*(r-l+1));
        if(l!=r) {
            lazy[i*2]+=lazy[i];
            lazy[i*2+1]+=lazy[i];
        }
        lazy[i]=0;
    }
    ll m=(l+r)>>1;
    if(x>r or y<l)return;
    if(x<=l and r<=y) {
        tree[i]+=v*(r-l+1);
        if(l!=r) {
            lazy[i*2]+=v;
            lazy[i*2+1]+=v;
        }
        return;
    }
    update(i*2,l,m,x,y,v);
    update(i*2+1,m+1,r,x,y,v);
    tree[i]=tree[i*2]+tree[i*2+1];
}
ll query(ll i,ll l,ll r,ll x,ll y) {
    if(l>r)return 0;
    if(lazy[i]!=0) {
        tree[i]+=(lazy[i]*(r-l+1));
        if(l!=r) {
        lazy[i*2]+=lazy[i];
            lazy[i*2+1]+=lazy[i];
        }
        lazy[i]=0;
    }
    ll m=(l+r)>>1;
    if(x>r or y<l)return 0;
    if(x<=l and r<=y) {
        return tree[i];
    }
    ll p=query(i*2,l,m,x,y);
    ll q=query(i*2+1,m+1,r,x,y);
    return p+q;
}
int main() {
    int t,tc=0;
    scanf("%d",&t);
    while(t--) {
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        printf("Case %d:\n",++tc);
        ll n,m;
        scanf("%lld%lld",&n,&m);
        while(m--) {
            int d;
            scanf("%d",&d);
            if(d==0) {
                ll l,r,k;
                scanf("%lld%lld%lld",&l,&r,&k);
                update(1,1,n,l+1,r+1,k);
            } else {
                ll l,r;
                scanf("%lld%lld",&l,&r);
                printf("%lld\n",query(1,1,n,l+1,r+1));
            }
        }
    }
    return 0;
}
