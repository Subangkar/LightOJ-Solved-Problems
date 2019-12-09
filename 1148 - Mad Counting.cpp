//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 1000000

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n;
		map<int, int> occ;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (occ.find(x) != occ.end()) ++occ[x];
			else occ[x] = 1;
		}
		int n_ppl = 0;
		for (auto &p:occ) {
			n_ppl += (p.first + 1) * ((p.second + p.first) / (p.first + 1));
		}
		printf("Case %d: %d\n", t, n_ppl);
	}
	return 0;
}
