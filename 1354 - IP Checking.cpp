#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <bitset>
#include <cmath>

typedef long long ll;




using namespace std;



int Bin2Dec(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}


int main()
{

	int t = 0, cs = 0;
	cin >> t;

	while (cs<t)
	{
		cs++;
        int a,b,c,d;
        long long w,x,y,z;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%lld.%lld.%lld.%lld",&w,&x,&y,&z);
        cout << "Case "<<cs<<": ";
        if(Bin2Dec(w)==a && Bin2Dec(x)==b && Bin2Dec(y)==c && Bin2Dec(z)==d){
            cout << "Yes"<<endl;
        }
        else{
            cout << "No"<<endl;
        }
	}

	return 0;
}
