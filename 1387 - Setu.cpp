#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t,tc=0;
   scanf("%d",&t);
   while(t--)
   {
      int n,i,sum=0;
      char ch[10];
      scanf("%d",&n);
      printf("Case %d:\n",++tc);
      while(n--)
      {
         scanf("%s",ch);
         if(ch[0]=='d')
         {
            int k;
            scanf("%d",&k);
            sum+=k;
         }
         else
         {
            printf("%d\n",sum);
         }
      }
   }
   return 0;
}
