#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;
const long long M = (long long)1e4+7;
const int Mod = 1e4 + 7 ;
#define     ll      long long
#define     ull     unsigned long long
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}

ll Long() {
    ll x;
    scanf("%lld",&x);
    return x;
}
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     vi          vector<int>
#define     vll         vector<ll>
#define     vs          vector<string>
#define     pb          push_back
#define     mii         map<int,int>
#define     msi         map<string,int>
#define     mll         map<ll,ll>
#define     muli        map<ull,int>
#define     mli         map<ll,int>
#define     mil         map<int,ll>
#define     umii        unordered_map<int,int>
#define     umsi        unordered_map<string,int>
#define     umll        unordered_map<ll,ll>
#define     umuli       unordered_map<ull,int>
#define     umli        unordered_map<ll,int>
#define     umil        unordered_map<int,ll>
#define     si          set<int>
#define     sll         set<ll>
#define     PQi         priority_queue<int>
#define     PQl         priority_queue<ll>
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)


void Identity(int res[][10], int n) {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(i == j)
                res[i][j] = 1 ;
            else res[i][j] = 0 ;
        }
    }
}

void MAT_MUL(int x[][10],int y[][10],int n) {
    int tmp[10][10];
    mem(tmp);
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            for(int k = 1; k <= n ; k++) {
                tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % Mod ;
                tmp[i][j] %= Mod ;
            }
        }
    }
    for(int i = 1 ; i <= 4 ; i++) {
        for(int j = 1 ; j <= 4 ; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

void Mat_Exp(int A[][10], int k, int n) {
    int res[10][10] = {0};
    Identity(res,n);
    int bas[10][10]= {0};
    for(int i = 1 ; i <= 4 ; i++) {
        for(int j = 1 ; j <= 4 ; j++) {
            bas[i][j] = A[i][j] ;
        }
    }
    while(k) {
        if(k & 1) {
            MAT_MUL(res,bas,n);
        }
        MAT_MUL(bas,bas,n);
        k >>= 1 ;
    }
    for(int i = 1 ; i <= 4 ; i++) {
        for(int j = 1 ; j <= 4 ; j++) {
            A[i][j] = res[i][j] ;
        }
    }
}

int main() {
    int t = Int , tc = 0;
    while(t--) {
        int A[10][10];
        mem(A);
        int n = Int ,a = Int, b = Int , c = Int;
        A[1][1] = a, A[1][3] = b, A[1][4] = 1 ;
        A[2][1] = A[3][2] = A[4][4] = 1 ;
        if(n <= 2) {
            printf("Case %d: 0\n",++tc);
        } else {
            int k = n - 2  ;
            Mat_Exp(A,k,4);
            int d = (A[1][4] * c) ;
            printf("Case %d: %d\n",++tc,d % Mod);
        }
    }
    return 0 ;
}

