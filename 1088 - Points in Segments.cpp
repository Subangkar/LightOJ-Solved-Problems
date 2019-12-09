//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 100000
int64_t a[N_MAX + 1];

int64_t nzeros_in_fact(int64_t n) {
	int64_t cnt = 0;
	int64_t d = 5;
	while (n >= d) {
		cnt += (n / d);
		d *= 5;
	}
	return cnt;
}

int64_t bin_search(int64_t low, int64_t high, int64_t v) {
	int64_t soln = -1;
	int64_t mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (v < nzeros_in_fact(mid)) { // look left
			high = mid - 1;
		} else if (v > nzeros_in_fact(mid)) low = mid + 1;
		else {
			soln = mid;
			high = mid - 1;
		}
	}
	return soln;
}

int64_t bin_search_first_ge(int64_t a[], int64_t n, int64_t low, int64_t high, int64_t v) {
	int64_t pos = -1;
	int64_t mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (v <= a[mid]) { // look left
			high = mid - 1;
			pos = mid;
		} else low = mid + 1;
	}
	return pos;
}

int64_t bin_search_first_le(int64_t a[], int64_t n, int64_t low, int64_t high, int64_t v) {
	int64_t pos = -1;
	int64_t mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (v >= a[mid]) { // look left
			low = mid + 1;
			pos = mid;
		} else high = mid - 1;
	}
	return pos;
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
		int64_t N, M;
		scanf("%lld %lld", &N, &M);
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &a[i]);
		}
		printf("Case %d:\n", t);
		for (int j = 0; j < M; ++j) {
			int64_t min, max;
			int64_t cnt = 0;
			scanf("%lld %lld", &min, &max);
			int64_t l = bin_search_first_ge(a, N, 0, N - 1, min);
			int64_t h = bin_search_first_le(a, N, 0, N - 1, max);
			if (l >= 0 && h >= 0 && l <= h) {
				cnt = h - l + 1;
			}
			printf("%lld\n", cnt);
		}
	}
	return 0;
}
