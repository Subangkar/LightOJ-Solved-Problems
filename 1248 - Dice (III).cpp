//
// Created by Subangkar on 27-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

// Ei = 1 + (i/n)Ei => Ei = n/(n-i)
// Ex = 1 + (1 + (1/n)E1) + (1 + (2/n)E2) + (1 + (3/n)E3)
// E3 => expected length of seeing among same 3 items

double expec(int n) {
	double exp_val = 0.0;
	for (int i = 0; i < n; ++i) {
		exp_val += 1 + double(i) / (n - i);
	}
	return exp_val;
}


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int n;
		cin >> n;

		printf("Case %d: %lf\n", t, expec(n));
	}
	return 0;
}

