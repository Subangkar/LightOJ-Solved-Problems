//
// Created by Subangkar on 05-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 50000


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int64_t n, c, T = 0;
		scanf("%lld%lld", &n, &c);
		if (n) T = (c / (2 * n)) + (c % (2 * n) > n);
		printf("Case %d: %lld\n", t, T);
	}
	return 0;
}
