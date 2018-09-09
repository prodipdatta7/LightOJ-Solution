#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool pal(ll n)
{
    ll m=n,a[14],i=0,j=0;
    while(m)
    {
        a[++i]=m%10;
        m/=10;
    }
    //cout<<i<<endl;
    while(n)
    {
        if(a[i]!=n%10)
            return false;
        n/=10;
        i--;
    }
    return true;
}
int main()
{

    int tc,t=0;
    scanf("%d",&tc);
    while(tc--)
    {

        ll n;
        scanf("%lld",&n);
        bool ans=pal(n);
        if(ans==true)
        {
            printf("Case %d: Yes\n",++t);
        }
        else
            printf("Case %d: No\n",++t);
    }
    return 0;
}
