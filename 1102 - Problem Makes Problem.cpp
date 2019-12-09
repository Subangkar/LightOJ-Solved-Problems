//
// Created by Subangkar on 01-Dec-19.
//

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
// keeps n! mod m
#define N_MAX 2000000
int64_t fact[N_MAX + 1];

int64_t fact_precalc(int64_t N, const int64_t m) {
	static int64_t max = 0;
	static int64_t M = 0;
	if (m != M) max = 0;
	if (N <= max) return fact[N];
	fact[0] = 1;
	for (int64_t n = max + 1; n <= N; ++n) {
		fact[n] = (n * fact[n - 1]) % m;
	}
	max = N;
	M = m;
	return fact[N];
}

// a^b % m
int64_t bigmod(int64_t a, int64_t b, const int64_t m) {
	if (b == 0) return 1;
	int64_t x = bigmod(a, b / 2, m);
	int64_t mod_val = (x * x) % m;
	if (b & 1) {
		mod_val = (mod_val * a) % m;
	}
	return mod_val;
}

// 1/a % p,  b and p must be co-prime to each other and p must be a prime
int64_t invmod(int64_t a, int64_t p) {
	return bigmod(a, p - 2, p);
}


// Returns value of Binomial Coefficient C(n, k) : O(k)
int64_t binomialCoeff(int64_t n, int64_t k, const int64_t m) {
	int64_t resl = 1;
	int64_t resu = 1;

	k = min(k, n - k);

	// Calculate value of
	// [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	for (int64_t i = 0; i < k; ++i) {
		resu = (resu * ((n - i) % m)) % m;
		resl = (resl * ((i + 1) % m)) % m;
	}
	return (resu * invmod(resl, m)) % m;
}

// Returns value of Binomial Coefficient C(n, k) : O(1)
int64_t binomialCoeff_fact(int64_t n, int64_t k, const int64_t m) {
	int64_t resl = 1;
	int64_t resu = 1;

	k = min(k, n - k);
	fact_precalc(n, m);

	resu = fact[n];
	resl = (fact[n - k] * fact[k]) % m;

	return (resu * invmod(resl, m)) % m;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	fact_precalc(N_MAX, MOD);
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n, k;
//		cin >> n >> k >> s;
		scanf("%d %d", &n, &k);

		printf("Case %d: %lld\n", t, (binomialCoeff_fact(n + k - 1, n, MOD)));
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
