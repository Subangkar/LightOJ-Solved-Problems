//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 50000


int X[N_MAX + 1], Y[N_MAX + 1];

// Function for calculating median
int findMedian(int a[], int n, int64_t ttl) {

	int64_t med;
	if (ttl % 2) med = 1 + ttl / 2;
	else med = ttl / 2;

	int64_t acc = 0;
	int i = 0;
	while (acc < med) {
		++i;
		acc += a[i];
	}
	return i;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n, m, q;
		int64_t ttl = 0;
		scanf("%d%d%d", &n, &m, &q);
		memCLR(X, n, 0);
		memCLR(Y, m, 0);
		for (int i = 0; i < q; ++i) {
			int u, v;
			int64_t w;
			scanf("%d%d%lld", &u, &v, &w);
			X[u] += w;
			Y[v] += w;
			ttl += w;
		}
		int x_med = findMedian(X, n, ttl);
		int y_med = findMedian(Y, m, ttl);
		printf("Case %d: %d %d\n", t, x_med, y_med);
	}
	return 0;
}
