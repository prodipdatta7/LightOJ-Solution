#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
struct Point
{
    double x,y;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
double dist(Point a,Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
//两个圆的公共部分面积
double Area_of_overlap(Point c1,double r1,Point c2,double r2)
{
    double d = dist(c1,c2);
    if(r1 + r2 < d + eps)return 0;
    if(d < fabs(r1 - r2) + eps)
    {
        double r = min(r1,r2);
        return PI*r*r;
    }
    double x = (d*d + r1*r1 - r2*r2)/(2*d);
    double t1 = acos(x / r1);
    double t2 = acos((d - x)/r2);
    return r1*r1*t1 + r2*r2*t2 - d*r1*sin(t1);
 }
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    Point c1,c2;
    double r1,r2;
    int T;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        iCase ++;
        c1.input();
       scanf("%lf",&r1);
        c2.input();
        scanf("%lf",&r2);
       printf("Case %d: %.6lf\n",iCase,Area_of_overlap(c1,r1,c2,r2));
   }
    return 0;
}