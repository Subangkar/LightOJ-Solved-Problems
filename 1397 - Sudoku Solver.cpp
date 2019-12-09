//
// Created by Subangkar on 26-Nov-19.
//
#include<bits/stdc++.h>

using namespace std;

#define N 3

int a[N][N][N][N];
bool assigned[N][N][N][N];

bool block_okay(int br, int bc, int val) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[br][bc][i][j] == val)
				return false;
		}
	}
	return true;
}

bool line_okay(int br, int bc, int r, int c, int val) {
	int out = br, in = r;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[out][i][in][j] == val) return false;
		}
	}
	out = bc, in = c;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[i][out][j][in] == val) return false;
		}
	}
	return true;
}

bool is_okay(int br, int bc, int r, int c, int val) {
	return block_okay(br, bc, val) && line_okay(br, bc, r, c, val);
}

bool find_best_row_colm(int &br_s, int &bc_s, int &r_s, int &c_s) {
	int best = INT32_MAX;
	for (int br = 0; br < N; ++br) {
		for (int bc = 0; bc < N; ++bc) {
			for (int r = 0; r < N; ++r) {
				for (int c = 0; c < N; ++c) {
					if (!a[br][bc][r][c]) {
						int cur = 0;
						for (int k = 1; k <= 9; ++k)
							if (is_okay(br, bc, r, c, k))
								cur++;

						if (cur < best) {
							br_s = br;
							bc_s = bc;
							r_s = r;
							c_s = c;
							best = cur;
						}
					}
				}

			}
		}
	}
	return best < 10;
}


bool backtrack(int n_unassigned) {
//	uint32_t br = (pos / (N * N * N)) % N,
//			bc = (pos / (N * N)) % N,
//			r = (pos / N) % N,
//			c = (pos) % N;
//	if (!n_unassigned) return true;
//	if (pos == N * N * N * N) return true;
//	if (assigned[br][bc][r][c]) return backtrack(pos + 1, n_unassigned);
	int br, bc, r, c;
	if (!find_best_row_colm(br, bc, r, c)) return true;
	for (int v = 1; v <= 9; ++v) {
		if (is_okay(br, bc, r, c, v)) {
			a[br][bc][r][c] = v;
			if (backtrack(n_unassigned - 1)) return true;
			else a[br][bc][r][c] = 0;
		}
	}
	return false;
}

int main() {
#ifdef OJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, tc;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int size = N * N * N * N;
		int n_unassigned = size;
		for (int br = 0; br < N; ++br) {
			for (int r = 0; r < N; ++r) {
				for (int bc = 0; bc < N; ++bc) {
					for (int c = 0; c < N; ++c) {
						char in;
						cin >> in;
						if (in == '.') {
							a[br][bc][r][c] = 0;
							assigned[br][bc][r][c] = false;
						} else if (in == '\n') {
							cout << "Problem" << endl;
						} else {
							a[br][bc][r][c] = in - '0';
							assigned[br][bc][r][c] = true;
							--n_unassigned;
						}
					}
				}
			}

		}
		backtrack(n_unassigned);
		cout << "Case " << t << ":" << endl;
		for (int br = 0; br < N; ++br) {
			for (int r = 0; r < N; ++r) {
				for (int bc = 0; bc < N; ++bc) {
					for (int c = 0; c < N; ++c) {
						cout << a[br][bc][r][c];
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}


