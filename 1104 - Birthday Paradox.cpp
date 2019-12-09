//
// Created by Subangkar on 26-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;


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
//		double p = (1 + sqrt(1 + 8 * log(2) / log(double(n) / (n - 1))))/2;// formula does not compute correctly
		double p = 1;
		int x = 0;
		for (int i = n; i >= 0; --i) {
			p *= double(i) / n;
			if (p <= 0.5) {
				x = n - i;
				break;
			}
		}
		cout << "Case " << t << ": " << x << endl;
	}
	return 0;
}

