#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5 ;
const double eps = 1e-9 ;
const int MAX_N = 1e6 + 5 ;
const long long M = (long long)1e9+7 ;
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
template<typename t>inline t abs(t a) { if(a>=0) return a; return -a;}
template<typename t>inline t gcd(t a , t b) {return !b ? a : gcd(b , a % b);}
template<typename t>inline t lcm(t a , t b) {return a * ( b /gcd(a , b));}
template<typename T>inline T modpow(T b, T p, T Mod) {
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

template<typename T> inline T ModInv(T b, T Mod) {return modpow(b, Mod - 2, Mod );}

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
}/*
int e1 , e2 , d1 ;
template < typename T >inline void extgcd(T a , T b){
	if(!b) {e1 = 1 , e2 = 0 , d1 = a ; return ;}
	extgcd(b , a % b) ;
	T x1 = e2 ; 
	T y1 = e1 - (a / b) * e2 ;
	e1 = x1 ;
	e2 = y1 ;
}

primes in range 1 - n
1 - 100(1e2) -> 25 pimes
1 - 1000(1e3) -> 168 primes
1 - 10000(1e4) -> 1229 primes
1 - 100000(1e5) -> 9592 primes
1 - 1000000(1e6) -> 78498 primes
1 - 10000000(1e7) -> 664579 primes
large primes -> 
104729 1299709 15485863 179424673 2147483647 32416190071 112272535095293 48112959837082048697
*/
/*
std::vector<int> primes;
bitset < MAX_N > bs;
ll sieve_size = MAX_N ;

void sieve(ll n){
	bs.set() ;
	bs[0] = bs[1] = 1 ;
	for(ll i = 2 ; i <= n ; i++)if(bs[i]){
		for(ll j = i * i ; j <= n ; j += i) bs[j] = 0 ;
			primes.push_back((int)i);
	}
}

bool isprime(ll n){
	if(n <= sieve_size)return bs[n] ;
	for(int i = 0 ; i <= (int)primes.size() ; i++){
		if(n % primes[i] == 0)return false ;
	}
	return true ;
}

int numDiffPf[MAX_N] ;

void DiffPF(){
	for(int i = 2 ; i < MAX_N ; i++){
		if(numDiffPf[i] == 0){
			for(int j = i ; j < MAX_N ; j += i)numDiffPf[j]++;
		}
	}
}

int Phi[MAX_N] ;

void EulerPHI(){
	for(int i = 1 ; i < MAX_N ; i++)Phi[i] = i ;
		for(int i = 2 ; i < MAX_N ; i++)
			if(Phi[i] == i)
				for(int j = i ; j < MAX_N ; j += i)
					Phi[j] = (Phi[j]/i) * (i - 1) ;
}

int F(int x){
	return 0 ;
}
pair < int , int > floydCycle(int x0){
	int tor = F(x0) , hare = F(F(x0)) ;
	while(tor != hare){tor = F(tor) , hare = F(F(hare));}
	int mu = 0 ; hare = x0 ;
	while(tor != hare){tor = F(tor) , hare = F(hare); mu++ ;}
	int lambda = 1 ; hare = F(tor) ;
	while(tor != hare){hare = F(hare) ; lambda++;}
	return {mu , lambda} ;
}
*/
template <typename T>inline vector< T > Unique(vector< T > v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
    return v;
}
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
#define     pb			push_back
#define     eb			emplace_back
#define     all(x)      x.begin(),x.end()
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)

int fact[MAX_N][6] ;
void cal(){
	for(int i = 2 ; i <= MAX_N ; i++){
		int f = i ;
		while(f % 2 == 0){
			f /= 2 ;
			fact[i][2]++;
		}while(f % 3 == 0){
			f /= 3 ;
		}while(f % 5 == 0){
			f /= 5 ;
			fact[i][5]++;
		}
		fact[i][2] += fact[i - 1][2] ;
		fact[i][5] += fact[i - 1][5] ;
	}
	
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cal() ;
    int t = Int , tc = 0 ;
    while(t--) {
    	int n = Int , r = Int , p = Int , q = Int ;
    	int d2 = fact[n][2] - (fact[r][2] + fact[n - r][2] ) ;
    	int d5 = fact[n][5] - (fact[r][5] + fact[n - r][5] ) ;
    	int c2 = 0 , c5 = 0 ;
    	while(p % 2 == 0){
    		p /= 2 ; c2++ ;
    	}while(p % 3 == 0){
    		p /= 3 ;
    	}while(p % 5 == 0){
    		p /= 5 ; c5++ ;
    	}
    	c2 *= q , c5 *= q ;
    	int tot2 = c2 + d2 ;
    	int tot5 = c5 + d5 ;
    	printf("Case %d: %d\n" , ++tc,min(tot2 , tot5));
    }
    return 0;
}

