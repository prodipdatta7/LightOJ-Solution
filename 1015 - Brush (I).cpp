#include<stdio.h>
int main()
    {
    int n,i,sum,t,k,j=0;
    scanf("%d",&t);
    //printf("\n\n");
    while(t--)
        {
        sum=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            {
            scanf("%d",&k);
            if(k>=0)
                sum+=k;
            }
        printf("Case %d: %d\n",++j,sum);
        }
    return 0;
    }
