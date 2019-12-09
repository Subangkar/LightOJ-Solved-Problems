//
// Created by Subangkar on 30-Nov-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 100+1
#define S_MAX 100000+1
#define MOD 1000003
#define memCLR(arr, n, v) for(int i=0;i<n;++i) arr[i]=v;

// a^b % m
int64_t bigmod(int64_t a, int64_t b, int64_t m) {
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
int64_t binomialCoeff(int64_t n, int64_t k) {
//	int64_t res = 1;
	int64_t resl = 1;
	int64_t resu = 1;

	k = min(k, n - k);

	// Calculate value of
	// [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	for (int64_t i = 0; i < k; ++i) {
//		res *= (n - i);
//		res /= (i + 1);
		resu = (resu * ((n - i) % MOD)) % MOD;
		resl = (resl * ((i + 1) % MOD)) % MOD;
	}
	return (resu * invmod(resl, MOD)) % MOD;
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

		printf("Case %d: %lld\n", t, (binomialCoeff(n, k)));
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
