//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 10000000000

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
		else{
			soln = mid;
			high = mid - 1;
		}
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
		scanf("%lld", &K);
		int64_t n = bin_search(0, N_MAX, K);
		if (n != -1) printf("Case %d: %lld\n", t, n);
		else printf("Case %d: %s\n", t, "impossible");
	}
	return 0;
}
