//
// Created by Subangkar on 27-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 1000+5
#define S_MAX 15000+5
#define MOD 100000007

#ifdef DEBUG_1
int64_t sum[N_MAX][S_MAX];

// Runtime error donno why
int64_t perm2(int N, int K, int S) {
	if (!N && !S) return 0;
	if (N < 1 || S < 1 || K < 1) return 0;

	sum[0][0] = 1;
	for (int n = 1; n <= N; ++n) {
		sum[n][0] = 1;
	}
	for (int s = 1; s <= S; ++s) {
		sum[0][s] = 1;
	}
	for (int n = 1; n <= N; ++n) {
		for (int s = 1; s <= S; ++s) {
			sum[n][s] = sum[n - 1][s] + sum[n][s - 1];
			if (n - 2 >= 0) {
				sum[n][s] -= sum[n - 2][s - 1];
				if (s - K - 1 >= 0) {
					sum[n][s] += sum[n - 2][s - K - 1];
				}
			}
			if (s - K - 1 >= 0) {
				sum[n][s] -= sum[n - 1][s - K - 1];
			}
			sum[n][s] = (sum[n][s] + MOD) % MOD;
		}
	}
	int64_t v = sum[N][S] - sum[N - 1][S] - sum[N][S - 1] + sum[N - 1][S - 1];
	return (v + MOD) % MOD;
}

#endif

// R(n,s) = R(n, s-1)       // nth elem at least once => (1......K)
//        + R(n-1, s)       // nth elem excluding     => (0)
//        - R(n-1, s-1-K)   // nth can't be taken K for making "(s-1)"

int64_t dp[2][S_MAX];

int perm(int N, int K, int S) {
	for (int s = 0; s <= S; ++s) {
		dp[0][s] = 0;
		dp[1][s] = s <= K;
	};
	dp[0][0] = 1;
//	for (int n = 0; n <= N; ++n) dp[n][0] = 1;

	for (int n = 2; n <= N; ++n) {
		for (int s = 1; s <= S; ++s) {
			int i = n % 2;
			int i_1 = !i;
			dp[i][s] = (dp[i][s - 1] + dp[i_1][s] - (s - 1 - K >= 0) * dp[i_1][max(0, s - 1 - K)] + MOD) % MOD;
		}
	}
	return dp[N%2][S];
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
		int n, k, s;
//		cin >> n >> k >> s;
		scanf("%d %d %d", &n, &k, &s);

		printf("Case %d: %d\n", t, perm(n, k - 1, s - n)); // at least once
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
