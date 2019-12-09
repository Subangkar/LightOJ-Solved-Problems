//
// Created by Subangkar on 25-Nov-19.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int t, tc, x;

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		int c[n + 1][n + 1];
		vector<int> g[n + 1];
		bool vis[n + 1];
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				c[i][j] = 0;
			}
			vis[i] = false;
		}
		for (int k = 0; k < n; ++k) {
			int u, v, w;
			cin >> u >> v >> w;
			c[u][v] = w;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int f_cost = 0, b_cost = 0;
		int n_vis = 0;
		int u = 1, v;
		while (n_vis < n) {
			do {
				v = g[u].back();
				g[u].pop_back();
				if (v == 1 && n_vis == n - 1) break;
			} while (vis[v] && !g[u].empty());
			f_cost += c[u][v];
			b_cost += c[v][u];
//			cout << u << " " << v << endl;
			vis[u] = true;
			n_vis++;
			u = v;
		}
		cout << "Case " << t << ": " << min(f_cost, b_cost) << endl;
	}
	return 0;
}

