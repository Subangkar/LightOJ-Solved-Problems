//
// Created by Subangkar on 26-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

double exp_dp(int n, map<int, double> &mp) {
	if (n <= 1) return 0;
	if (mp.find(n) != mp.end())
		return mp[n];

	double exp_val = (1) + 1;//n,1
	int n_divisors = 2;
	for (int d = 2; d * d <= n; ++d) {
		if (n % d == 0) {
			exp_val += (1 + exp_dp(d, mp)) + (n / d != d) * (1 + exp_dp(n / d, mp));
			n_divisors += 1 + (n / d != d);
		}
	}
	exp_val /= (n_divisors - 1);
	mp[n] = exp_val;
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
		map<int, double> m;
		m[2] = m[3] = m[5] = m[7] = 2.0;
//		cout << "Case " << t << ": " << exp_dp(n, m) << endl;
		printf("Case %d: %lf\n", t, exp_dp(n, m));
	}
	return 0;
}

