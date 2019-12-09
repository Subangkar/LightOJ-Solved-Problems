//
// Created by Subangkar on 30-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX_BITS 32
#define N_MAX 1000
#define R 0
uint64_t fact[N_MAX_BITS + 1];

int dp[N_MAX + 1];
int cost[N_MAX + 1];


void calc_fact() {
	fact[0] = 0;
	fact[1] = 0;
	for (uint64_t n = 2; n <= N_MAX_BITS; ++n) {
		fact[n] = (fact[n - 1] << 1u) + (1u << (n - 2));// 2R(n-1) + 2^n/4
	}
}

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


size_t bitlen(uint64_t n) {
	size_t l = 0;
	while (n) {
		++l;
		n >>= 1u;
	}
	return l;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	calc_fact();
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		uint64_t N;
//		cin >> N >> k >> D;
		scanf("%lld", &N);
//		bitset<N_MAX_BITS> n;
		uint64_t ttl_n_adj = 0;
		uint64_t n = N;
		for (size_t b = bitlen(N) - 1; b > 0 && n; --b) {
			if (!(n & (1u << b))) continue;
			n &= (1u << b) - 1;
			size_t x = (1u << (b - 1)) - 1u;
			int next_bit = (n & (1u << (b - 1))) != 0;
			ttl_n_adj += fact[b] + next_bit * (n - x);// R(b-1) + (n - (2^b-2-1))*(if_two_adj)
		}
		printf("Case %d: %llu\n", t, ttl_n_adj);
	}
	return 0;
}
