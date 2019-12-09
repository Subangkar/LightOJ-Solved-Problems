//
// Created by Subangkar on 25-Nov-19.
//
// precision error as 669.610662499 is printed as 669.610662
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	cout << fixed << setprecision(7) << (669.610662499);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, tc;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		int v[n + 1];
		double ex[n + 1];
		for (int i = 1; i <= n; ++i) {
			cin >> v[i];
		}
//		ex[n] = v[n];
		for (int j = n; j; --j) {
			int p_inv = n - j > 6 ? 6 : (n - j);
			ex[j] = 0;
			for (int k = j + 1; k <= j + 6 && k <= n; ++k) {
				ex[j] += ex[k];
			}
//			ex[j] = v[j] + ex[j] / (p_inv > 0 ? p_inv : 1);
			if (p_inv > 1)
				ex[j] /= p_inv;
			ex[j] += v[j];
		}
//		cout << "Case " << t << ": " << ex[1] << endl;
//		printf("Case %d: %.6lf\n", t, ex[1]);
		printf("Case %d: %lf\n", t, ex[1]);
	}
	return 0;
}

