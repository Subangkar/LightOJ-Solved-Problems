//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 50

bool taken[N_MAX + 1];

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int own[N_MAX + 1], opp[N_MAX + 1];
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &own[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &opp[i]);
		}
		sort(own, own + n);
		sort(opp, opp + n, greater<>());
		memCLR(taken, n, false);
		int pnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (opp[j] != -1 && own[i] > opp[j]) {
					pnt += 2;
					own[i] = opp[j] = -1;
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i)
			if (own[i] != -1)
				for (int j = 0; j < n; ++j) {
					if (opp[j] != -1 && own[i] == opp[j]) {
						pnt += 1;
						own[i] = opp[j] = -1;
						break;
					}
				}
		printf("Case %d: %d\n", t, pnt);
	}
	return 0;
}
