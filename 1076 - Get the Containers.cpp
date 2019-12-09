//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 1000

int64_t a[N_MAX + 1];
int N, M;


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
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &a[i]);
		}
		int64_t ttl = 0;
		ttl = accumulate(a, a + N, ttl);
		int64_t min = *max_element(a, a + N);
		printf("Case %d: %lld\n", t, bin_search(a, N, min, ttl));
	}
	return 0;
}
