//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 50000

int Y[N_MAX + 1];

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n, w;
		scanf("%d%d", &n, &w);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
//			cin >> x;
			Y[i] = y;
		}
		sort(Y, Y + n);
		int cnt = 1;
		int y_min = Y[0];
		for (int i = 1; i < n; ++i) {
			if (y_min + w < Y[i]) {
				cnt++;
				y_min = Y[i];
			}
		}
		printf("Case %d: %d\n", t, cnt);
	}
	return 0;
}
