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
    cerr<<it->substr((*it)[0]==' ',it->length())<< " = " << a << " ";
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
#define     Block        1000

int cur_ans=0,cnt[N];
int ans[N];
int a[N];
struct Mo {
    int l,r,id;
} q[N];
bool cmp(Mo A,Mo B) {
    if(A.l/Block!=B.l/Block)
        return A.l/Block < B.l/Block;
    return A.r<B.r;
}

void add(int x) {
    cnt[x]++;
    if(cnt[x]==1)cur_ans++;
}
void remove(int x) {
    cnt[x]--;
    if(cnt[x]==0)cur_ans--;
}
int main() {
    int t=Int,tc=0;
    while(t--) {
        memset(a,0,sizeof a);
        memset(q,0,sizeof q);
        memset(ans,0,sizeof ans);
        memset(cnt,0,sizeof cnt);
        cur_ans=0;
        int n=Int;
        int Q=Int;
        for(int i=0; i<n; i++) {
            a[i]=Int;
        }

        for(int i=0; i<Q; i++) {
            q[i].l=Int-1,q[i].r=Int-1,q[i].id=i;
        }
        sort(q,q+Q,cmp);
        int mo_l=0,mo_r=-1;
        for(int i=0; i<Q; i++) {
            int lft=q[i].l;
            int rgt=q[i].r;
            while(mo_r<rgt) {
                mo_r++;
                add(a[mo_r]);
            }
            while(mo_r>rgt) {
                remove(a[mo_r]);
                mo_r--;
            }
            while(mo_l<lft) {
                remove(a[mo_l]);
                mo_l++;
            }
            while(mo_l>lft) {
                mo_l--;
                add(a[mo_l]);
            }
            // error(q[i].id,cur_ans);
            ans[q[i].id]=cur_ans;
        }
        printf("Case %d:\n",++tc);
        for(int i=0; i<Q; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
