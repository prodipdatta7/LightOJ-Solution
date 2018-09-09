#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;
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
// ///error///
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
// ///This DEBUGGER-tool need c++11///
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define     pb		push_back
#define     all(x)      x.begin(),x.end()
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)


set<int>st;
struct SEG
{
	int tree[N << 2] ;
	void propagate(int i , int b, int e){
		if(tree[i]){
			if(b != e){
				tree[i << 1] = tree[i << 1 | 1] = tree[i] ;
                tree[i] = 0 ;
			}
			
		}
	}
	void upd(int i, int b, int e ,int l, int r, int v){
		propagate(i,b,e);
		if(e < l or r < b)return ;
		if(l <= b and e <= r){
			if(b != e){
				tree[i << 1] = tree[i << 1 | 1] = v ;
                tree[i] = 0 ;
			}
            else{
                tree[i] = v ;
            }
			return ;
		}
		int mid = ( b + e ) >> 1 ;
		upd(i << 1 , b , mid , l , r , v) ;
		upd(i << 1 | 1 , mid + 1 , e , l , r , v) ;
		//tree[i] = tree[ i<< 1] + tree[i << 1 | 1] ;
	}

	void query(int i, int b, int e, int p){
		propagate(i,b,e);
		if(e < p or p < b)return ;
		if(p == b and e == b){
            if(tree[i])
			     st.insert(tree[i]);
            return ;
		}
		int mid = ( b + e ) >> 1 ;
		query(i << 1 , b , mid , p) ;
		query(i << 1 | 1 , mid + 1 , e , p) ;
	}
}T;

int main() {
    int t = Int, tc = 0 ;
    while(t--) {
    	//SEG T ;
    	mem(T.tree);
    	int q = Int ;
        int n = 2 * q ;
        int i = 0 ;
        st.clear();
    	while(q--){
    		int l = Int, r = Int ;
            T.upd(1,1,n,l,r,++i);
    	}
        for(int i = 1 ; i <= (n) ; i++){
            T.query( 1 , 1, n, i);
        }
        printf("Case %d: %d\n",++tc,(int)st.size());
    }
    return 0;
}
