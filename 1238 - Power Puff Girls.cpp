#include<bits/stdc++.h>
using namespace std;
const int N = 30;
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
#define     Int         Int()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     memn(a)     memset(a,-1,sizeof a)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int puff[N][N] ;
string s[N] ;

int PowerPuffGirls(int r, int c) {
    queue<pii>q;
    q.push({r,c});
    puff[r][c] = 0 ;
    int mn = INT_MAX;
    while(!q.empty()) {
        int x = q.front().ff ;
        int y = q.front().ss ;
        q.pop();
        if(s[x][y] == 'h') {
            mn = min(mn,puff[x][y]);
        } else {
            for(int i = 0 ; i < 4 ; i++) {
                int a = x + dx[i] ;
                int b = y + dy[i] ;
                if(s[a][b] != '#' and s[a][b] != 'm' and puff[a][b] == -1) {
                    puff[a][b] = puff[x][y] + 1 ;
                    q.push({a,b});
                }
            }
        }
    }
    return mn ;
}

int main() {
    int t = Int, tc = 0 ;
    while(t--) {
        int n = Int, m = Int ;
        pii p[4] ;
        for(int i = 0; i < n ; i++) {
            s[i].clear() ;
            cin >> s[i] ;
            for(int j = 0 ; s[i][j] ; j++) {
                if(s[i][j] == 'a') {
                    p[0] = {i,j};
                } else if(s[i][j] == 'b') {
                    p[1] = {i,j};
                } else if(s[i][j] == 'c') {
                    p[2] = {i,j};
                }
            }
        }
        int res = 0 ;
        for(int i = 0 ; i < 3 ; i++) {
            memn(puff);
            res = max(res,PowerPuffGirls(p[i].ff,p[i].ss));
        }
        printf("Case %d: %d\n",++tc,res) ;
    }
    return 0 ;
}