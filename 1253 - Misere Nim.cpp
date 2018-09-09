#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
const long long M = (long long)1e18+7;
#define     ll      long long
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
ll Long() {
    ll x;
    scanf("%I64d",&x);
    return x;
}
void Char(char* ch) {
    scanf("%s",ch);
}
template<typename t>t abs(t a) {
    if(a>=0)return a;
    return -a;
}/*
///error///
#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s,char c) {
    vector<string>v;
    stringstream ss(s);
    string x;
    while(getline(ss,x,c))
        v.emplace_back(x);
    return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T,typename... Args>
void err(vector<string>::iterator it,T a,Args...args) {
    cout<<it->substr((*it)[0]==' ',it->length())<< " = " << a << " ";
    err(++it,args...);
}*/
///This DEBUGGER-tool need c++11///
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

int main() {
    int t=Int,tc=0;
    while(t--) {
        int n=Int;
        int a[n+1];
        for(int i=1; i<=n; i++)
            a[i]=Int;
        sort(a+1,a+n+1);
        if(a[1]==a[n] and a[1]==1) {
            if(n&1)
                printf("Case %d: Bob\n",++tc);
            else
                printf("Case %d: Alice\n",++tc);
        } else {
            int xr=0;
            for(int i=1; i<=n; i++) {
                xr^=a[i];
            }
            if(xr)
                printf("Case %d: Alice\n",++tc);
            else
                printf("Case %d: Bob\n",++tc);
        }
    }
    return 0;
}

