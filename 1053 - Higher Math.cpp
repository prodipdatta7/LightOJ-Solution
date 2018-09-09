#include<bits/stdc++.h>
using namespace std;
int tc;
int main()
{
    long long t,n,m,d,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        n=a*a;
        m=b*b;
        d=c*c;
        if((n+m)==d||m+d==n||d+n==m)
            printf("Case %d: yes\n",++tc);
        else
            printf("Case %d: no\n",++tc);
    }
}
