#include<stdio.h>
int main() {
    int n,m,t,k=0;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        printf("Case %d: %d\n",++k,n+m);
    }
    return 0;
}
