//
// Created by Subangkar on 30-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 50+1
#define S_MAX 1000+1
#define MOD 100000007

// R(n,s) = R(n, s-1)       // nth elem at least once => (1......K)
//        + R(n-1, s)       // nth elem excluding     => (0)
//        - R(n-1, s-1-K)   // nth can't be taken K for making "(s-1)"

int64_t dp[2][S_MAX];
int coin[N_MAX];
int val[N_MAX];

int dp_value(int N, int S) {
	for (int s = 0; s <= S; ++s) {
		int K = coin[1] * val[1];
		dp[0][s] = 0;
		dp[1][s] = (s <= K && s % val[1] == 0);
	};
	dp[0][0] = dp[1][0] = 1;
//	for (int n = 0; n <= N; ++n) dp[n][0] = 1;

	for (int n = 2; n <= N; ++n) {
		int K = coin[n] * val[n];
		for (int s = 1; s <= S; ++s) {
			int i = n % 2;
			int i_1 = !i;
			dp[i][s] = ((s - val[n] >= 0) * dp[i][max(s - val[n], 0)] +
			            dp[i_1][s] -
			            (s - val[n] - K >= 0) * dp[i_1][max(s - val[n] - K, 0)] + MOD) % MOD;
		}
	}
	return dp[N % 2][S];
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
		int n, k;
//		cin >> n >> k >> s;
		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
		for (int i = 1; i <= n; ++i) scanf("%d", &coin[i]);

		printf("Case %d: %d\n", t, dp_value(n, k));
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
