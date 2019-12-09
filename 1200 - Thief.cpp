//
// Created by Subangkar on 06-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

#define N_MAX 100
#define S_MAX 10000
#define MOD 100000007

int64_t dp[S_MAX + 1];
int64_t val[N_MAX + 1], wt[N_MAX + 1], cnt[N_MAX + 1];

int64_t unboundedKnapsack(int64_t W, int n, int64_t val[], const int64_t wt[]) {
	memCLR(dp, W + 1, 0);

	for (int i = 0; i <= W; i++)
		for (int j = 0; j < n; j++)
			if (wt[j] <= i)
				dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);

	return dp[W];
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
		int64_t n, w;
//		cin >> n >> k >> s;
		scanf("%lld %lld", &n, &w);

		for (int i = 0; i < n; ++i) scanf("%lld%lld%lld", &val[i], &cnt[i], &wt[i]);

		for (int i = 0; i < n; ++i) w -= cnt[i] * wt[i];

		if (w < 0)
			printf("Case %d: %s\n", t, "Impossible");
		else
			printf("Case %d: %lld\n", t, unboundedKnapsack(w, n, val, wt));
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
