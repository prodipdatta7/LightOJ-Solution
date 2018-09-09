#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d",&a,&b);
        c=(b-a+1);
        int ans=(c/3)*2;
        if(c%3)
        {
            int x=a%3,z=c%3;
            if(x==2)
            {
                ans+=z;
            }
            else if(x==1)
            {
                ans+=(z>1);
            }
            else
            {
                ans++;
            }

        }
        printf("Case %d: %d\n",++tc,ans);
    }
    return 0;
}
