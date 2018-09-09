#include<bits/stdc++.h>
using namespace std;
int tc;
int main()
{
    int t,n,m,k,i,j;
    cin>>t;
    while(t--)
    {
        int sum=0;
        cin>>n>>m;
        sum+=abs(n-m)*4;
        sum+=11;
        sum+=(n*4)+8;
        printf("Case %d: %d\n",++tc,sum);

    }
}
