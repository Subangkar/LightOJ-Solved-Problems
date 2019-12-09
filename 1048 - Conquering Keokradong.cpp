//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 1000

int64_t a[N_MAX + 1];
int64_t N, M;


bool is_possible(const int64_t arr[], size_t n, int64_t cap) {
	int64_t cnt = 1, sum = 0;
	for (int i = 0; i < n && cnt <= M; ++i) {
		if (sum + arr[i] <= cap) sum += arr[i];
		else {
			++cnt;
			sum = arr[i];
		}
	}
	return cnt <= M;
}

int64_t bin_search(const int64_t arr[], size_t n, int64_t low, int64_t high) {
	int64_t soln = high;
	int64_t mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (is_possible(arr, n, mid)) {
			soln = mid;
			high = mid - 1;
		} else low = mid + 1;
	}
	return soln;
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
//		cin >> N >> k >> D;
		int64_t K;
		scanf("%lld %lld", &N, &K);
		N++;
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &a[i]);
		}
		M = K + 1;
		int64_t ttl = 0;
		ttl = accumulate(a, a + N, ttl);
		int64_t min = *max_element(a, a + N);
		int64_t C = bin_search(a, N, min, ttl);
		printf("Case %d: %lld\n", t, C);
		int64_t sum = 0, cnt = 1;
		for (int i = 0; i < N; ++i) {
			if (sum + a[i] <= C && N - 1 - i >= M - cnt) sum += a[i];
			else {
				printf("%lld\n", sum);
				++cnt;
				sum = a[i];
			}
		}
		if (cnt == M)printf("%lld\n", sum);
	}
	return 0;
}
