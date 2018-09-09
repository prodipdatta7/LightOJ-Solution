#include<bits/stdc++.h>
using namespace std;
const int N =1e6+5;
int tree[N];
int lazy[N<<2];
void build(int n,char *ch) {
    for(int i=1; i<=n; i++)
        tree[i]=ch[i-1]-'0';
}
void update(int id,int l,int r,int x,int y) {
    if(l>r)return;
    if(lazy[id]!=0) {
        if(l!=r) {
            lazy[id*2]+=lazy[id];
            lazy[id*2+1]+=lazy[id];
            lazy[id]=0;
        }

    }
    if(x>r or y<l)return;
    if(x<=l and r<=y) {
        lazy[id]++;
        return;
    }
    int mid=(l+r)>>1;
    update(id*2,l,mid,x,y);
    update(id*2+1,mid+1,r,x,y);
}
int query(int id,int l,int r,int x,int y) {
    if(l>r) return 0;
    if(lazy[id]!=0) {
        if(l!=r) {
            lazy[id*2]+=lazy[id];
            lazy[id*2+1]+=lazy[id];
            lazy[id]=0;
        }
    }
    if(x>r or y<l)return 0;
    if(x<=l and r<=y) {
        //cerr<<tree[x]<<endl;
        if(lazy[id]&1)
            return tree[x]^1;
        else
            return tree[x];
    }
    int mid=(l+r)>>1;
    return max(query(id*2,l,mid,x,y),query(id*2+1,mid+1,r,x,y));
}
int main() {
    int t,tc=0;
    cin>>t;
    while(t--) {
        memset(lazy,0,sizeof lazy);
        memset(tree,0,sizeof tree);
        printf("Case %d:\n",++tc);
        char ch[N];
        scanf("%s",ch);
        int n=strlen(ch);
        build(n,ch);
        int m;
        scanf("%d",&m);
        while(m--) {
            char s[2];
            scanf("%s",s);
            if(s[0]=='Q') {
                int l;
                scanf("%d",&l);
                printf("%d\n",query(1,1,n,l,l));
            } else {
                int l,r;
                scanf("%d%d",&l,&r);
                update(1,1,n,l,r);
            }
        }
    }
    return 0;
}


