//
// Created by Subangkar on 29-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define T_MAX 1000+1
#define D_MAX 1000+1

double dp[2][D_MAX];

#define TT 0
#define TD 1
#define MD 2
#define DD 3
#define TM 4

double prob(int type, int t, int d) {
	double n = t + d + 1;
//	if (t < 0 || d < 0) return 0.0;
	switch (type) {
		case TT:
			return (t * (t - 1)) / (n * (n - 1));
		case TD:
			return (t * d) / (n * (n - 1) / 2.0);
		case MD:
			return (1 * d) / (n * (n - 1) / 2.0);
		case DD:
			return (d * (d - 1)) / (n * (n - 1));
		default:
			return 0.0;
	}
}

double exp_prob(int T, int D) {
	if (T & 1) return 0.00;
	for (int d = 0; d <= D; ++d) {
		dp[0][d] = 1.00;
	}
	for (int t = 2; t <= T; t += 2) {
		for (int d = 0; d <= D; ++d) {
			int i = (t / 2) % 2, i_1 = !i;
			dp[i][d] = (dp[i_1][d] * prob(TT, t, d) +
			            (d > 0 ? dp[i][d - 1] * prob(TD, t, d) + dp[i][d - 1] * prob(MD, t, d) : 0)) /
			           (1 - prob(DD, t, d));
		}
	}

	return dp[(T / 2) % 2][D];
}


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int T, D;
//		cin >> T >> k >> D;
		scanf("%d %d", &T, &D);

		printf("Case %d: %lf\n", t, exp_prob(T, D));
	}
	return 0;
}
