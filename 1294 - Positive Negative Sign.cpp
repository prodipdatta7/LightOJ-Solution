#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,t=0;
    scanf("%d",&tc);
    while(tc--) {
        long long n,m,i,j,a=0,b=0,d=0;
        scanf("%lld %lld",&n,&m);
        long long y,x=(n/(2*m));
        y=(m*(m+1))/2;
        d=2*m*m;
        a=(x*(2*y+(x-1)*d))/2;
        y=y+(m*m);
        b=(x*(2*y+(x-1)*d))/2;
        printf("Case %d: %lld\n",++t,(b-a));
    }
    return 0;
}
