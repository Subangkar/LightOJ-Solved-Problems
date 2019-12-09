//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 10000


int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);
		int a[n + 1], p[n + 1];
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			a[i] = x;
			p[x] = i;
		}
		int cnt = 0;
		a[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != i) {
				++cnt;
				p[a[i]] = p[i];
				swap(a[i], a[p[i]]);
				p[i] = i;
			}
		}
		printf("Case %d: %d\n", t, cnt);
	}
	return 0;
}
