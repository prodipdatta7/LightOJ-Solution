#include<bits/stdc++.h>
using namespace std;
const int N =1e5+6;
struct node {
    int mn,mx,df;
} tree[N<<2];
int a[N];
void build(int i,int l,int r) {
    if(l==r) {
        tree[i].mn=a[l];
        tree[i].mx=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].mn=min(tree[i*2].mn,tree[i*2+1].mn);
    tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
}
node query(int i,int l,int r,int x,int y) {
    if(x>r or y<l) {
        node q;
        q.mn=INT_MAX;
        q.mx=INT_MIN;
        return q;
    }
    if(x<=l and r<=y) {
        return tree[i];
    }
    int mid=(l+r)>>1;
    node u=query(i*2,l,mid,x,y);
    node v=query(i*2+1,mid+1,r,x,y);
    node w;
    w.mn=min(u.mn,v.mn);
    w.mx=max(u.mx,v.mx);
    return w;
}
int main() {
    int t,tc=0;
    cin>>t;
    while(t--) {
        memset(tree,0,sizeof tree);
        memset(a,0,sizeof a);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        int ans=INT_MIN;
        for(int i=1; i+m-1<=n; i++) {
            node tmp=query(1,1,n,i,i+m-1);
            ans=max(ans,tmp.mx-tmp.mn);
        }
        printf("Case %d: %d\n",++tc,ans);
    }
    return 0;
}

