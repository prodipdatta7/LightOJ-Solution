#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long M = (long long)1e9+7;
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
void Char(char* ch) {
    scanf("%s",ch);
}
template<typename t>inline t abs(t a) {
    if(a>=0)
        return a;
    return -a;
}
template<typename T> inline T modpow(T b, T p, T Mod) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
            res %= Mod ;
        }
        b *= b;
        b %= Mod;
        p >>= 1;
    }
    return res ;
}

template<typename T> inline T ModInv(T b, T Mod) {
    return modpow(b, Mod - 2, Mod );
}

template<typename T> inline T pwr(T b, T p) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
        }
        b *= b;
        p >>= 1;
    }
    return res ;
}

template<typename T> inline T gcd(T a, T b) {
    if(b==0)
        return a;
    return gcd(b, a%b);
}

template <typename T> inline void Int(T &n) {
    n = 0;
    int f = 1;
    register int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isdigit(ch); ch = getchar())
        n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}
template<typename T, typename U> inline void Int(T &a, U &b) {
    Int(a);
    Int(b);
}
template<typename T, typename U, typename W> inline void Int(T &a, U &b, W &c) {
    Int(a,b);
    Int(c);
}
template<typename T, typename U, typename W,typename X> inline void Int(T &a, U &b, W &c, X &d) {
    Int(a,b,c);
    Int(d);
}
vector<int> Unique(vector<int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
    return v;
}
///error///
// #define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
// vector<string> split(const string &s,char c) {
//     vector<string>v;
//     stringstream ss(s);
//     string x;
//     while(getline(ss,x,c))
//         v.emplace_back(x);
//     return move(v);
// }

// void err(vector<string>::iterator it) {}
// template<typename T,typename... Args>
// void err(vector<string>::iterator it,T a,Args...args) {
//     cout<<it->substr((*it)[0]==' ',it->length())<< " = " << a << " ";
//     err(++it,args...);
// }
///This DEBUGGER-tool need c++11///
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     pb		push_back
#define     all(x)      x.begin(),x.end()
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)

struct trie
{
	int cnt , stop ;
	trie *tree[11] ;
	trie(){
		cnt = stop = 0 ;
		for(int i = 1 ; i <= 10 ; i++){
			tree[i] = NULL ;
		}
	}
}*root;

bool add(char *ch){
	trie *cur = root ;
	int f = 0 ;
	for(int i = 0 ; ch[i] ; i++){
		int id = ch[i] - '0' + 1;
		if(cur -> tree[id] == NULL){
			cur -> tree[id] = new trie() ;
		}
		if(cur -> stop)f = 1 ;
		cur = cur -> tree[id] ;cur -> cnt++;
	}
	cur -> stop++;
	if(cur -> stop > 1 or f)return 0 ;
	for(int i = 1 ; i <= 10; i++){
		if(cur -> tree[i] != NULL)return 0 ;
	}
	return 1 ;
}

void del(trie * cur){
    for(int i = 0 ; i < 11 ; i++){
        if(cur -> tree[i]){
            del(cur -> tree[i]);
        }
    }
    delete cur ;
}

int main() {
    int t = Int , tc = 0 ;
    while(t--) {
    	root = new trie() ;
    	int n = Int ,res = 1;
    	for(int i = 1 ; i <= n ; i++){
    		char ch[11] ;
    		scanf("%s",ch);
    		res &= add(ch);
    	}
    	if(res)printf("Case %d: YES\n",++tc);
    	else printf("Case %d: NO\n",++tc);
        del(root);
    }
    return 0;
}
