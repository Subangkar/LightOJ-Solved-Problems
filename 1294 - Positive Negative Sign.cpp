//
// Created by Subangkar on 04-Dec-19.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc = 0;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		long long n,m;
		scanf("%lld%lld", &n, &m);
		printf("Case %d: %lld\n", t, (n*m)/2);
	}
	return 0;
}
