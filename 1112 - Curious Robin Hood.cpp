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

inline segtrnode_t seg_lazy_val_reset(segtrnode_t &lazy_node) {
	return lazy_node = 0;
}

inline segtrnode_t seg_lazy_val_update(segtrnode_t &lazy_node, segtrnode_t pending_val) {
	return lazy_node += pending_val;
}

inline segtrnode_t seg_tree_val_update(segtrnode_t &tree_node, segtrnode_t pending_val) {
	return tree_node += pending_val;
}

inline segtrnode_t seg_node_val(segmenttree_t tree, int left, int right = -1) {
	if (right == -1) return tree[left];
	return tree[left] + tree[right];
}

inline segtrnode_t seg_node_val(segtrnode_t left_child_val) {
	return left_child_val;
}

inline segtrnode_t seg_node_val(segtrnode_t left_child_val, segtrnode_t right_child_val) {
	return left_child_val + right_child_val;
}

inline segtrnode_t seg_tree_out_of_range_val() {
	return 0;
}

#define SEG_TREE_OUT_OF_RANGE_VAL 0
#define SEG_TREE_NULL_PENDING 0

// si -> index of current node in segment tree
// ss and se -> Starting and ending indexes of
// elements for which current nodes stores sum
// us and ue -> starting and ending indexes of update query
// diff -> which we need to add in the range us to ue
segtrnode_t updateRangeUtil(segmenttree_t tree, segmenttree_t lazy, int si, int ss, int se, int us,
                            int ue, int diff) {
	// If lazy value is non-zero for current node of segment
	// tree, then there are some pending updates. So we need
	// to make sure that the pending updates are done before
	// making new updates. Because this value may be used by
	// parent after recursive calls (See last line of this
	// function)
	if (lazy[si] != SEG_TREE_NULL_PENDING) {
		// Make pending updates using value stored in lazy
		// nodes
//		tree[si] += lazy[si];///////////////////////
		seg_tree_val_update(tree[si], lazy[si]);

		// Checking if it is not leaf node because if
		// it is leaf node then we cannot go further
		if (ss != se) {
			// We can postpone updating children we don't
			// need their new values now.
			// Since we are not yet updating children of si,
			// we need to set lazy flags for the children
//			lazy[si * 2 + 1] += lazy[si];
//			lazy[si * 2 + 2] += lazy[si];
			seg_lazy_val_update(lazy[si * 2 + 1], lazy[si]);
			seg_lazy_val_update(lazy[si * 2 + 2], lazy[si]);
		}

		// Set the lazy value for current node as 0 as it
		// has been updated
//		lazy[si] = 0;
		seg_lazy_val_reset(lazy[si]);
	}

	// Out of range
	if (ss > se || ss > ue || se < us)
		return SEG_TREE_OUT_OF_RANGE_VAL;

	// Current segment is fully in range
	if (ss >= us && se <= ue) {
		// Add the difference to current node
//		tree[si] += diff;
		seg_tree_val_update(tree[si], diff);

		// Same logic for checking leaf node or not
		if (ss != se) {
			// This is where we store values in lazy nodes,
			// rather than updating the segment tree itelf
			// Since we don't need these updated values now
			// we postpone updates by storing values in lazy[]
//			lazy[si * 2 + 1] += diff;
//			lazy[si * 2 + 2] += diff;
			seg_lazy_val_update(lazy[si * 2 + 1], diff);
			seg_lazy_val_update(lazy[si * 2 + 2], diff);
		}
		return tree[si];
	}

	// If not completely in range, but overlaps
	// recur for children
	int mid = (ss + se) / 2;
	updateRangeUtil(tree, lazy, si * 2 + 1, ss, mid, us, ue, diff);
	updateRangeUtil(tree, lazy, si * 2 + 2, mid + 1, se, us, ue, diff);

	// And use the result of children calls
	// to update this node
//	tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]);
//	tree[si] = seg_node_val(tree, si * 2 + 1, si * 2 + 2);
	tree[si] = seg_node_val(tree[si * 2 + 1], tree[si * 2 + 2]);
	return tree[si];
}

