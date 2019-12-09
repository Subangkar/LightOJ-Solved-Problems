//
// Created by Subangkar on 07-Dec-19.
//
#include <bits/stdc++.h>

using namespace std;
#define memCLR(a, n, v) for(int64_t i=0;i<n;++i) a[i]=v;
#define INF INT32_MAX
#define N_MAX 100000
#define SEGTREE_SIZE (5*N_MAX)


typedef int64_t dtype;
typedef int64_t segtrnode_t;
typedef segtrnode_t *segmenttree_t;

inline segtrnode_t seg_node_val(segtrnode_t left_child_val) {
	return left_child_val;
}

inline segtrnode_t seg_node_val(segtrnode_t left_child_val, segtrnode_t right_child_val) {
	return min(left_child_val, right_child_val);
}

#define SEG_TREE_OUT_OF_RANGE_VAL INF


// A recursive function to get the sum of values in given
// a range of the array. The following are the parameters
// for this function
// si --> Index of the current node in the segment tree
// Initially, 0 is passed as root is always at index 0
// ss & se --> Starting and ending indexes of the
// segment represented by current node
// i.e., tree[si]
// qs & qe --> Starting and ending indexes of query
// range
segtrnode_t getRangeValUtil(segmenttree_t tree, int ss, int se, int qs, int qe, int si) {
	// Out of range
	if (ss > se || ss > qe || se < qs)
		return SEG_TREE_OUT_OF_RANGE_VAL;

	// At this point, we are sure that pending lazy updates
	// are done for current node. So we can return value
	// (same as it was for a query in our previous post)

	// If this segment lies in range
	if (ss >= qs && se <= qe)
		return tree[si];

	// If a part of this segment overlaps with the given
	// range
	int mid = (ss + se) / 2;
//	return max(getRangeValUtil(tree, lazy, ss, mid, qs, qe, 2 * si + 1),
//	           getRangeValUtil(tree, lazy, mid + 1, se, qs, qe, 2 * si + 2));
	return seg_node_val(getRangeValUtil(tree, ss, mid, qs, qe, 2 * si + 1),
	                    getRangeValUtil(tree, mid + 1, se, qs, qe, 2 * si + 2));
}

// Return sum of elements in range from index qs (query
// start) to qe (query end). It mainly uses getRangeValUtil()
segtrnode_t getRangeVal(segmenttree_t tree, int n, int qs, int qe) {
	// Check for erroneous input values
//	if (qs < 0 || qe > n - 1 || qs > qe) {
//		printf("Invalid Input");
//		return -1;
//	}

	return getRangeValUtil(tree, 0, n - 1, qs, qe, 0);
}


// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(segmenttree_t tree, segtrnode_t arr[], int ss, int se, int si) {
	// out of range as ss can never be greater than se
	if (ss > se) return;

	// If there is one element in array, store it in
	// current node of segment tree and return
	if (ss == se) {
//		tree[si] = arr[ss];
		tree[si] = seg_node_val(arr[ss]);
		return;
	}

	// If there are more than one elements, then recur
	// for left and right subtrees and store the sum
	// of values in this node
	int mid = (ss + se) / 2;
	constructSTUtil(tree, arr, ss, mid, si * 2 + 1);
	constructSTUtil(tree, arr, mid + 1, se, si * 2 + 2);

//	tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]);
//	tree[si] = seg_node_val(tree, si * 2 + 1, si * 2 + 2);
	tree[si] = seg_node_val(tree[si * 2 + 1], tree[si * 2 + 2]);
}

segmenttree_t tree = nullptr;


// Function to construct a segment tree from a given array
// This function allocates memory for segment tree and
// calls constructSTUtil() to fill the allocated memory
// To store segment tree
void constructST(segtrnode_t arr[], int n) {
	if (!tree)tree = new segtrnode_t[SEGTREE_SIZE];
	memCLR(tree, 2 * n - 1, 0);

	constructSTUtil(tree, arr, 0, n - 1, 0);
}

int64_t a[N_MAX + 1];

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
		dtype N, Q;
		scanf("%lld%lld", &N, &Q);
		for (int i = 0; i < N; ++i) {
			scanf("%lld", &a[i]);
		}
		constructST(a, N);
		printf("Case %d:\n", t);
		dtype l, r;
		for (int j = 0; j < Q; ++j) {
			scanf("%lld%lld", &l, &r);
			printf("%lld\n", getRangeVal(tree, N, l - 1, r - 1));
		}
	}
	delete[] tree;
	return 0;
}
