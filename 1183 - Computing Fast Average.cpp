#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
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

struct SEG
{
	ll tree[N << 2] , lazy[N << 2];
	SEG(){
		mem(tree) ;
		mem(lazy) ;
	}
	
	void propagate(int i , int b, int e){
		if(lazy[i] != -1){
			tree[i] = 1LL * (e - b + 1) * lazy[i] ;
			if(b != e){
				lazy[i << 1] = lazy[i << 1 | 1] = lazy[i] ;
			}
			lazy[i] = -1 ;
		}
	}
	void upd(int i, int b, int e ,int l, int r, ll v){
		propagate(i,b,e);
		if(e < l or r < b)return ;
		if(l <= b and e <= r){
			tree[i] = 1LL * ( e - b + 1 ) * v ;
			if(b != e){
				lazy[i << 1] = lazy[i << 1 | 1] = v ;
			}
			return ;
		}
		int mid = ( b + e ) >> 1 ;
		upd(i << 1 , b , mid , l , r , v) ;
		upd(i << 1 | 1 , mid + 1 , e , l , r , v) ;
		tree[i] = tree[ i<< 1] + tree[i << 1 | 1] ;
	}

	ll query(int i, int b, int e, int l, int r){
		propagate(i,b,e);
		if(e < l or r < b)return 0;
		if(l <= b and e <= r){
			return tree[i];
		}
		int mid = ( b + e ) >> 1 ;
		ll x = query(i << 1 , b , mid , l , r) ;
		ll y = query(i << 1 | 1 , mid + 1 , e , l , r) ;
		return x + y ;
	}
}T;

int main() {
    int t = Int, tc = 0 ;
    while(t--) {
    	//SEG T ;
    	mem(T.tree);
    	memn(T.lazy);
    	int n = Int , q = Int ;
    	printf("Case %d:\n",++tc);
    	while(q--){
    		int f = Int ;
    		if(f == 1){
    			int l = Int + 1 , r = Int + 1 ;
    			ll v = Long ;
    			T.upd(1 , 1 , n , l , r, v) ;
    		}
    		else{
    			int l = Int + 1 , r = Int + 1 ;
    			ll res = T.query(1 , 1 , n , l , r) ;
    			ll rng = r - l + 1 ;
    			ll rr = __gcd(res , rng) ;
    			res /= rr , rng /= rr ;
    			if(rng == 1){
    				printf("%lld\n",res);
    			}
    			else{
    				printf("%lld/%lld\n",res,rng);	
    			}
    		}
    	}
    }
    return 0;
}