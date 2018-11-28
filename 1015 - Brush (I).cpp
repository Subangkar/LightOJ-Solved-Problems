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
		int n, sum = 0,x;
		cin >> n;

		for (size_t i = 0; i < n; i++)
		{
			cin >> x;
			if (x > 0) sum += x;
		}

		cout << "Case " << cs << ": " << sum << endl;

	}

	return 0;
}
