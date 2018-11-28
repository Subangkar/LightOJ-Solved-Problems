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


#define pi 3.14159
int main()
{

	int t = 0, cs = 0;
	cin >> t;

	while (cs<t)
	{
		cs++;
		int m, l, r;
		cin >> m >> l;
		r = (abs(m - l) + m) * 4 + 3 * 3 + 2 * 5;
		cout << "Case " << cs << ": " << r << endl;
		//printf("Case %d: %lf\n", cs, r);

	}

	return 0;
}
