#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

#define nln        puts("")                         ///prLLInewline
#define getLLI(a)  scanf("%d",&a);
#define max3(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define min3(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(LLI i=1;i<=n;i++)
#define FOR0(i,n)  for(LLI i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(LLI i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (LLI)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long LLI
#define LLI        long long
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

LLI Set(LLI N,LLI pos)
{
    return N=N | (1<<pos);
}
LLI reset(LLI N,LLI pos)
{
    return N= N & ~(1<<pos);
}
bool check(LLI N,LLI pos)
{
    return (bool)(N & (1<<pos));
}
void CI(LLI &_x)
{
    scanf("%d",&_x);
}

void CO(LLI &_x)
{
    cout<<_x;
}

template<typename T> void getarray(T a[],LLI n)
{
    for(LLI i=0; i<n; i++) cin>>a[i];
}
template<typename T> void prLLIarray(T a[],LLI n)
{
    for(LLI i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

const double EPS=1e-9;                              ///constatnts
const LLI INF=0x7f7f7f7f;

LLI dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
LLI dc8[8]= {0,0,-1,1,1,1,-1,-1};
LLI dr4[4]= {0,0,1,-1};                      ///4 direction move
LLI dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
LLI kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
LLI kn8c[8]= {2,1,-1,-2,-2,-1,1,2};
LLI gcd(LLI a, LLI b, LLI &x, LLI &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    LLI x1, y1;
    LLI d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(LLI a, LLI b, LLI c, LLI &x0, LLI &y0, LLI &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void shift_solution (LLI & x, LLI & y, LLI a, LLI b, LLI cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

LLI find_all_solutions (LLI a, LLI b, LLI c, LLI minx, LLI maxx, LLI miny, LLI maxy)
{
    LLI x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    LLI sign_a = a>0 ? +1 : -1;
    LLI sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    LLI lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution (x, y, a, b, -sign_b);
    LLI rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    LLI lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)
        shift_solution (x, y, a, b, sign_a);
    LLI rx2 = x;

    if (lx2 > rx2)
        swap (lx2, rx2);
    LLI lx = max (lx1, lx2);
    LLI rx = min (rx1, rx2);

    return (rx - lx) / abs(b) + 1;
}
int main()
{
//READ("input.txt");
    LLI t,kase=1;
    cin>>t;
    while(t--)
    {

        LLI A,B,C,x1,x2,y1,y2;
        cin>>A>>B>>C>>x1>>x2>>y1>>y2;
        C*=-1;

        cout<<"Case "<<kase++<<": ";

//cout<<find_any_solution(A,B,C,x1,y1,x2)<<"\n";
//cout<<"FF "<<x1<<" "<<y1<<" "<<x2<<"\n";


        if(A==0&&B==0&&C)
        {
            puts("0");
        }
        else if(A==0&&B==0&&C==0)
        {
            cout<<1ll*(x2-x1+1)*(y2-y1+1)<<"\n";
        }
        else if(A==0)
        {
        int yy=C/B;
            if(C%B==0&&yy>=y1&&yy<=y2)cout<<abs(x2-x1)+1<<"\n";
            else puts("0");

        }
        else if(B==0)
        {
        int xx=C/A;
            if(C%A==0 &&xx>=x1&&xx<=x2)cout<<abs(y2-y1)+1<<"\n";
            else puts("0");

        }
        else
        cout<<max(find_all_solutions(A,B,C,x1,x2,y1,y2),0ll)<<"\n";
    }

}
