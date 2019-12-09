//
// Created by Subangkar on 02-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 1000+5
#define S_MAX 15000+5
#define MOD 100000007

// R(n,s) = R(n, s-1)       // nth elem at least once => (1......K)
//        + R(n-1, s)       // nth elem excluding     => (0)
//        - R(n-1, s-1-K)   // nth can't be taken K for making "(s-1)"

int64_t dp[2][S_MAX];

int64_t perm(int N, int K, int S) {
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
			dp[i][s] = (dp[i][s - 1] + dp[i_1][s] - (s - 1 - K >= 0) * dp[i_1][max(0, s - 1 - K)]);
		}
	}
	int64_t sum = 0;
	for (int s = 0; s <= S; ++s) {
		sum += dp[N % 2][s];
	}
	return sum;
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
		scanf("%d %d", &n, &s);
		k = 6;
		int64_t ttl = round(pow(k, n));
		int64_t gte_s = ttl - perm(n, k - 1, s - 1 - n);
		int64_t gcd = __gcd(gte_s, ttl);
		ttl /= gcd;
		gte_s /= gcd;
		if (ttl != 1) printf("Case %d: %lld/%lld\n", t, gte_s, ttl); // at least once
		else printf("Case %d: %lld\n", t, gte_s);
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
