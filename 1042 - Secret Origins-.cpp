#include<bits/stdc++.h>
 
using namespace std;
 
typedef unsigned int uint_t;
uint_t snoob(uint_t x)
{
 
  uint_t rightOne;
  uint_t nextHigherOneBit;
  uint_t rightOnesPattern;
 
  uint_t next = 0;
 
  if(x)
  {
    rightOne = x & -(signed)x;
    nextHigherOneBit = x + rightOne;
    rightOnesPattern = x ^ nextHigherOneBit;
    rightOnesPattern = (rightOnesPattern)/rightOne;
    rightOnesPattern >>= 2;
    next = nextHigherOneBit | rightOnesPattern;
  }
 
  return next;
}
 
int main()
{
  int t, tc = 0;
  scanf("%d",&t);
  while(t--){
  	int n ; 
  	scanf("%d",&n);
  	printf("Case %d: %llu\n",++tc,snoob(n));
  }
  return 0;
}