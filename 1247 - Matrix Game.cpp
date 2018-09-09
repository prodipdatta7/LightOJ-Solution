#include<bits/stdc++.h>
using namespace std;
const int N =1e6+5;
const long long M = (long long)1e9+7;
typedef     long long       ll;
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     vi          vector<int>
#define     vl          vector<ll>
#define     pb          push_back
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     sq(a)       (a)*(a)

int main() {
    int t = Int , tc = 0;
    while(t--) {
        int n = Int, m = Int , res = 0 ;
        for(int i = 1 ; i <= n ; i++) {
            int sum = 0 ;
            for(int j = 1 ; j <= m ; j++) {
                int x = Int ;
                sum += x ;
            }
            res ^= sum ;
        }
        if(res){
            printf("Case %d: Alice\n",++tc);
        }
        else{
            printf("Case %d: Bob\n",++tc);
        }
    }
    return 0;
}

