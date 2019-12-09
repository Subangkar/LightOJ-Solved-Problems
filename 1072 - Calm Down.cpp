//
// Created by Subangkar on 05-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 50000

#define PI acos(-1.0)

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		double R;
		int64_t n;
		scanf("%lf%lld", &R, &n);
		double theta = 2 * PI / n;
		double r = R * sin(theta / 2) / (1 + sin(theta / 2));
		printf("Case %d: %lf\n", t, r);
	}
	return 0;
}
