#include<stdio.h>
int main()
{
    int T,n,m,s,t,j,k=0,q,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        scanf("%d",&q);
        printf("Case %d:\n",++k);
        for(j=1; j<=q; j++)
        {
            scanf("%d%d",&x,&y);
            if(x>=n&&x<=s&&y>=m&&y<=t)
                printf("Yes\n");
            else
                printf("No\n");
        }

    }
    return 0;

}
