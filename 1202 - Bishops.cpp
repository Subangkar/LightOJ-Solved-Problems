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


int main()
{

	int t = 0, cs = 0;
	cin >> t;

	while (cs<t)
	{
		cs++;
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		cout << "Case " << cs << ": ";
		if ((abs(r1 - r2) + abs(c1 - c2)) % 2 == 1) {
			cout << "impossible" << endl;
		}
		else if (abs(r1 - r2) == abs(c1 - c2))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}

	}

	return 0;
}
