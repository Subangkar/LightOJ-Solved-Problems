//
// Created by Subangkar on 30-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 200
#define R 0
#define G 1
#define B 2

int dp[20 + 1][3];
int cost[20 + 1][3];


int dp_value(int N) {

	dp[0][R] = cost[0][R];
	dp[0][G] = cost[0][G];
	dp[0][B] = cost[0][B];

	for (int n = 1; n < N; ++n) {
			dp[n][R] = cost[n][R] + min(dp[n - 1][G], dp[n - 1][B]);
			dp[n][G] = cost[n][G] + min(dp[n - 1][B], dp[n - 1][R]);
			dp[n][B] = cost[n][B] + min(dp[n - 1][R], dp[n - 1][G]);
	}

	return min(dp[N - 1][R], min(dp[N - 1][G], dp[N - 1][B]));
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
		int N;
//		cin >> N >> k >> D;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d %d %d", &cost[i][R], &cost[i][G], &cost[i][B]);
		}

		printf("Case %d: %d\n", t, dp_value(N));
	}
	return 0;
}
