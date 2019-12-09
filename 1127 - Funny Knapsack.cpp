//
// Created by Subangkar on 05-Dec-19.
//

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 30
int64_t a[N_MAX + 1];

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

ll X[(1 << (N_MAX / 2)) + 1], Y[(1 << (N_MAX / 2)) + 1];

// Returns the maximum possible sum less or equal to S
ll solveSubsetSum(ll a[], int n, ll S) {
	calcsubarray(a, X, n / 2, 0); // 2^n/2
	calcsubarray(a, Y, n - n / 2, n / 2); // 2^n/2

	int size_X = 1 << (n / 2);
	int size_Y = 1 << (n - n / 2);

	sort(Y, Y + size_Y);  // 2^n/2log(2^n/2) = n.2^n/2

	// To keep track of the maximum sum of a subset
	// such that the maximum sum is less than S
//	ll max = 0;
	ll n_ways = 0;

	// Traverse all elements of X and do Binary Search
	// for a pair in Y with maximum sum less than S.
	for (int i = 0; i < size_X; i++) { // n.2^n/2
		if (X[i] <= S) {
			// lower_bound() returns the first address which has value less than or equal to
			int p = upper_bound(Y, Y + size_Y, S - X[i]) - Y; // log(2^n/2) = n

			// If S-X[i] was not in array Y then take the max value less than S-X[i] -> max less than S
//			if (p != size_Y && Y[p] == (S - X[i]))
//				p++;

			n_ways += (p);

//			if ((Y[p] + X[i]) > max)
//				max = Y[p] + X[i];

		}
	}
	return n_ways;
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
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &a[i]);
		}
		printf("Case %d: %lld\n", t, solveSubsetSum(a, N, S));
	}
	return 0;
}
