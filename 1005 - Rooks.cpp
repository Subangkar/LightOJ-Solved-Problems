//
// Created by Subangkar on 30-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 100+1
#define S_MAX 100000+1
#define MOD 100000007

// Returns value of Binomial Coefficient C(n, k) : O(k)
int64_t binomialCoeff(int n, int k) {
	int res = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
		k = n - k;

	// Calculate value of
	// [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}


int64_t nways(int n, int k) {
	if (n < k) return 0;
	int64_t mult = 1;
	for (int i = 0, x = n; i < k; ++i, --x) {
		mult *= x;
	}
	return binomialCoeff(n, k) * mult;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n, k;
//		cin >> n >> k >> s;
		scanf("%d %d", &n, &k);

		printf("Case %d: %lld\n", t, nways(n, k));
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
