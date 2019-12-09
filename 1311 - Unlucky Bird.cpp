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
		double u1, u2, a1, a2, u3;
		scanf("%lf%lf%lf%lf%lf", &u1, &u2, &u3, &a1, &a2);
		double t1, t2, x, d;
		t1 = u1 / a1;
		t2 = u2 / a2;
		x = max(t1, t2);
		d = (u1 * t1 - .5 * a1 * t1 * t1) + (u2 * t2 - .5 * a2 * t2 * t2);
		printf("Case %d: %lf %lf\n", t, d, x * u3);
	}
	return 0;
}
