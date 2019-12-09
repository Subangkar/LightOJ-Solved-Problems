//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 36

typedef int64_t ll;

// Find all possible sum of elements of a[] and store
// in x[]
void calcsubarray(ll a[], ll x[], int n, int c) {
	for (int i = 0; i < (1 << n); i++) {
		ll s = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				s += a[j + c];
		x[i] = s;
	}
}

// all subset sums
void gen(const ll a[], int n, int i, long long acc, vector<long long> &ans) {
	ans.push_back(acc);
	if (i < n) {
		gen(a, n, i + 1, acc, ans);
		gen(a, n, i + 1, acc + a[i], ans);
		gen(a, n, i + 1, acc + a[i] + a[i], ans);
	}
}

//ll X[(1 << (N_MAX / 2)) + 1];
vector<long long> X, Y;

// Returns the maximum possible sum less or equal to S
const char *solveSubsetSum(ll a[], int n, ll S) {
	X.clear();
	Y.clear();
//	calcsubarray(a, X, n, 0); // 2^n
	gen(a, n / 2, 0, 0, X); // 2^9
	gen(a + n / 2, n - n / 2, 0, 0, Y); // 2^9

	//	sort(X, X + size_X);  // 2^nlog(2^n) = n.2^n
	sort(Y.begin(), Y.end()); // 18.2^18

	for (long long x : X) { // n.2^n
		if (x == S) return "Yes";
		if (x < S) {
			if (binary_search(Y.begin(), Y.end(), S - x)) // log(2^n) = n
				return "Yes";
		}
	}
	return "No";
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
//		cin >> N >> k >> D;
		int64_t N, S;
		scanf("%lld %lld", &N, &S);
		int64_t a[N_MAX + 1];
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &a[i]);
		}
		printf("Case %d: %s\n", t, solveSubsetSum(a, N, S));
	}
	return 0;
}
