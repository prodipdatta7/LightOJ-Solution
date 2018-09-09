#include<bits/stdc++.h>
using namespace std;
const int N =2e2+5;
const long long M = (long long)1e9+7;
#define     ll      long long
#define     ull     unsigned long long
int Int() {
    int x;
    scanf("%d",&x);
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
#define     PQi         priority_queue<int>
#define     PQl         priority_queue<ll>
#define     all(x)      x.begin(),x.end()
#define     LB          lower_bound
#define     UB          upper_bound
#define     Mx(a,b)     (a>b)?a:b
#define     Mn(a,b)     (a<b)?a:b
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int fired[N][N], jane[N][N];
string s[N] ;
vector< pii > F;

bool valid(int r , int c, int n, int m) {
    return (r >=0 and r < n and c >=0 and c < m and s[r][c] != '#');
}

void Fire(int n, int m) {
    for(int i = 0 ; i < (int)F.size() ; i++) {
        int r = F[i].ff;
        int c = F[i].ss;
        queue< pii > q ;
        q.push({r,c});
        fired[r][c] = 0;
        while(!q.empty()) {
            int x = q.front().ff;
            int y = q.front().ss;
            q.pop();
            for(int j = 0 ; j < 4 ; j++) {
                int a = x + dx[j] ;
                int b = y + dy[j] ;
                if(valid(a,b,n,m) and (fired[a][b] == -1 or fired[a][b] > fired[x][y] + 1) ) {
                    fired[a][b] = fired[x][y] + 1 ;
                    q.push({a,b});
                }
            }
        }
    }
}

int Jane(int r, int c, int n, int m) {
    queue< pii > qq ;
    qq.push({r,c});
    jane[r][c] = 0;
    int mx = INT_MAX;
    while(!qq.empty()) {
        int x = qq.front().ff;
        int y = qq.front().ss;
        qq.pop();
        for(int i = 0 ; i < 4 ; i++) {
            int a = x + dx[i] ;
            int b = y + dy[i] ;
            if(valid(a,b,n,m) and jane[a][b] == -1 ) {
                if(fired[a][b] != -1) {
                    if(fired[a][b] > jane[x][y] + 1) {
                        jane[a][b] = jane[x][y] + 1 ;
                        qq.push({a,b});
                        if(a == n - 1 or a == 0 or b == 0 or b == m - 1) {
                            mx = min(mx,jane[a][b]);
                        }
                    }
                } else {
                    jane[a][b] = jane[x][y] + 1 ;
                    qq.push({a,b});
                    if(a == n - 1 or a == 0 or b == 0 or b == m - 1) {
                        mx = min(mx,jane[a][b]);
                    }
                }
            }
        }
    }
    if(mx == INT_MAX)return 0;
    return mx ;
}
int main() {
    int t = Int , tc = 0 ;
    while(t--) {
        memn(fired);
        memn(jane);
        F.clear() ;
        int n = Int, m =Int ;
        int J[2] = {0};
        for(int i = 0 ; i < n ; i++) {
            s[i].clear();
            cin >> s[i] ;
            for(int j = 0 ; s[i][j] ; j++) {
                if(s[i][j] == 'F') {
                    F.pb({i,j});
                }
                if(s[i][j] == 'J') {
                    J[0] = i, J[1] = j ;
                }
            }
        }
        if(s[J[0]][J[1]] == 'F') {
            printf("Case %d: IMPOSSIBLE\n",++tc);
            continue ;
        }
        if(J[0] == 0 or J[1] == 0 or J[0] == n-1 or J[1] == m-1) {
            printf("Case %d: 1\n",++tc);
            continue;
        }
        Fire(n,m);
        int res = Jane(J[0],J[1],n,m);
        if(res == 0)
            printf("Case %d: IMPOSSIBLE\n",++tc);
        else
            printf("Case %d: %d\n",++tc,res + 1);
    }
    return 0 ;
}

