#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


typedef unsigned long long int lli;

int main()
{
    int ox,oy,ax,ay,bx,by;
    double dacx,dacy;
    double r,tht,ac;

    int t=0,cs=0;

    cin>>t;
    while(cs++<t)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;

        dacx=(ax+bx) / 2.0 - ax;
        dacy=(ay+by) / 2.0 - ay;


        r=sqrt(((ox-ax)*(ox-ax))+((oy-ay)*(oy-ay)));
        tht = 2*asin(sqrt(dacx*dacx+dacy*dacy)/r);

//        cout<<"Case "<<cs<<": "<<r*tht<<endl;
        printf("Case %d: %lf\n",cs,r*tht);
    }

    return 0;
}
