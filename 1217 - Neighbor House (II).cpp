//
// Created by Subangkar on 30-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 1000
#define R 0

int dp[N_MAX + 1];
int cost[N_MAX + 1];


int dp_value(int N) {
	if (N < 2)
		return cost[0];
	if (N < 3)
		return max(cost[0], cost[1]);

	int max_exc_n[N - 1];
	int max_exc_0[N - 1];
	int *cost_exc_n = cost;
	int *cost_exc_0 = &cost[1];
	max_exc_n[0] = cost_exc_n[0];
	max_exc_n[1] = cost_exc_n[1];

	max_exc_0[0] = cost_exc_0[0];
	max_exc_0[1] = cost_exc_0[1];

	max_exc_n[2] = cost_exc_n[2] + max_exc_n[0];
	max_exc_0[2] = cost_exc_0[2] + max_exc_0[0];

	for (int n = 3; n < N - 1; ++n) {
		max_exc_n[n] = cost_exc_n[n] + max(max_exc_n[n - 2], max_exc_n[n - 3]);
		max_exc_0[n] = cost_exc_0[n] + max(max_exc_0[n - 2], max_exc_0[n - 3]);
	}
	int n = N - 1;
	return max(max(max_exc_n[n - 1], max_exc_n[n - 2]), max(max_exc_0[n - 1], max_exc_0[n - 2]));
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
			scanf("%d", &cost[i]);
		}

		printf("Case %d: %d\n", t, dp_value(N));
	}
	return 0;
}
