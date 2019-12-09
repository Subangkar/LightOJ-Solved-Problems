//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;

using namespace std;

#define N_MAX 50000

int Y[N_MAX + 1];

double f(double l, double w, double x) {
	return (l - 2 * x) * (w - 2 * x) * x;
}

double f1(double l, double w, double x) {
	return l * w - 4 * (l + w) * x + 12 * x * x;
}

double f2(double l, double w, double x) {
	return -4 * (l + w) + 24 * x;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		double l, w;
		scanf("%lf%lf", &l, &w);
		double x1, x2, x;
		x1 = (4 * (l + w) + sqrt(16 * (l + w) * (l + w) - 48 * l * w)) / (2 * 12);
		x2 = (4 * (l + w) - sqrt(16 * (l + w) * (l + w) - 48 * l * w)) / (2 * 12);
		if (f(l, w, x1) > f(l, w, x2)) x = x1;
		else x = x2;
		printf("Case %d: %lf\n", t, f(l, w, x));
	}
	return 0;
}
