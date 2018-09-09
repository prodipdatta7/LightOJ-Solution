#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t,tc=0;
   scanf("%d",&t);
   getchar();
   while(t--)
   {
      string a,b;
      getline(cin,a);
      getline(cin,b);
      for(int i=0;a[i];i++)
      {
         if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
         {
            if((a[i]>='a'&&a[i]<='z'))
            {
               a[i]=a[i]-32;
            }
         }
      }
      for(int i=0;b[i];i++)
      {
         if((b[i]>='a'&&b[i]<='z')||(b[i]>='A'&&b[i]<='Z'))
         {
            if((b[i]>='a'&&b[i]<='z'))
            {
               b[i]=b[i]-32;
            }
         }
      }
      sort(a.begin(),a.end());
      sort(b.begin(),b.end());
      int i=0;
      while(a[i]==' ')
      {
         i++;
      }
      int j=0;
      while(b[j]==' ')
      {
         j++;
      }
      bool flag=false;
      //cout<<a<<endl<<b;
      for(int x=i;a[x];x++)
      {
         if(a[x]!=b[j++])
         {
            flag=true;
            break;
         }
      }
      if(flag==false)
         printf("Case %d: Yes\n",++tc);
      else
         printf("Case %d: No\n",++tc);
   }
   return 0;
}
