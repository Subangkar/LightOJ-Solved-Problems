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

#define FILE_INP freopen("in.txt","r",stdin)
#define FILE_OUT freopen("out.txt","w",stdout)

#define pi 3.14159
int main()
{

    FILE_INP;
	FILE_OUT;

	int t = 0, cs = 0;
	cin >> t;

	while (cs<t)
	{
		cs++;
		double R, r, n;
		cin >> R >> n;
		r=R*(sin(pi / n) / (1 + sin(pi / n)));
//		cout << "Case " << cs << ": " <<  << endl;
		printf("Case %d: %g\n",cs,r);

	}

	return 0;
}
