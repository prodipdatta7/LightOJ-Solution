#include<stdio.h>
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=10)
            printf("%d %d\n",0,n);
        else if(n<20)
            printf("%d %d\n",n%10,10);
         else
            printf("%d %d\n",10,10);
    }
    return 0;
}