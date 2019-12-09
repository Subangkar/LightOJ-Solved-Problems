//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 2000
int64_t a[N_MAX + 1];

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
		scanf("%lld", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &a[i]);
		}
		int64_t cnt = 0;
		sort(a, a + N);
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				int64_t p = lower_bound(a + j + 1, a + N, a[i] + a[j]) - a;
//				if (p != i && p != j) {
					if (p == N || a[p] >= a[i] + a[j])
						--p;
					cnt += (p - j);
//				}
			}
		}
		printf("Case %d: %lld\n", t, cnt);
	}
	return 0;
}
