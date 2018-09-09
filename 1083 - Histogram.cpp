#include<bits/stdc++.h>
using namespace std;
const int N =1e6+5;
const long long M = (long long)1e9+7;
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

int a[N];
struct Htg {
    int l,r;
} P[N];
int main() {
    int t=Int,tc=0;
    while(t--) {
        int n;
        scanf("%d",&n);
        ll sum=1,mx=0;
        stack<int>st;
        for(int i=1; i<=n; i++) {
            a[i]=Int;
        }
        for(int i=1; i<=n; i++) {
            int x=a[i];
            if(!st.size()) {
                st.push(i);
                P[i].l=i;
            } else {

                if(x<=a[st.top()]) {
                    while(x<=a[st.top()]) {
                        st.pop();
                        if(st.empty())
                            break;
                    }
                    if(!st.empty()) {
                        P[i].l=st.top()+1;
                        st.push(i);
                    } else {
                        P[i].l=1;
                        st.push(i);
                    }

                } else {
                    st.push(i);
                    P[i].l=i;
                }
            }
            //error(P[i].l,i);
        }
        stack<int>TS;
        for(int i=n; i>=1; i--) {
            int x=a[i];
            if(!TS.size()) {
                TS.push(i);
                P[i].r=i;
            } else {

                if(x<=a[TS.top()]) {
                    while(x<=a[TS.top()]) {
                        TS.pop();
                        if(TS.empty())
                            break;
                    }
                    if(!TS.empty())
                        P[i].r=TS.top()-1;
                    else
                        P[i].r=n;
                    TS.push(i);
                } else {
                    TS.push(i);
                    P[i].r=i;
                }
            }
            //error(P[i].r,i);
        }
        for(int i=1; i<=n; i++) {
            int v=P[i].r-P[i].l+1;
            mx=max(mx,1LL*v*1LL*a[i]);
        }
        printf("Case %d: %lld\n",++tc,mx);
    }
    return 0;
}


