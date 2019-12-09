//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX_DIGITS 19
#define N_MAX 1000

uint64_t pow10[N_MAX_DIGITS + 1];
uint64_t R[N_MAX_DIGITS + 1]; //   0-999
uint64_t P[N_MAX_DIGITS + 1]; // 000-999

void calc_nzeros_in_digits() {
	R[0] = P[0] = 0;
	R[1] = P[1] = 1;
	for (int n = 2; n <= N_MAX_DIGITS; ++n) {
		P[n] = pow10[n - 1] + 10 * P[n - 1];    // (0)___ + [0-9](___)
		R[n] = 9 * P[n - 1] + R[n - 1];         // [1-9](___) + ___
	}
}

void calc_pow10() {
	pow10[0] = 1;
	pow10[1] = 10;
	for (uint64_t n = 2; n <= N_MAX_DIGITS; ++n) {
		pow10[n] = pow10[n - 1] * 10;
	}
}

int64_t num_zeros(const string &N) {
	if (atoll(N.data()) < 0) return 0;
	if (atoll(N.data()) < 10) return R[1];

	int64_t pos = N.length();
	int64_t digit = (N[0] - '0');
	int64_t nzr = R[pos - 1] + (digit - 1) * P[pos - 1];

	for (size_t i = 1; i < N.length(); ++i) {
		pos = N.length() - i;
		digit = (N[i] - '0');
		int64_t val_after = atoll(N.data() + i);
		nzr += digit * P[pos - 1]
		       + (digit != 0) * pow10[pos - 1]
		       + (digit == 0) * (val_after + 1);
	}
	return nzr;
}

size_t bitlen(uint64_t n) {
	size_t l = 0;
	while (n) {
		++l;
		n >>= 1u;
	}
	return l;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	calc_pow10();
	calc_nzeros_in_digits();
	int t, tc;

//	cin >> tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++) {
//		char m[N_MAX_DIGITS + 1], n[N_MAX_DIGITS + 1];
		int64_t m, n;
		scanf("%lld %lld", &m, &n);
		string M_1 = to_string(m - 1);
		string N = to_string(n);
		int64_t nZ_m_1 = num_zeros(M_1);
		int64_t nZ_n = num_zeros(N);
		printf("Case %d: %lld\n", t, nZ_n - nZ_m_1);
	}
	return 0;
}
