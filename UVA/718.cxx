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

#define nln        puts("")                         ///printnewline
#define getint(a)  scanf("%d",&a);
#define max3(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define min3(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(int i=1;i<=n;i++)
#define FOR0(i,n)  for(int i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(int i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (int)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long int
#define LLI        long long int
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
void CI(int &_x)
{
    scanf("%d",&_x);
}

void CO(int &_x)
{
    cout<<_x;
}

template<typename T> void getarray(T a[],int n)
{
    for(int i=0; i<n; i++) cin>>a[i];
}
template<typename T> void printarray(T a[],int n)
{
    for(int i=0; i<n-1; i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

const double EPS=1e-9;                              ///constatnts
const int INF=0x7f7f7f7f;

int dr8[8]= {1,-1,0,0,1,-1,-1,1};            ///8 direction move
int dc8[8]= {0,0,-1,1,1,1,-1,-1};
int dr4[4]= {0,0,1,-1};                      ///4 direction move
int dc4[4]= {-1,1,0,0};                      ///or adjacent dir.
int kn8r[8]= {1,2,2,1,-1,-2,-2,-1};          ///knight moves
int kn8c[8]= {2,1,-1,-2,-2,-1,1,2};


int gcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}




bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
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




void shift_solution (int & x, int & y, int a, int b, int cnt)
{
    x += cnt * b;
    y -= cnt * a;
}



int find_all_solutions (int a, int b, int c, int minx, int maxx, int miny, int maxy)
{

    if(a==0&&b==0&&c)return 0;

    if(a==0&&b==0 &&c==0)
    {

        return (maxx-minx+1)*(maxy-miny+1);

    }
    if(a==0)
    {
        int yy=c/b;
        if(c%b&&yy>=miny&&yy<=maxy)
            return (maxx-minx+1);
        else
            return 0;
    }

    if(b==0)
    {
        int xx=c/a;
        if(c%a&&xx>=minx&&xx<=maxx)
            return (maxy-miny+1);
        else
            return 0;
    }




    int x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a>0 ? +1 : -1;
    int sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution (x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)
        shift_solution (x, y, a, b, sign_a);



    int rx2 = x;

    if (lx2 > rx2)
        swap (lx2, rx2);
    int lx = max (lx1, lx2);
    int rx = min (rx1, rx2);

    return (rx - lx) / abs(b) + 1;

}



int F,E,A,B;
vector<pair<int,int> >V;

bool vis[107];
void clr()
{

    memset(vis,0,sizeof vis);
    V.clear();
}
void input()
{

    cin>>F>>E>>A>>B;
    F--;

    FOR1(i,E)
    {

        int a,b;
        cin>>a>>b;

        V.PB(MP(a,b));
    }

}

bool connected(int i,int j)
{

    int a,b,c;
    a=V[i].ff,b=V[j].ff;
    b*=-1;
    c=V[j].ss-V[i].ss;

    int x,y,z;
    find_any_solution(a,b,c,x,y,z);



    int min_x,max_x,min_y,max_y;


    min_x=0;
    max_x=(F-V[i].ss)/V[i].ff;
   // max_x=max(0,max_x);


    min_y=0;
    max_y=(F-V[j].ss)/V[j].ff;
   // max_y=max(0,max_y);


    int num=find_all_solutions(a,b,c,min_x,max_x,min_y,max_y);

    num=max(0,num);

    return num;

}

bool ans=0;
int des;

int modd(int a,int b,int c)
{

    a=a-b;
    while(a<0)a+=c;
    return a%c;


}
void dfs(int u)
{


    if(modd(B,V[u].ss,V[u].ff)==0)
    {
        ans=1;
        return;

    }
//cout<<"CC "<<u<<"\n";
    vis[u]=1;
    for(int i=0; i<E; i++)
    {
        int v=i;
        if(vis[v])continue;
        if(connected(u,v))
            dfs(v);
        // cout<<"FF "<<u<<" "<<v<<"\n";

    }


}
void proc()
{

    ans=0;




//dfs(0);
    for(int i=0; i<V.size(); i++)
        if(vis[i]==0 &&ans==0 &&modd(A,V[i].ss,V[i].ff)==0)
        {
//        cout<<i<<"\n";
            dfs(i);
        }

    if(ans)
        puts("It is possible to move the furniture.");
    else
        puts("The furniture cannot be moved.");



}
int main()
{
    //  cout<<(0%5)<<"\n";
//READ("input.txt");
    int t;
    cin>>t;
    while(t--)
    {
        clr();
        input();
        proc();


    }

}
