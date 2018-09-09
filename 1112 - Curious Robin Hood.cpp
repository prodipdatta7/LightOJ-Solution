#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int sum[4*N],num[N];
void build(int i,int L,int R)
{
    sum[i]=0;
    if(L==R)
    {
        sum[i]=num[L];
        return;
    }
    int mid=(L+R)>>1;
    build(i<<1,L,mid);
    build(i*2+1,mid+1,R);
    sum[i]=sum[i*2]+sum[i*2+1];
}
void update(int i,int L,int R,int pos,int u)
{
    if(L==R)
    {
        sum[i]+=u;
        return ;
    }
    int mid=(L+R)>>1;
    if(pos<=mid)
        update(i*2,L,mid,pos,u);
    else
        update(i*2+1,mid+1,R,pos,u);
    sum[i]=sum[i*2]+sum[i*2+1];
}
void update1(int i,int L,int R,int pos,int u)
{
    if(L==R)
    {
        sum[i]=u;
        return ;
    }
    int mid=(L+R)>>1;
    if(pos<=mid)
        update1(i*2,L,mid,pos,u);
    else
        update1(i*2+1,mid+1,R,pos,u);
    sum[i]=sum[i*2]+sum[i*2+1];
}
int query(int i,int L,int R,int l,int r)
{
    if(r<L||R<l)
        return 0;
    if(l<=L&&R<=r)
        return sum[i];
    int mid=(L+R)>>1;
    int x=query(i*2,L,mid,l,r);
    int y=query(i*2+1,mid+1,R,l,r);
    return x+y;
}
int g;
int main()
{
    int n,m,i,l,r,t;
    cin>>t;
    while(t--)
    {
        printf("Case %d:\n",++g);
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        cin>>n>>m;
        for(i=1; i<=n; i++)
            cin>>num[i];
        build(1,1,n);
        while(m--)
        {
            scanf("%d",&i);
            if(i==1)
            {
                scanf("%d",&l);
                printf("%d\n",query(1,1,n,l+1,l+1));
                update1(1,1,n,l+1,0);
            }
            else if(i==2)
            {
                int x,y;
                scanf("%d %d",&x,&y);
                update(1,1,n,x+1,y);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,1,n,l+1,r+1));
            }
        }
    }
}
