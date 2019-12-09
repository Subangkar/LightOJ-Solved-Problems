//
// Created by Subangkar on 01-Dec-19.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<uint64_t, uint64_t> factor_t;

#define memCLR(a, n, v) for(uint64_t i=0;i<n;++i) a[i]=v;

#define MOD 1000000007

// a^b mod m
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
inline int64_t invmod(int64_t a, int64_t p) {
	return bigmod(a, p - 2, p);
}

// a*b mod m
inline int64_t modmult(int64_t a, int64_t b, int64_t m) {
	return (a % m) * (b % m) % m;
}

// a/b mod m
inline int64_t moddiv(int64_t a, int64_t b, int64_t m) {
	return ((a % m) * invmod(b, m)) % m;
}

// keeps n! mod m
#define N_MAX 100
int64_t fact[N_MAX + 1];

int64_t fact_precalc(int64_t N, int64_t m) {
	static int64_t max = 0;
	if (N <= max) return fact[N];
	fact[0] = 1;
	for (int64_t n = max + 1; n <= N; ++n) {
		fact[n] = (n * fact[n - 1]) % m;
	}
	max = N;
	return fact[N];
}

vector<uint64_t> primes;

size_t prime_generators(uint64_t N) {
	bool is_prime[N + 1];
	memCLR(is_prime, N, true);
	uint64_t p = 2;
	primes.push_back(p);
	for (uint64_t i = 2; p * i <= N; ++i) is_prime[p * i] = false;
	for (p = 3; p <= N; p += 2) {
		if (!is_prime[p]) continue;
		primes.push_back(p);
		for (uint64_t i = 2; p * i <= N; ++i) is_prime[p * i] = false;
	}
	return primes.size();
}

// first=fact, second=pow
uint64_t prime_factorization_sieve(uint64_t N, vector<pair<uint64_t, uint64_t >> &prime_factors) {
	uint64_t n = 2;
	auto factor = make_pair(n, 0ul);
	while (!(N & 1u)) {
		N >>= 1u;
		++factor.second;
	}
	if (factor.second) prime_factors.emplace_back(factor);
	for (n = 3; n * n <= N; n += 2) {
		factor = make_pair(n, 0ul);
		while (N % n == 0) {
			N /= n;
			++factor.second;
		}
		if (factor.second) prime_factors.emplace_back(factor);
	}
	if (N > 1) prime_factors.emplace_back(make_pair(N, 1));
	return prime_factors.size();
}

// first=fact, second=pow
uint64_t prime_factorization_sieve(uint64_t N, vector<pair<uint64_t, uint64_t >> &prime_factors,
                                   const vector<uint64_t> &primes) {
	for (auto p : primes) {
		if (N < 2) break;
		auto factor = make_pair(p, 0ul);
		while (N % p == 0) {
			N /= p;
			++factor.second;
		}
		if (factor.second) prime_factors.emplace_back(factor);
	}
	if (N > 1) prime_factors.emplace_back(make_pair(N, 1));
	return prime_factors.size();
}

uint64_t f(uint64_t n, uint64_t m) {
	vector<factor_t> prime_factors;
	prime_factorization_sieve(n, prime_factors, primes);
	uint64_t resu = 1, resl = 1;
	for (auto &factor :prime_factors) {
		uint64_t p = factor.first, a = factor.second * m;
		resu = (resu * ((bigmod(p, a + 1, MOD) - 1 + MOD) % MOD)) % MOD;
		resl = (resl * ((p - 1 + MOD) % MOD)) % MOD;
	}
	return (resu * invmod(resl, MOD)) % MOD;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	prime_generators((1u << 16u));// for 32-bit div is max sqrt(2^
//	uint64_t p_max = (0 - 1 + MOD) % MOD;
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
		int n, m;
//		cin >> n >> k >> s;
		scanf("%d %d", &n, &m);

		printf("Case %d: %lld\n", t, f(n, m));
//		cout << "Case " << t << ": " << perm(n, k, s) << endl;
	}
	return 0;
}