// Function to update a range of values in segment
// tree
// us and eu -> starting and ending indexes of update query
// ue -> ending index of update query
// diff -> which we need to add in the range us to ue
segtrnode_t updateRange(segmenttree_t tree, segmenttree_t lazy, int n, int us, int ue, int diff) {
	return updateRangeUtil(tree, lazy, 0, 0, n - 1, us, ue, diff);
}

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
segtrnode_t getRangeValUtil(segmenttree_t tree, segmenttree_t lazy, int ss, int se, int qs, int qe, int si) {

	// If lazy flag is set for current node of segment tree
	// then there are some pending updates. So we need to
	// make sure that the pending updates are done before
	// processing the sub sum query
	if (lazy[si] != SEG_TREE_NULL_PENDING) {

		// Make pending updates to this node. Note that this
		// node represents sum of elements in arr[ss..se] and
		// all these elements must be increased by lazy[si]
//		tree[si] += lazy[si];
		seg_tree_val_update(tree[si], lazy[si]);

		// Checking if it is not leaf node because if
		// it is leaf node then we cannot go further
		if (ss != se) {
			// Since we are not yet updating children os si,
			// we need to set lazy values for the children
//			lazy[si * 2 + 1] += lazy[si];
//			lazy[si * 2 + 2] += lazy[si];
			seg_lazy_val_update(lazy[si * 2 + 1], lazy[si]);
			seg_lazy_val_update(lazy[si * 2 + 2], lazy[si]);
		}

		// Unset the lazy value for current node as it has
		// been updated
//		lazy[si] = 0;
		seg_lazy_val_reset(lazy[si]);
	}

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
	return seg_node_val(getRangeValUtil(tree, lazy, ss, mid, qs, qe, 2 * si + 1),
	                    getRangeValUtil(tree, lazy, mid + 1, se, qs, qe, 2 * si + 2));
}

// Return sum of elements in range from index qs (query
// start) to qe (query end). It mainly uses getRangeValUtil()
segtrnode_t getRangeVal(segmenttree_t tree, segmenttree_t lazy, int n, int qs, int qe) {
	// Check for erroneous input values
	if (qs < 0 || qe > n - 1 || qs > qe) {
		printf("Invalid Input");
		return -1;
	}

	return getRangeValUtil(tree, lazy, 0, n - 1, qs, qe, 0);
}


// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st.
void constructSTUtil(segmenttree_t tree, segmenttree_t lazy, segtrnode_t arr[], int ss, int se, int si) {
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
	constructSTUtil(tree, lazy, arr, ss, mid, si * 2 + 1);
	constructSTUtil(tree, lazy, arr, mid + 1, se, si * 2 + 2);

//	tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]);
//	tree[si] = seg_node_val(tree, si * 2 + 1, si * 2 + 2);
	tree[si] = seg_node_val(tree[si * 2 + 1], tree[si * 2 + 2]);
}

segtrnode_t tree[SEGTREE_SIZE] = {0};

// To store pending updates
segtrnode_t lazy[SEGTREE_SIZE] = {0};

// Function to construct a segment tree from a given array
// This function allocates memory for segment tree and
// calls constructSTUtil() to fill the allocated memory
// To store segment tree
void constructST(segtrnode_t arr[], int n) {
	memCLR(tree, 2 * n - 1, 0);
	memCLR(lazy, 2 * n - 1, 0);

	constructSTUtil(tree, lazy, arr, 0, n - 1, 0);
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
		dtype l, r, v;
		int chc = 0;
		for (int j = 0; j < Q; ++j) {
			scanf("%d", &chc);
			if (chc == 1) {
				scanf("%lld", &l);
				r = l;
				v = getRangeVal(tree, lazy, N, l, r);
				updateRange(tree, lazy, N, l, r, -v);
				printf("%lld\n", v);
			}
			else if (chc == 2) {
				scanf("%lld%lld", &l, &v);
				r = l;
				updateRange(tree, lazy, N, l, r, v);
			}
			else if (chc == 3) {
				scanf("%lld%lld", &l, &r);
				v = getRangeVal(tree, lazy, N, l, r);
				printf("%lld\n", v);
			}
		}
	}
	return 0;
}
