//
// Created by Subangkar on 07-Dec-19.
//
#include <bits/stdc++.h>
//#include "FenwickTree.hpp"

using namespace std;
#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;
#define INF INT32_MAX
#define N_MAX 100000
#define FENWICKTREE_SIZE (N_MAX+1)
#define INF INT32_MAX


typedef int dtype;
#define INF INT32_MAX

typedef int bitreedata_t;

void updateBIT(bitreedata_t tree[], int n, int i, bitreedata_t val);

// tree size must be n+1
void buildBIT(const bitreedata_t arr[], bitreedata_t tree[], int n) {
	memCLR(tree, n + 1, 0);

//	bitreedata_t x;
	for (int i = 0; i < n; i++) {
//		x = i + 1;
//		while (x <= n) {
//			tree[x] += arr[i];
//			x += x & -x;
//		}
		updateBIT(tree, n, i, arr[i]);
	}
}


void updateBIT(bitreedata_t tree[], int n, int i, bitreedata_t val) {
	++i;
	if (i == 0) return;
	while (i <= n) {
		tree[i] += val;
		i += i & -i;
	}
}

// sum upto i
bitreedata_t queryBIT(const bitreedata_t tree[], int n, int i) {
	++i;
	if (i > n) return INT32_MIN;
	bitreedata_t sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= i & -i;
	}
	return sum;
}

// l & its children excluding r's children
void updateBIT(bitreedata_t tree[], int n, int l, int r, bitreedata_t val) {
	if (l > r) return;
//	updateBIT(tree, n, r, val);
//	updateBIT(tree, n, l - 1, -val);
	updateBIT(tree, n, l, val);
	updateBIT(tree, n, r + 1, -val);
}

bitreedata_t queryBIT(bitreedata_t tree[], int n, int l, int r) {
	if (l > r) return INT32_MIN;
	return queryBIT(tree, n, r) - queryBIT(tree, n, l - 1);
}


int tree[N_MAX + 1];

void constructST(int arr[], int n) {
//	buildBIT(arr, tree, n);
	memCLR(tree, n + 1, 0);
}

int main() {
//	int arr[] = {1, 2, 3, 4, 5};
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	// Build segment tree from given array
////	constructST(arr, n);
//	buildBIT(arr, tree, n);
//	// Add 4 to all nodes in index range [0, 3]
//	updateBIT(tree, n, 1, 10);
//	updateBIT(tree, n, 0, 2, 10);
//
//	cout << queryBIT(tree, n, 0, 0) << endl;
//	cout << queryBIT(tree, n, 1, 1) << endl;
//	cout << queryBIT(tree, n, 2, 2) << endl;
//	cout << queryBIT(tree, n, 0, 1) << endl;
//	cout << queryBIT(tree, n, 1, 4) << endl;
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int a[N_MAX + 1];
	char str[N_MAX + 1];
	int t, tc;
	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int64_t N, Q;
		cin >> str;
		N = strlen(str);
		for (int i = 0; i < N; ++i) a[i] = str[i] - '0';
		cin >> Q;
		constructST(a, N);
		printf("Case %d:\n", t);
		dtype l, r, v;
		char chc = 0;
		for (int j = 0; j < Q; ++j) {
			cin >> chc;
			if (chc == 'Q') {
				cin >> l;
				v = a[l - 1] ^ (queryBIT(tree, N, l - 1) % 2);//a[l - 1] ^
				printf("%d\n", v);
			} else if (chc == 'I') {
				cin >> l >> r;
				updateBIT(tree, N, l - 1, r - 1, 1);
			}
		}
	}
	return 0;
}
