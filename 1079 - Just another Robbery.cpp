//
// Created by Subangkar on 28-Nov-19.
//

//
// Created by Subangkar on 27-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;


#define N_MAX 100

double opt[N_MAX * N_MAX + 1];
//double P_inv[N_MAX + 1];
int V_sum[N_MAX + 1];
pair<int, double> bank[N_MAX + 1];//million,P

int prob(int N, int W, double cut_P) {
	int maxW = 0;
	for (int i = 0; i <= W; ++i) {
		opt[i] = 1;
	}
	opt[0] = 0;
	for (int n = 1; n <= N; ++n) {
		for (int i = V_sum[n]; i; --i) {
			if (i >= bank[n].first)
				opt[i] = min(opt[i - bank[n].first] + (1 - opt[i - bank[n].first]) * bank[n].second, opt[i]);
			if (opt[i] < cut_P && i > maxW) {
				maxW = i;
			}
		}
	}
	return maxW;
}


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

//  cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
//      int n, k, s;
//      cin >> n >> k >> s;
		int n;
		double cut_p;
//      scanf("%lf %d", &cut_p, &n);
		cin >> cut_p >> n;
//      P_inv[0] = 1.00;
		V_sum[0] = 0;
		int W = 0;
		int minInc = INT32_MAX;
		for (int i = 1; i <= n; ++i) {
			cin >> bank[i].first >> bank[i].second;
			minInc = min(bank[i].first, minInc);
			V_sum[i] = V_sum[i - 1] + bank[i].first;
//          P_inv[i] = P_inv[i - 1] * (1.00 - bank[i].second);
//          W += bank[i].first;
		}
		W = V_sum[n];
		printf("Case %d: %d\n", t, prob(n, W, cut_p));
//      cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
