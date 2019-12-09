//
// Created by Subangkar on 30-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 200
uint64_t dp[N_MAX][N_MAX];


//double dp_value(int T, int D) {
//	if (T & 1) return 0.00;
//	for (int d = 0; d <= D; ++d) {
//		dp[0][d] = 1.00;
//	}
//	for (int t = 2; t <= T; t += 2) {
//		for (int d = 0; d <= D; ++d) {
//			int i = (t / 2) % 2, i_1 = !i;
//			dp[i][d] = (dp[i_1][d] * prob(TT, t, d) +
//			            (d > 0 ? dp[i][d - 1] * prob(TD, t, d) + dp[i][d - 1] * prob(MD, t, d) : 0)) /
//			           (1 - prob(DD, t, d));
//		}
//	}
//
//	return dp[(T / 2) % 2][D];
//}


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int N;
//		cin >> N >> k >> D;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= i; ++j) {
				scanf("%lld", &dp[i][j]);
			}
		}
		for (int i = N + 1; i < 2 * N; ++i) {
			for (int j = 1; j <= (N - (i % (N))); ++j) {
				scanf("%lld", &dp[i][j]);
			}
		}
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= i; ++j) {
				dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
		for (int i = N + 1; i < 2 * N; ++i) {
			for (int j = 1; j <= (N - (i % (N))); ++j) {
				dp[i][j] = dp[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j]);
			}
		}

		printf("Case %d: %llu\n", t, dp[2 * N - 1][1]);
	}
	return 0;
}
